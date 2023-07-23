#ifndef _VARIABLE_REGEX_MATCHER_H_
#define _VARIABLE_REGEX_MATCHER_H_

#include "../types/UiRegex.h"
#include "../types/UiType.h"
#include <string>
#include <vector>
#include <regex>
#include <iostream>

class VariableRegexMatcher {
    private:
        /* VARIABLES */
        std::vector<UiRegex*> regexTypes;
        
    public:
        VariableRegexMatcher();
        ~VariableRegexMatcher();

        UiType::TYPE match(std::string line);
        UiType::TYPE matchInString(std::string line, bool useSkips = true);
        std::string getRegexForType(UiType::TYPE type);
};

#endif // _VARIABLE_REGEX_MATCHER_H_