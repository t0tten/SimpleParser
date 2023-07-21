#include "ArithmeticException.h"

ArithmeticException::ArithmeticException(std::string statement, std::string regex) {
    this->statement = statement;
    this->regex = regex;
}

std::string ArithmeticException::getMessage() {
    std::string message = "ERROR: the following statement is incorrect: ";
    return message + this->statement + "\n\tREGEX: " + this->regex;
}