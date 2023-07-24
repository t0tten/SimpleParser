#include "BluetoothVariableUiComponent.h"

/* PRIVATE */
std::string BluetoothVariableUiComponent::toStringAppendix(std::string tabs) {
    return tabs + this->value;
}

/* PROTECTED */
BluetoothVariableUiComponent::BluetoothVariableUiComponent(UiType::TYPE type, std::string value): VariableUiComponent(type) {
    this->type = type;
    this->value = value;
}

/* PUBLIC */
BluetoothVariableUiComponent::~BluetoothVariableUiComponent() {}

std::string BluetoothVariableUiComponent::getValue(UiComponent* component) {
    std::string isConnected = "true";
    return isConnected;
}

/* STATIC */
VariableUiComponent* BluetoothVariableUiComponent::create(UiType::TYPE type, std::string value) {
    return new BluetoothVariableUiComponent(type, value);
}