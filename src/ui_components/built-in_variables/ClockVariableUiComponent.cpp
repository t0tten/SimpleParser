#include "ClockVariableUiComponent.h"

/* PRIVATE */
std::string ClockVariableUiComponent::toStringAppendix(std::string tabs) {
    return "";
}
std::string ClockVariableUiComponent::getHours() { return this->hours; }
std::string ClockVariableUiComponent::getMinutes() { return this->minutes; }
std::string ClockVariableUiComponent::getSeconds() { return this->seconds; }
std::string ClockVariableUiComponent::getTime() { return this->getHours() + ":" + this->getMinutes(); }
std::string ClockVariableUiComponent::getFullTime() { return this->getTime() + ":" + this->getSeconds(); }

/* PROTECTED */
ClockVariableUiComponent::ClockVariableUiComponent(UiType::TYPE type, std::string value): VariableUiComponent(type) {
    this->type = type;
    this->value = value;
}

/* PUBLIC */
ClockVariableUiComponent::~ClockVariableUiComponent() {}

std::string ClockVariableUiComponent::getValue(UiComponent* component) {
    this->hours = "13";
    this->minutes = "37";
    this->seconds = "00";

    switch(this->type) {
        case UiType::CLOCK:
            return this->getTime();
        case UiType::CLOCK_FULL:
            return this->getFullTime();
        case UiType::CLOCK_HOUR:
            return this->getHours();
        case UiType::CLOCK_MIN:
            return this->getMinutes();
        case UiType::CLOCK_SEC:
            return this->getSeconds();
        default:
            return "";
    }
}

/* STATIC */
VariableUiComponent* ClockVariableUiComponent::create(UiType::TYPE type, std::string value) {
    return new ClockVariableUiComponent(type, value);
}