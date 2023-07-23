#ifndef _IF_REGEX_MACTHER_H_
#define _IF_REGEX_MACTHER_H_

#include "../types/UiType.h"
#include "VariableRegexMatcher.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
#include <string>
#include <iostream>

class IfRegexMatcher {
    private:
        std::string prefix, regexOperators, suffix;
        std::string text;

    public:
        IfRegexMatcher();
        ~IfRegexMatcher();

        bool validateString(std::string statement);
        std::string grabOperator(std::string statement);
        std::vector<std::string> split(const std::string& statement, std::string op);
};

#endif // _IF_REGEX_MACTHER_H_