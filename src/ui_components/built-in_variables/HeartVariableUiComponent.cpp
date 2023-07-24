#include "HeartVariableUiComponent.h"

/* PRIVATE */
std::string HeartVariableUiComponent::toStringAppendix(std::string tabs) {
    return tabs + this->value;
}

/* PROTECTED */
HeartVariableUiComponent::HeartVariableUiComponent(UiType::TYPE type, std::string value): VariableUiComponent(type) {
    this->value = value;
}

/* PUBLIC */
HeartVariableUiComponent::~HeartVariableUiComponent() {}

std::string HeartVariableUiComponent::getValue(UiComponent* component) {
    std::string heartBeat = "72";
    return heartBeat;
}

/* STATIC */
VariableUiComponent* HeartVariableUiComponent::create(UiType::TYPE type, std::string value) {
    return new HeartVariableUiComponent(type, value);
}