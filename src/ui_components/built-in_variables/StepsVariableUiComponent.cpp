#include "StepsVariableUiComponent.h"

/* PRIVATE */
std::string StepsVariableUiComponent::toStringAppendix(std::string tabs) {
    return tabs + this->value;
}

/* PROTECTED */
StepsVariableUiComponent::StepsVariableUiComponent(UiType::TYPE type, std::string value): VariableUiComponent(type) {
    this->value = value;
}

/* PUBLIC */
StepsVariableUiComponent::~StepsVariableUiComponent() {}

std::string StepsVariableUiComponent::getValue() {
    std::string steps = "2758";
    return steps;
}

/* STATIC */
VariableUiComponent* StepsVariableUiComponent::create(UiType::TYPE type, std::string value) {
    return new StepsVariableUiComponent(type, value);
}