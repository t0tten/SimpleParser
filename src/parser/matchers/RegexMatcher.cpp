#include "RegexMatcher.h"

/* PRIVATE */
UiRegex* RegexMatcher::findRegexType(UiType::TYPE type) {
    UiRegex* currentRegex = NULL;
    for (int i = 0; i < this->regexTypes.size() && currentRegex == NULL; i++) {
        if (this->regexTypes[i]->getType() == type) {
            currentRegex = this->regexTypes[i];
        }
    }
    return currentRegex;
}

/* PUBLIC */
RegexMatcher::RegexMatcher() {
    /* ARITHMICS */
    this->regexTypes.push_back(new UiRegex(UiType::IF, "[ ]*if[ ]*\\(", "[:\"\\{\\}_()a-zA-Z0-9]*[ ]*[=><!][=]?[ ]*[:\"\\{\\}_()a-zA-Z0-9]*", "\\)[ ]*\\{[ ]*"));
    this->regexTypes.push_back(new UiRegex(UiType::ELSE_IF, "[ ]*\\}[ ]*else if[ ]*\\(", "[:\"\\{\\}_()a-zA-Z0-9]*[ ]*[=><!][=]?[ ]*[:\"\\{\\}_()a-zA-Z0-9]*", "\\)[ ]*\\{[ ]*"));
    this->regexTypes.push_back(new UiRegex(UiType::ELSE, "[ ]*\\}", "[ ]*else[ ]*", "\\{[ ]*"));
    this->regexTypes.push_back(new UiRegex(UiType::ARI_END, "[ ]*", "", "\\}[ ]*"));
    this->regexTypes.push_back(new UiRegex(UiType::FOR, "[ ]*for[ ]*\\(", "[0-9]+[ ]*to[ ]*[0-9]+", "\\)[ ]*\\{[ ]*"));

    /* BUILT-IN FUNCTIONS */
    this->regexTypes.push_back(new UiRegex(UiType::LINE, "[ ]*\\.line[ ]*\\(", "[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*", "\\);[ ]*"));
    this->regexTypes.push_back(new UiRegex(UiType::CIRCLE,"[ ]*\\.circle[ ]*\\(", "[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*", "\\);[ ]*"));
    this->regexTypes.push_back(new UiRegex(UiType::TEXT, "[ ]*\\.text[ ]*\\(", "[ ]*([0-9]+|\\{i\\})[ ]*,[ ]*([0-9]+|\\{i\\})[ ]*,[ ]*([0-9]+|\\{i\\})[ ]*,[ ]*\"[:%\\{\\}a-zA-Z0-9-_,? ]+\"[ ]*\\", ")[ ]*;[ ]*"));
    this->regexTypes.push_back(new UiRegex(UiType::RECTANGLE, "[ ]*\\.rectangle[ ]*\\(", "[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*", "\\);[ ]*"));
    this->regexTypes.push_back(new UiRegex(UiType::COLOR,"[ ]*\\.color[ ]*\\(", "[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*,[ ]*[0-9]+[ ]*", "\\);[ ]*"));
}

RegexMatcher::~RegexMatcher() {
    for (int i = 0; i < this->regexTypes.size(); i++) {
        delete this->regexTypes[i];
    }
}

UiType::TYPE RegexMatcher::match(std::string& filecontent) {
    if (filecontent == "") {
        return UiType::NOOP;
    }

    bool isFound = false;
    UiType::TYPE type;
    int i = 0;
    for (;i < this->regexTypes.size() && !isFound; i++) {
        const std::regex component_reg("^" + this->regexTypes[i]->getCompleteRegex() + ".*");
        if (std::regex_match(filecontent, component_reg)) {
            isFound = true;
            type = this->regexTypes[i]->getType();
            std::string remove_regex = "^" + this->regexTypes[i]->getPrefixRegex();
            const std::regex remove_reg(remove_regex);
            filecontent = std::regex_replace(filecontent, remove_reg, "");
        }
    }

    if (isFound) {
        return type;
    } else {
        return UiType::MISSING;
    }
}

std::string RegexMatcher::getValues(UiType::TYPE type, std::string& filecontent) {
    int i = 0;
    bool inAString = false;
    for (; i < filecontent.size(); i++) {
        if (filecontent[i] == '"' && !inAString) {
            inAString = true;
        } else if (filecontent[i] == '"' && inAString) {
            inAString = false;
        }
        if (filecontent[i] == ')' && !inAString) {
            break;
        }
    }
    std::string retVal = filecontent.substr(0, i);
    UiRegex* regexType = this->findRegexType(type);
    if (regexType != NULL) {
        std::string remove_regex = "^[ ]*" + regexType->getInfixRegex() + regexType->getSuffixRegex();
        const std::regex remove_reg(remove_regex);
        filecontent = std::regex_replace(filecontent, remove_reg, "");
    }
    return retVal;
}