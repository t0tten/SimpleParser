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
        UiRegex* findRegexType(UiType::TYPE type);
        
    public:
        RegexMatcher();
        ~RegexMatcher();

        UiType::TYPE match(std::string& filecontent);
        std::string getValues(UiType::TYPE type, std::string& filecontent);
};

#endif // _REGEX_MATCHER_H_