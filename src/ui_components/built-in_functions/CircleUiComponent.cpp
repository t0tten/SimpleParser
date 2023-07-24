#include "CircleUiComponent.h"

/* PRIVATE */
CircleUiComponent::CircleUiComponent(UiType::TYPE type, int x, int y, int radius): UiComponent(type) {
    this->x = x;
    this->y = y;
    this->radius = radius;
}

std::string CircleUiComponent::toStringAppendix(std::string tabs) {
    return  tabs + "X: " + std::to_string(this->x) + "\n" + \
            tabs + "Y: " + std::to_string(this->y) + "\n" + \
            tabs + "RADIUS: " + std::to_string(this->radius) + "\n";
}

/* PUBLIC */
CircleUiComponent::~CircleUiComponent() {}

UiComponent* CircleUiComponent::parseValues(std::vector<std::string> values) {
    int x = std::stoi(values.at(0));
    int y = std::stoi(values.at(1));
    int radius = std::stoi(values.at(2));
    return new CircleUiComponent(UiType::CIRCLE, x, y, radius);
}

void CircleUiComponent::execute(UiComponent* component) {
    std::cout << "Drawing circle" << std::endl;
}