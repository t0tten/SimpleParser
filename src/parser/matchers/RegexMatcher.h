#ifndef _REGEX_MATCHER_H_
#define _REGEX_MATCHER_H_

#include "../types/UiRegex.h"
#include "../types/UiType.h"
#include <string>
#include <vector>
#include <regex>
#include <iostream>

class RegexMatcher {
    private:
        /* VARIABLES */
        std::vector<UiRegex*> regexTypes;

        /* FUNCTIONS */
        UiType::TYPE matchLine(std::vector<UiRegex*> regexVector, std::string line);
        std::string extractValuesFromLine(std::vector<UiRegex*> array, UiType::TYPE type, std::string line);
        
    public:
        RegexMatcher();
        ~RegexMatcher();

        UiType::TYPE match(std::string line);
        std::string getValues(UiType::TYPE type, std::string line);
};

#endif // _REGEX_MATCHER_H_