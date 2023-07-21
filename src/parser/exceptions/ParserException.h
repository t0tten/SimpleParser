#ifndef _PARSER_EXCEPTION_H_
#define _PARSER_EXCEPTION_H_

#include "Exception.h"
#include <string>

class ParserException: public Exception {
    private:
        int lineNumber;
        std::string line;

    public:
        ParserException(int lineNumber, std::string line);
        std::string getMessage();
};

#endif // _PARSING_EXCEPTION_H_