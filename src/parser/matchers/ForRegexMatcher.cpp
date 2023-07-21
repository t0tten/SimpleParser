#include "ForRegexMatcher.h"

ForRegexMatcher::ForRegexMatcher() {
    this->number = "[0-9]+";
    this->divider = "[ ]*to[ ]*";
}

ForRegexMatcher::~ForRegexMatcher() {}

std::vector<std::string> ForRegexMatcher::split(const std::string& statement) {
    char delimiter = ';';
    std::regex outer_reg(this->divider);
    std::string values = std::regex_replace(statement, outer_reg, std::string(1, delimiter));

    std::vector<std::string> lines;
    std::string line;

    std::istringstream ss(values);
    while (std::getline(ss, line, delimiter)) {
        lines.push_back(line);
    }

    return lines;
}

bool ForRegexMatcher::validateString(std::string statement) {
    std::regex stat_reg(this->number + this->divider + this->number);
    return std::regex_match(statement, stat_reg);
}

std::string ForRegexMatcher::getRegex() {
    return this->number + this->divider + this->number;
}