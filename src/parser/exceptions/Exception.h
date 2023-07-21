#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <string>

class Exception {
    public:
        virtual std::string getMessage() {
            return "";
        };
};

#endif // _EXCEPTION_H_