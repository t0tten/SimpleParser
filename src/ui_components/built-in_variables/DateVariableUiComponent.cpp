#include "DateVariableUiComponent.h"

/* PRIVATE */
std::string DateVariableUiComponent::toStringAppendix(std::string tabs) {
    return tabs + this->value;
}

std::string DateVariableUiComponent::getDate() { return this->getYear() + "/" + this->getMonth() + "/" + this->getDay();}
std::string DateVariableUiComponent::getFullDate() { return this->getFullYear() + "/" + this->getMonth() + "/" + this->getDay(); }
std::string DateVariableUiComponent::getFullYear() { return this->fullYear; }
std::string DateVariableUiComponent::getYear() { return this->year; }
std::string DateVariableUiComponent::getMonth() { return this->month; }
std::string DateVariableUiComponent::getDay() { return this->day; }

/* PROTECTED */
DateVariableUiComponent::DateVariableUiComponent(UiType::TYPE type, std::string value): VariableUiComponent(type) {
    this->type = type;
    this->value = value;
}

/* PUBLIC */
DateVariableUiComponent::~DateVariableUiComponent() {}

std::string DateVariableUiComponent::getValue(UiComponent* component) {
    this->fullYear = "2023";
    this->year = "23";
    this->month = "07";
    this->day = "20";

    switch (this->type) {
        case UiType::DATE:
            return this->getDate();
        case UiType::DATE_FULL:
            return this->getFullDate();
        case UiType::DATE_FULL_YEAR:
            return this->getFullYear();
        case UiType::DATE_YEAR:
            return this->getYear();
        case UiType::DATE_MONTH:
            return this->getMonth();
        case UiType::DATE_DAY:
            return this->getDay();
        default:
            return "";
    }
}

/* STATIC */
VariableUiComponent* DateVariableUiComponent::create(UiType::TYPE type, std::string value) {
    return new DateVariableUiComponent(type, value);
}