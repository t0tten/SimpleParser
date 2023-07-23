#include "ColorUiComponent.h"

/* PRIVATE */
ColorUiComponent::ColorUiComponent(UiType::TYPE type, int r, int g, int b): UiComponent(type) {
    this->r = r;
    this->g = g;
    this->b = b;
}

std::string ColorUiComponent::toStringAppendix(std::string tabs) {
    return  tabs + "R: " + std::to_string(this->r) + "\n" + \
            tabs + "G: " + std::to_string(this->g) + "\n" + \
            tabs + "B: " + std::to_string(this->b) + "\n";
}

/* PUBLIC */
ColorUiComponent::~ColorUiComponent() {}

UiComponent* ColorUiComponent::parseValues(std::vector<std::string> values) {
    int r = std::stoi(values.at(0));
    int g = std::stoi(values.at(1));
    int b = std::stoi(values.at(2));
    return new ColorUiComponent(UiType::COLOR, r, g, b);
}

void ColorUiComponent::execute() {
    std::cout << "Changing color" << std::endl;
}