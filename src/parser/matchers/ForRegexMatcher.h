#ifndef _FOR_REGEX_MACTHER_H_
#define _FOR_REGEX_MACTHER_H_

#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
#include <string>
#include <iostream>

class ForRegexMatcher {
    private:
        std::string number, divider;

    public:
        ForRegexMatcher();
        ~ForRegexMatcher();

        bool validateString(std::string statement);
        std::string getRegex();
        std::vector<std::string> split(const std::string& statement);
};

#endif // _FOR_REGEX_MACTHER_H_