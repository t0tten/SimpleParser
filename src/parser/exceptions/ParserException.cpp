#include "ParserException.h"

ParserException::ParserException(int lineNumber, std::string line) {
    this->lineNumber = lineNumber;
    this->line = line;
}

std::string ParserException::getMessage() {
    std::string message = "ERROR: Syntax error on line ";
    return message + std::to_string(this->lineNumber) + ": " + this->line;
}