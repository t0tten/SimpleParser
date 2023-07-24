#include "ForUiComponent.h"

/* PRIVATE */
ForUiComponent::ForUiComponent(UiType::TYPE type, int start, int end): ArithmeticUiComponent(type) {
    this->start = start;
    this->end = end;
}

std::string ForUiComponent::toStringAppendix(std::string tabs) {
    std::string retVal = tabs + "FIRST COMPARISON: " + std::to_string(this->start) + "\n";
    retVal += tabs + "SECOND COMPARISON: " + std::to_string(this->end) + "\n";
    retVal += tabs + "CODE BLOCK:\n ";
    
    tabs += "\t";
    for (int i = 0; i < this->codeBlock.size(); i++) {
        retVal += "\t" + this->codeBlock[i]->toString(tabs);
    }
    return retVal;
}

/* PUBLIC */
ForUiComponent::~ForUiComponent() {}

void ForUiComponent::execute(UiComponent* component) {
    if ((this->end - this->start) >= 0) {
        for (int i = this->start; i < this->end; i++) {
            this->index = i;
            this->executeCodeBlock(this);
        }
    } else {
        for (int i = this->start; i > this->end; i--) {
            this->index = i;
            this->executeCodeBlock(this);
        }
    }
}

int ForUiComponent::getIndex() {
    return this->index;
}

/* STATIC */
ForUiComponent* ForUiComponent::parseValues(std::string statement) {
    ForRegexMatcher regexMatcher;
    if (regexMatcher.validateString(statement)) {
        std::vector<std::string> comparers = regexMatcher.split(statement);
        int start = std::stoi(comparers.at(0));
        int end = std::stoi(comparers.at(1));
        return new ForUiComponent(UiType::FOR, start, end);
    } else {
        throw ArithmeticException(statement);
    }
    return NULL;
}