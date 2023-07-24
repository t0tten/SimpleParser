#include "StringVariableUiComponent.h"

/* PRIVATE */
std::string StringVariableUiComponent::toStringAppendix(std::string tabs) {
    return tabs + this->value;
}

/* PROTECTED */
StringVariableUiComponent::StringVariableUiComponent(UiType::TYPE type, std::string value): VariableUiComponent(type) {
    this->value = value;
}

/* PUBLIC */
StringVariableUiComponent::~StringVariableUiComponent() {}

std::string StringVariableUiComponent::getValue(UiComponent* component) {
    bool comingFromFor = false;
    ForUiComponent* forUiComponent = dynamic_cast<ForUiComponent*>(component);
    if (forUiComponent != nullptr) {
        comingFromFor = true;
    }

    std::string retVal = this->value;
    UiType::TYPE type = UiType::NOOP;
    VariableRegexMatcher variableRegexMatcher;
    while (type != UiType::MISSING) {
        type = variableRegexMatcher.matchInString(retVal);
        if (type != UiType::MISSING || (comingFromFor && type == UiType::INDEX)) {
            std::string regex = variableRegexMatcher.getRegexForType(type);
            std::regex replace_reg(regex);
            std::string translatedValue = "";
            if (!comingFromFor) {
                VariableUiComponent* translatedComponent = IfUiComponent::translateToVariable(type, regex);
                translatedValue = translatedComponent->getValue(component);
                delete translatedComponent;
            } else {
                translatedValue = std::to_string(forUiComponent->getIndex());
            }
            retVal = std::regex_replace(retVal, replace_reg, translatedValue);
        }
    }
    
    return retVal;
}

/* STATIC */
VariableUiComponent* StringVariableUiComponent::create(UiType::TYPE type, std::string value) {
    std::regex replace_reg("[ ]*\"[ ]*");
    value = std::regex_replace(value, replace_reg, "");
    return new StringVariableUiComponent(type, value);
}