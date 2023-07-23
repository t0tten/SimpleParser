#include "TextUiComponent.h"

/* PRIVATE */
TextUiComponent::TextUiComponent(UiType::TYPE type, int x, int y, int thickness, VariableUiComponent* text): UiComponent(type) {
    this->x = x;
    this->y = y;
    this->thickness = thickness;
    this->text = text;
}

std::string TextUiComponent::toStringAppendix(std::string tabs) {
    return  tabs + "X: " + std::to_string(this->x) + "\n" + \
            tabs + "Y: " + std::to_string(this->y) + "\n" + \
            tabs + "THICKNESS: " + std::to_string(this->thickness) + "\n" + \
            tabs + "TEXT: " + this->text->getValue() + "\n";
}

/* PUBLIC */
TextUiComponent::~TextUiComponent() {
    delete this->text;
}

UiComponent* TextUiComponent::parseValues(std::vector<std::string> values) {
    int x = std::stoi(values.at(0));
    int y = std::stoi(values.at(1));
    int thickness = std::stoi(values.at(2));
    VariableUiComponent* text = StringVariableUiComponent::create(UiType::STRING, values.at(3));
    return new TextUiComponent(UiType::TEXT, x, y, thickness, text);
}

void TextUiComponent::execute() {
    std::cout << "Drawing text:" << this->text->getValue() << std::endl;
}