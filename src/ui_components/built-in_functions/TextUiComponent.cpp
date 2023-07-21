#include "TextUiComponent.h"

/* PRIVATE */
TextUiComponent::TextUiComponent(UiType::TYPE type, int x, int y, int thickness, std::string text): UiComponent(type) {
    this->x = x;
    this->y = y;
    this->thickness = thickness;
    this->text = text;
}

std::string TextUiComponent::toStringAppendix() {
    return  "\tX: " + std::to_string(this->x) + "\n" + \
            "\tY: " + std::to_string(this->y) + "\n" + \
            "\tTHICKNESS: " + std::to_string(this->thickness) + "\n" + \
            "\tTEXT: " + this->text + "\n";
}

/* PUBLIC */
TextUiComponent::~TextUiComponent() {

}

UiComponent* TextUiComponent::parseValues(std::vector<std::string> values) {
    int x = std::stoi(values.at(0));
    int y = std::stoi(values.at(1));
    int thickness = std::stoi(values.at(2));
    std::string text = values.at(3);
    return new TextUiComponent(UiType::TEXT, x, y, thickness, text);
}