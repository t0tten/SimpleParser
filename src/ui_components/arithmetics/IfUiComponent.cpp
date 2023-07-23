#include "IfUiComponent.h"

/* PRIVATE */
IfUiComponent::IfUiComponent(UiType::TYPE type, std::string op, VariableUiComponent* component1, VariableUiComponent* component2): ArithmeticUiComponent(type) {
    this->op = op;
    this->component1 = component1;
    this->component2 = component2;
}

std::string IfUiComponent::toStringAppendix(std::string tabs) {
    std::string comp1 = (this->component1 != NULL) ? this->component1->getValue() : "";
    std::string comp2 = (this->component1 != NULL) ? this->component1->getValue() : "";
    std::string retVal = tabs + "OPERATION: " + this->op + "\n";
    retVal += tabs + "FIRST COMPARISON: " + comp1 + "\n";
    retVal += tabs + "SECOND COMPARISON: " + comp2 + "\n";
    retVal += tabs + "CODE BLOCK:\n ";
    tabs += "\t";
    for (int i = 0; i < this->codeBlock.size(); i++) {
        retVal += tabs + this->codeBlock[i]->toString(tabs);
    }

    for (int i = 0; i < this->ifComponents.size(); i++) {
        retVal += tabs +  this->ifComponents[i]->toString(tabs);
    }
    return retVal;
}

VariableUiComponent* IfUiComponent::translateToVariable(UiType::TYPE type, std::string value) {
    switch(type) {
        case UiType::STRING:
            return StringVariableUiComponent::create(type, value);
        case UiType::CLOCK:
        case UiType::CLOCK_FULL:
        case UiType::CLOCK_HOUR:
        case UiType::CLOCK_MIN:
        case UiType::CLOCK_SEC:
            return ClockVariableUiComponent::create(type, value);
        case UiType::BOOLEAN_TRUE:
        case UiType::BOOLEAN_FALSE:
            return BooleanVariableUiComponent::create(type, value);
        case UiType::BATT:
            return BatteryVariableUiComponent::create(type, value);
        case UiType::BT:
            return BluetoothVariableUiComponent::create(type, value);
        case UiType::DATE:
        case UiType::DATE_FULL:
        case UiType::DATE_FULL_YEAR:
        case UiType::DATE_YEAR:
        case UiType::DATE_MONTH:
        case UiType::DATE_DAY:
            return DateVariableUiComponent::create(type, value);
        case UiType::HEART:
            return HeartVariableUiComponent::create(type, value);
        case UiType::STEPS:
            return StepsVariableUiComponent::create(type, value);
        default:
            throw ArithmeticException(value);
    }
}

/* PUBLIC */
IfUiComponent::~IfUiComponent() {
    if (this->component1 != NULL) {
        delete this->component1;
    }

    if (this->component2 != NULL) {
        delete this->component2;
    }
}

void IfUiComponent::addIfComponent(IfUiComponent* ifComponent) {
    this->ifComponents.push_back(ifComponent);
}

void IfUiComponent::continueWithNextIfStatement() {
    for (int i = 0; i < this->ifComponents.size(); i++) {
        this->ifComponents[i]->execute();
    }
}

void IfUiComponent::execute() {
    bool isExperssionTrue = false;
    if (this->component1 != NULL && this->component2 != NULL) {
        //std::cout << "Comparing: " << this->component1->getValue() << " " << this->op << " " << this->component2->getValue() << std::endl;
        
        int comparer1 = -1;
        int comparer2 = -1;
        if (this->op != "=" && this->op != "!=") {
            comparer1 = std::stoi(this->component1->getValue());
            comparer2 = std::stoi(this->component2->getValue());
        }
        
        if (this->op == "<") {
            if (comparer1 < comparer2) {
                isExperssionTrue = true;
            }
        } else if (this->op == ">") {
            if (comparer1 > comparer2) {
                isExperssionTrue = true;
            }
        } else if (this->op == "<=") {
            if (comparer1 <= comparer2) {
                isExperssionTrue = true;
            }
        } else if (this->op == ">=") {
            if (comparer1 >= comparer2) {
                isExperssionTrue = true;
            }
        } else if (this->op == "=") {
            if (this->component1->getValue() == this->component2->getValue()) {
                isExperssionTrue = true;
            }
        } else if (this->op == "!=") {
            if (this->component1->getValue() != this->component2->getValue()) {
                isExperssionTrue = true;
            }
        }
    } else {
        isExperssionTrue = true;
    }

    if (isExperssionTrue) {
        this->executeCodeBlock();
    } else {
        this->continueWithNextIfStatement();
    }
}

/* STATIC */
IfUiComponent* IfUiComponent::parseValues(std::string statement) {
    IfRegexMatcher regexMatcher;
    if (regexMatcher.validateString(statement)) {
        std::string op = regexMatcher.grabOperator(statement);
        std::vector<std::string> comparers = regexMatcher.split(statement, op);
        VariableRegexMatcher variableRegexMatcher;
        VariableUiComponent* component1 = IfUiComponent::translateToVariable(variableRegexMatcher.match(comparers.at(0)), comparers.at(0));
        VariableUiComponent* component2 = IfUiComponent::translateToVariable(variableRegexMatcher.match(comparers.at(1)), comparers.at(1));
        return new IfUiComponent(UiType::IF, op, component1, component2);
    } else {
        throw ArithmeticException(statement);
    }
    return NULL;
}

IfUiComponent* IfUiComponent::emptyValues() {
    return new IfUiComponent(UiType::IF, "", NULL, NULL);
}