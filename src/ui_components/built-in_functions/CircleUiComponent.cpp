#include "CircleUiComponent.h"

/* PRIVATE */
CircleUiComponent::CircleUiComponent(UiType::TYPE type, int x, int y, int radius): UiComponent(type) {
    this->x = x;
    this->y = y;
    this->radius = radius;
}

std::string CircleUiComponent::toStringAppendix() {
    return  "\tX: " + std::to_string(this->x) + "\n" + \
            "\tY: " + std::to_string(this->y) + "\n" + \
            "\tRADIUS: " + std::to_string(this->radius) + "\n";
}

/* PUBLIC */
CircleUiComponent::~CircleUiComponent() {}

UiComponent* CircleUiComponent::parseValues(std::vector<std::string> values) {
    int x = std::stoi(values.at(0));
    int y = std::stoi(values.at(1));
    int radius = std::stoi(values.at(2));
    return new CircleUiComponent(UiType::CIRCLE, x, y, radius);
}