#include "LineUiComponent.h"

/* PRIVATE */
LineUiComponent::LineUiComponent(UiType::TYPE type): UiComponent(type) {}
LineUiComponent::LineUiComponent(UiType::TYPE type, int x, int y, int length, int thickness): UiComponent(type) {
    this->x = x;
    this->y = y;
    this->length = length;
    this->thickness = thickness;
}

std::string LineUiComponent::toStringAppendix() {
    return "\tX: " + std::to_string(this->x) + "\n" + \
        "\tY: " + std::to_string(this->y) + "\n" + \
        "\tLENGTH: " + std::to_string(this->length) + "\n" +  \
        "\tTHICKNESS: " + std::to_string(this->thickness) + "\n";
}

/* PUBLIC */
LineUiComponent::~LineUiComponent() {}

UiComponent* LineUiComponent::parseValues(std::vector<std::string> values) {
    int x = std::stoi(values.at(0));
    int y = std::stoi(values.at(1));
    int length = std::stoi(values.at(2));
    int thickness = std::stoi(values.at(3));
    return new LineUiComponent(UiType::LINE, x, y, length, thickness);
    //return new LineUiComponent(UiType::LINE, 0, 0, 0, 0);
}