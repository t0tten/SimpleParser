#include "VariableRegexMatcher.h"

/* PUBLIC */
VariableRegexMatcher::VariableRegexMatcher() {
    this->regexTypes.push_back(new UiRegex(UiType::STRING, "\"", ".*", "\""));
    this->regexTypes.push_back(new UiRegex(UiType::CLOCK, "\\{", "CLK", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::CLOCK_FULL, "\\{", "CLK_FULL", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::CLOCK_HOUR, "\\{", "CLK_HOUR", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::CLOCK_MIN, "\\{", "CLK_MIN", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::CLOCK_SEC, "\\{", "CLK_SEC", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::BOOLEAN_TRUE, "", "true", ""));
    this->regexTypes.push_back(new UiRegex(UiType::BOOLEAN_FALSE, "", "false", ""));
    this->regexTypes.push_back(new UiRegex(UiType::BATT, "\\{", "BATT", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::BT, "\\{", "BT", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::HEART, "\\{", "HEART", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::DATE, "\\{", "DATE", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::DATE_FULL, "\\{", "DATE_FULL", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::DATE_FULL_YEAR, "\\{", "DATE_FULL_YEAR", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::DATE_YEAR, "\\{", "DATE_YEAR", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::DATE_MONTH, "\\{", "DATE_MONTH", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::DATE_DAY, "\\{", "DATE_DAY", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::STEPS, "\\{", "STEPS", "\\}"));
    this->regexTypes.push_back(new UiRegex(UiType::INDEX, "\\{", "i", "\\}"));
}

VariableRegexMatcher::~VariableRegexMatcher() {
    for (int i = 0; i < this->regexTypes.size(); i++) {
        delete this->regexTypes[i];
    }
}

UiType::TYPE VariableRegexMatcher::match(std::string line) {
    bool isFound = false;
    UiType::TYPE type;
    int i = 0;
    for (;i < this->regexTypes.size() && !isFound; i++) {
        const std::regex component_reg(this->regexTypes[i]->getCompleteRegex());
            
        if (std::regex_match(line, component_reg)) {
            isFound = true;
            type = this->regexTypes[i]->getType();
        }
    }

    if (isFound) {
        return type;
    } else {
        return UiType::MISSING;
    }
}

UiType::TYPE VariableRegexMatcher::matchInString(std::string line, bool useSkips) {
    bool isFound = false;
    UiType::TYPE type;
    int i = 0;
    for (;i < this->regexTypes.size() && !isFound; i++) {
        const std::regex component_reg(".*" + this->regexTypes[i]->getCompleteRegex() + ".*");
        type = this->regexTypes[i]->getType();
        if(useSkips) {
            if (type == UiType::STRING || type == UiType::BOOLEAN_TRUE || type == UiType::BOOLEAN_FALSE) {
                continue;
            }
        }
        if (std::regex_match(line, component_reg)) {
            isFound = true;
        }
    }

    if (isFound) {
        return type;
    } else {
        return UiType::MISSING;
    }
}

std::string VariableRegexMatcher::getRegexForType(UiType::TYPE type) {
    for (int i = 0; i < this->regexTypes.size(); i++) {
        if (this->regexTypes[i]->getType() == type) {
            return this->regexTypes[i]->getCompleteRegex();
        }
    }
    return "";
}