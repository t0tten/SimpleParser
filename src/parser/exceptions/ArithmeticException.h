#ifndef _ARITHMETIC_EXCEPTION_H_
#define _ARITHMETIC_EXCEPTION_H_

#include "Exception.h"
#include <string>

class ArithmeticException: public Exception {
    private:
        std::string statement;
        std::string regex;

    public:
        ArithmeticException(std::string statement);
        std::string getMessage();
};

#endif // _ARITHMETIC_EXCEPTION_H_