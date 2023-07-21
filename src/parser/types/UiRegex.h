#ifndef _UI_REGEX_H_
#define _UI_REGEX_H_

#include "UiType.h"
#include <string>

class UiRegex {
    private:
        UiType::TYPE type;
        std::string prefixRegex, infixRegex, suffixRegex;

    public:
        UiRegex(UiType::TYPE type, std::string prefixRegex, std::string infixRegex,  std::string suffixRegex);
        ~UiRegex();

        UiType::TYPE getType();
        std::string getPrefixRegex();
        std::string getInfixRegex();
        std::string getSuffixRegex();
        std::string getCompleteRegex();
};

#endif // _UI_REGEX_H_