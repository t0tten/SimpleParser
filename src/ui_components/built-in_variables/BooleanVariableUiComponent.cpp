#include "BooleanVariableUiComponent.h"

/* PRIVATE */
std::string BooleanVariableUiComponent::toStringAppendix(std::string tabs) {
    return tabs + this->value;
}

/* PROTECTED */
BooleanVariableUiComponent::BooleanVariableUiComponent(UiType::TYPE type, std::string value): VariableUiComponent(type) {
    this->value = value;
}

/* PUBLIC */
BooleanVariableUiComponent::~BooleanVariableUiComponent() {}

std::string BooleanVariableUiComponent::getValue() {
    return this->value;
}

/* STATIC */
VariableUiComponent* BooleanVariableUiComponent::create(UiType::TYPE type, std::string value) {
    return new BooleanVariableUiComponent(type, value);
}