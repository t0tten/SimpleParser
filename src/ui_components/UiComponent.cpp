#include "UiComponent.h"

/* PRIVATE */
UiComponent::UiComponent() {}

UiComponent::UiComponent(UiType::TYPE type) {
    this->type = type;
}

/* PUBLIC */
UiComponent::~UiComponent() {}

std::string UiComponent::toString() {
    std::string strType = "";
    switch(this->type) {
        case UiType::LINE:
            strType = "LINE";
            break;
        case UiType::CIRCLE:
            strType = "CIRCLE";
            break;
        case UiType::TEXT:
            strType = "TEXT";
            break;
        case UiType::RECTANGLE:
            strType = "RECTANGLE";
            break;
        case UiType::COLOR:
            strType = "COLOR";
            break;
        case UiType::IF:
            strType = "IF-STATEMENT";
            break;
        case UiType::FOR:
            strType = "FOR-LOOP";
            break;
        default:
            break;
    }
    return "TYPE: " + strType + "\n" + this->toStringAppendix();
}