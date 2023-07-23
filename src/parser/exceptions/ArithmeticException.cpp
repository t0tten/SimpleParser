#include "ArithmeticException.h"

ArithmeticException::ArithmeticException(std::string statement) {
    this->statement = statement;
}

std::string ArithmeticException::getMessage() {
    std::string message = "ERROR: the following statement is incorrect: ";
    return message + this->statement;
}