#include "LineUiComponent.h"

/* PRIVATE */
LineUiComponent::LineUiComponent(UiType::TYPE type): UiComponent(type) {}
LineUiComponent::LineUiComponent(UiType::TYPE type, int x, int y, int xx, int yy): UiComponent(type) {
    this->x = x;
    this->y = y;
    this->xx = xx;
    this->yy = yy;
}

std::string LineUiComponent::toStringAppendix(std::string tabs) {
    return tabs + "X: " + std::to_string(this->x) + "\n" + \
        tabs + "Y: " + std::to_string(this->y) + "\n" + \
        tabs + "XX: " + std::to_string(this->xx) + "\n" +  \
        tabs + "YY: " + std::to_string(this->yy) + "\n";
}

/* PUBLIC */
LineUiComponent::~LineUiComponent() {}

UiComponent* LineUiComponent::parseValues(std::vector<std::string> values) {
    int x = std::stoi(values.at(0));
    int y = std::stoi(values.at(1));
    int xx = std::stoi(values.at(2));
    int yy = std::stoi(values.at(3));
    return new LineUiComponent(UiType::LINE, x, y, xx, yy);
}

void LineUiComponent::execute() {
    std::cout << "Drawing line" << std::endl;
}