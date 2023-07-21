#include "ForUiComponent.h"

/* PRIVATE */
ForUiComponent::ForUiComponent(UiType::TYPE type, std::string firstComparison, std::string secondComparison): ArithmeticUiComponent(type) {
    this->firstComparison = firstComparison;
    this->secondComparison = secondComparison;
}

std::string ForUiComponent::toStringAppendix() {
    std::string retVal = "\tFIRST COMPARISON: " + this->firstComparison + "\n";
    retVal += "\tSECOND COMPARISON: " + this->secondComparison + "\n";
    retVal += "\tCODE BLOCK:\n ";
    for (int i = 0; i < this->codeBlock.size(); i++) {
        retVal += "\t" + this->codeBlock[i]->toString();
    }
    return retVal;
}

/* PUBLIC */
ForUiComponent::~ForUiComponent() {}

/* STATIC */
ForUiComponent* ForUiComponent::parseValues(std::string statement) {
    ForRegexMatcher regexMatcher;
    if (regexMatcher.validateString(statement)) {
        std::vector<std::string> comparers = regexMatcher.split(statement);
        return new ForUiComponent(UiType::FOR, comparers.at(0), comparers.at(1));
    } else {
        throw ArithmeticException(statement, regexMatcher.getRegex());
    }
    return NULL;
}