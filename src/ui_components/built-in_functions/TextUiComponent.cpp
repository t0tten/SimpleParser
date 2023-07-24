#include "TextUiComponent.h"

/* PRIVATE */
TextUiComponent::TextUiComponent(UiType::TYPE type, std::string x, std::string y, std::string thickness, VariableUiComponent* text): UiComponent(type) {
    this->x = x;
    this->y = y;
    this->thickness = thickness;
    this->text = text;
}

std::string TextUiComponent::toStringAppendix(std::string tabs) {
    return  tabs + "X: " + this->x + "\n" + \
            tabs + "Y: " + this->y + "\n" + \
            tabs + "THICKNESS: " + this->thickness + "\n" + \
            tabs + "TEXT: " + this->text->getValue(NULL) + "\n";
}

/* PUBLIC */
TextUiComponent::~TextUiComponent() {
    delete this->text;
}

UiComponent* TextUiComponent::parseValues(std::vector<std::string> values) {
    VariableUiComponent* text = StringVariableUiComponent::create(UiType::STRING, values.at(3));
    return new TextUiComponent(UiType::TEXT, values.at(0), values.at(1), values.at(2), text);
}

void TextUiComponent::execute(UiComponent* component) {
    bool comingFromFor = false;
    std::string tx = this->x;
    std::string ty = this->y;
    std::string tthickness = this->thickness;
    ForUiComponent* forUiComponent = dynamic_cast<ForUiComponent*>(component);
    if (forUiComponent != nullptr) {
        VariableRegexMatcher variableRegexMatcher;
        std::string regex = variableRegexMatcher.getRegexForType(UiType::INDEX);
        std::regex replace_reg(regex);
        std::string translatedValue = std::to_string(forUiComponent->getIndex());;
        tx = std::regex_replace(tx, replace_reg, translatedValue);
        ty = std::regex_replace(ty, replace_reg, translatedValue);
        tthickness = std::regex_replace(tthickness, replace_reg, translatedValue);
    }
    std::cout << "Drawing text (" << tx << ", " << ty << "): thickness: " << tthickness << ", text:" << this->text->getValue(component) << std::endl;
}