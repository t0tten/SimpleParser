#include "ArithmeticUiComponent.h"

/* PRIVATE */
std::string ArithmeticUiComponent::toStringAppendix(std::string tabs) {
    return "";
}

/* PROTECTED */
ArithmeticUiComponent::ArithmeticUiComponent(UiType::TYPE type): UiComponent(type) {}

/* PUBLIC */
ArithmeticUiComponent::~ArithmeticUiComponent() {
    for (int i = 0; i < this->codeBlock.size(); i++) {
        delete codeBlock[i];
    }
}

std::vector<UiComponent*>& ArithmeticUiComponent::getCodeBlock() {
    return this->codeBlock;
}

void ArithmeticUiComponent::addCodeBlockComponent(UiComponent* component) {
    this->codeBlock.push_back(component);
}

ArithmeticUiComponent* ArithmeticUiComponent::empty() {
    return new ArithmeticUiComponent(UiType::NOOP);
}

void ArithmeticUiComponent::execute() {
    for (int i = 0; i < this->codeBlock.size(); i++) {
        this->codeBlock[i]->execute();
    }
}

void ArithmeticUiComponent::executeCodeBlock() {
    for (int i = 0; i < this->codeBlock.size(); i++) {
        this->codeBlock[i]->execute();
    }
}