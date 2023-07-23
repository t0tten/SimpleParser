#include "IfRegexMatcher.h"

IfRegexMatcher::IfRegexMatcher() {
    this->text = "[:\\{\\}\\!\\.a-zA-Z0-9 _-]";
    this->prefix = "[\\{\"]?" + this->text + "+[\\}\"]?[ ]*";
    this->regexOperators = "[><=!][=]?";
    this->suffix = "[ ]*[\\{\"]?" + this->text + "+[\\}\"]?";
}

IfRegexMatcher::~IfRegexMatcher() {}

std::vector<std::string> IfRegexMatcher::split(const std::string& statement, std::string op) {
    char delimiter = ';';
    std::regex outer_reg("[ ]*" + op + "[ ]*");
    std::string values = std::regex_replace(statement, outer_reg, std::string(1, delimiter));

    std::vector<std::string> lines;
    std::string line;

    std::istringstream ss(values);
    while (std::getline(ss, line, delimiter)) {
        lines.push_back(line);
    }

    return lines;
}

std::string IfRegexMatcher::grabOperator(std::string statement) {
    std::string retVal = statement;
    UiType::TYPE type = UiType::NOOP;
    VariableRegexMatcher variableRegexMatcher;
    while (type != UiType::MISSING) {
        type = variableRegexMatcher.matchInString(retVal, false);
        if (type != UiType::MISSING) {
            std::string regex = variableRegexMatcher.getRegexForType(type);
            std::regex replace_reg(regex);
            retVal = std::regex_replace(retVal, replace_reg, "");
        }
    }
    std::regex replace_reg(" ");
    retVal = std::regex_replace(retVal, replace_reg, "");
    return retVal;
}

bool IfRegexMatcher::validateString(std::string statement) {
    std::regex stat_reg(this->prefix + this->regexOperators + this->suffix);
    return std::regex_match(statement, stat_reg);
}