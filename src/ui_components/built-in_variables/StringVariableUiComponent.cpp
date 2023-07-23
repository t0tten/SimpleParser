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

std::string StringVariableUiComponent::getValue() {
    std::string retVal = this->value;
    UiType::TYPE type = UiType::NOOP;
    VariableRegexMatcher variableRegexMatcher;
    while (type != UiType::MISSING) {
        type = variableRegexMatcher.matchInString(retVal);
        if (type != UiType::MISSING) {
            std::string regex = variableRegexMatcher.getRegexForType(type);
            std::regex replace_reg(regex);
            VariableUiComponent* translatedComponent = IfUiComponent::translateToVariable(type, regex);
            std::string translatedValue = translatedComponent->getValue();
            delete translatedComponent;
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