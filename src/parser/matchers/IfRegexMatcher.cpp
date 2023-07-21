#include "IfRegexMatcher.h"

IfRegexMatcher::IfRegexMatcher() {
    this->text = "[:\\!\\.a-zA-Z0-9 _-]";
    this->prefix = "[\\{\"]?" + this->text + "+[\\}\"]?[ ]*";
    this->regexOperators = "[><=!][=]?";
    this->suffix = "[ ]*[\\{\"]?" + this->text + "+[\\}\"]?";
    
    comparisonRegex.push_back("\\{CLOCK\\}");
    comparisonRegex.push_back("\"" + this->text + "*\"");
    comparisonRegex.push_back("true");
    comparisonRegex.push_back("false");
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

std::string IfRegexMatcher::findOperator(std::string statement) {
    std::regex outer_reg(this->prefix + "|" + this->suffix);
    return std::regex_replace(statement, outer_reg, "");
}

bool IfRegexMatcher::validateString(std::string statement) {
    std::regex stat_reg(this->prefix + this->regexOperators + this->suffix);
    return std::regex_match(statement, stat_reg);
}

bool IfRegexMatcher::validateComparison(std::string comparison) {
    std::string regex = "";
    for (int i = 0; i < this->comparisonRegex.size(); i++) {
        regex += this->comparisonRegex[i];
        if(i != (this->comparisonRegex.size() - 1)) {
            regex += "|";
        }
    }
    std::regex stat_reg(regex);
    return std::regex_match(comparison, stat_reg);
}

std::string IfRegexMatcher::getRegex() {
    return this->prefix + this->regexOperators + this->suffix;
}

std::string IfRegexMatcher::getComparisonRegex() {
    std::string regex = "";
    for (int i = 0; i < this->comparisonRegex.size(); i++) {
        regex += this->comparisonRegex[i];
        if(i != (this->comparisonRegex.size() - 1)) {
            regex += "|";
        }
    }
    return regex;
}