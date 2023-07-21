#include "UiRegex.h"

UiRegex::UiRegex (UiType::TYPE type, std::string prefixRegex, std::string infixRegex,  std::string suffixRegex) {
    this->type = type;
    this->prefixRegex = prefixRegex;
    this->infixRegex = infixRegex;
    this->suffixRegex = suffixRegex;
}

UiRegex::~UiRegex() { }

UiType::TYPE UiRegex::getType() {
    return this->type;
}

std::string UiRegex::getPrefixRegex() {
    return this->prefixRegex;
}

std::string UiRegex::getInfixRegex() {
    return this->infixRegex;
}

std::string UiRegex::getSuffixRegex() {
    return this->suffixRegex;
}

std::string UiRegex::getCompleteRegex() {
    return this->prefixRegex + this->infixRegex + this->suffixRegex;
}