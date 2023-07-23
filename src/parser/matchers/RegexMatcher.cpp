#include "RegexMatcher.h"

/* PRIVATE */
UiType::TYPE RegexMatcher::matchLine(std::vector<UiRegex*> regexVector, std::string line) {
    bool isFound = false;
    UiType::TYPE type;
    int i = 0;
    for (;i < regexVector.size() && !isFound; i++) {
        const std::regex component_reg(regexVector[i]->getCompleteRegex());
        if (std::regex_match(line, component_reg)) {
            isFound = true;
            type = regexVector[i]->getType();
        }
    }

    if (isFound) {
        return type;
    } else {
        return UiType::MISSING;
    }
}

std::string RegexMatcher::extractValuesFromLine(std::vector<UiRegex*> array, UiType::TYPE type, std::string line) {
    UiRegex* currentRegex = NULL;
    for (int i = 0; i < array.size() && currentRegex == NULL; i++) {
        if (array[i]->getType() == type) {
            currentRegex = array[i];
        }
    }
    std::regex outer_reg(currentRegex->getPrefixRegex() + "|" + currentRegex->getSuffixRegex());
    std::regex infix_reg(currentRegex->getInfixRegex());
    std::regex quotation_marks("\"");
    std::string values = std::regex_replace(line, outer_reg, "");

    /* Make sure everything is fine */
    if (std::regex_match(values, infix_reg)) {
        return values;
    }
    return "";
}

/* PUBLIC */
RegexMatcher::RegexMatcher() {
    /* COMMENTS */
    this->regexTypes.push_back(new UiRegex(UiType::NOOP, "[ ]*//", ".*", "$"));

    /* ARITHMICS */
    this->regexTypes.push_back(new UiRegex(UiType::IF, "[ ]*if[ ]*\\(", ".*", "\\)[ ]*\\{[ ]*$"));
    this->regexTypes.push_back(new UiRegex(UiType::ELSE_IF, "[ ]*\\}[ ]*else if[ ]*\\(", ".*", "\\)[ ]*\\{[ ]*$"));
    this->regexTypes.push_back(new UiRegex(UiType::ELSE, "[ ]*\\}", "[ ]*else[ ]*", "\\{[ ]*$"));
    this->regexTypes.push_back(new UiRegex(UiType::FOR, "[ ]*for[ ]*\\(", ".*", "\\)[ ]*\\{[ ]*$"));
    this->regexTypes.push_back(new UiRegex(UiType::ARI_END, "[ ]*", "", "\\}[ ]*$"));

    /* BUILT-IN FUNCTIONS */
    this->regexTypes.push_back(new UiRegex(UiType::LINE, "[ ]*\\.line[ ]*\\(", "[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*", "\\);[ ]*$"));
    this->regexTypes.push_back(new UiRegex(UiType::CIRCLE,"[ ]*\\.circle[ ]*\\(", "[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*", "\\);[ ]*$"));
    this->regexTypes.push_back(new UiRegex(UiType::TEXT, "[ ]*\\.text[ ]*\\(", "[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*,[ ]*\"[a-zA-Z0-9 \\{\\},\\.\\-:_!#%&?]*\"[ ]*", "\\);[ ]*$"));
    this->regexTypes.push_back(new UiRegex(UiType::RECTANGLE, "[ ]*\\.rectangle[ ]*\\(", "[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*", "\\);[ ]*$"));
    this->regexTypes.push_back(new UiRegex(UiType::COLOR,"[ ]*\\.color[ ]*\\(", "[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*", "\\);[ ]*$"));
}

RegexMatcher::~RegexMatcher() {
    for (int i = 0; i < this->regexTypes.size(); i++) {
        delete this->regexTypes[i];
    }
}

UiType::TYPE RegexMatcher::match(std::string line) {
    if (line == "") {
        return UiType::NOOP;
    }
    return this->matchLine(this->regexTypes, line);
}

std::string RegexMatcher::getValues(UiType::TYPE type, std::string line) {
    return this->extractValuesFromLine(this->regexTypes, type, line);
}