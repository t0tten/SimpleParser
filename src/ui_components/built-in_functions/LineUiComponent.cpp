#include "LineUiComponent.h"

/* PRIVATE */
LineUiComponent::LineUiComponent(UiType::TYPE type): UiComponent(type) {}
LineUiComponent::LineUiComponent(UiType::TYPE type, int x, int y, int xx, int yy): UiComponent(type) {
    this->x = x;
    this->y = y;
    this->xx = xx;
    this->yy = yy;
}

std::string LineUiComponent::toStringAppendix() {
    return "\tX: " + std::to_string(this->x) + "\n" + \
        "\tY: " + std::to_string(this->y) + "\n" + \
        "\tXX: " + std::to_string(this->xx) + "\n" +  \
        "\tYY: " + std::to_string(this->yy) + "\n";
}

/* PUBLIC */
LineUiComponent::~LineUiComponent() {}

UiComponent* LineUiComponent::parseValues(std::vector<std::string> values) {
    int x = std::stoi(values.at(0));
    int y = std::stoi(values.at(1));
    int xx = std::stoi(values.at(2));
    int yy = std::stoi(values.at(3));
    return new LineUiComponent(UiType::LINE, x, y, xx, yy);
    //return new LineUiComponent(UiType::LINE, 0, 0, 0, 0);
}