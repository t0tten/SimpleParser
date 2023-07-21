#include "IfUiComponent.h"

/* PRIVATE */
IfUiComponent::IfUiComponent(UiType::TYPE type, std::string op, std::string firstComparison, std::string secondComparison): ArithmeticUiComponent(type) {
    this->op = op;
    this->firstComparison = firstComparison;
    this->secondComparison = secondComparison;
}

std::string IfUiComponent::toStringAppendix() {
    std::string retVal = "\tOPERATION: " + this->op + "\n";
    retVal += "\tFIRST COMPARISON: " + this->firstComparison + "\n";
    retVal += "\tSECOND COMPARISON: " + this->secondComparison + "\n";
    retVal += "\tCODE BLOCK:\n ";
    for (int i = 0; i < this->codeBlock.size(); i++) {
        retVal += "\t" + this->codeBlock[i]->toString();
    }

    for (int i = 0; i < this->ifComponents.size(); i++) {
        retVal += "\t" + this->ifComponents[i]->toString();
    }
    return retVal;
}

/* PUBLIC */
IfUiComponent::~IfUiComponent() {}

void IfUiComponent::addIfComponent(IfUiComponent* ifComponent) {
    this->ifComponents.push_back(ifComponent);
}

/* STATIC */
IfUiComponent* IfUiComponent::parseValues(std::string statement) {
    IfRegexMatcher regexMatcher;
    if (regexMatcher.validateString(statement)) {
        std::string op = regexMatcher.findOperator(statement);
        std::vector<std::string> comparers = regexMatcher.split(statement, op);
        if (regexMatcher.validateComparison(comparers.at(0)) && regexMatcher.validateComparison(comparers.at(1))) {
            return new IfUiComponent(UiType::IF, op, comparers.at(0), comparers.at(1));
        } else {
            throw ArithmeticException(statement, regexMatcher.getComparisonRegex());
        }
    } else {
        throw ArithmeticException(statement, regexMatcher.getRegex());
    }
    return NULL;
}

IfUiComponent* IfUiComponent::emptyValues() {
    return new IfUiComponent(UiType::IF, "", "", "");
}