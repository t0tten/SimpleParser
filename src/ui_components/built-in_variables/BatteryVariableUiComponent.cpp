#include "BatteryVariableUiComponent.h"

/* PRIVATE */
std::string BatteryVariableUiComponent::toStringAppendix(std::string tabs) {
    return tabs + this->value;
}

/* PROTECTED */
BatteryVariableUiComponent::BatteryVariableUiComponent(UiType::TYPE type, std::string value): VariableUiComponent(type) {
    this->value = value;
}

/* PUBLIC */
BatteryVariableUiComponent::~BatteryVariableUiComponent() {}

std::string BatteryVariableUiComponent::getValue() {
    std::string batteryPercentage = "96";
    return batteryPercentage;
}

/* STATIC */
VariableUiComponent* BatteryVariableUiComponent::create(UiType::TYPE type, std::string value) {
    return new BatteryVariableUiComponent(type, value);
}