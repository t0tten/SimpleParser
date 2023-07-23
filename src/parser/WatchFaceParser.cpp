#include "WatchFaceParser.h"

/* PRIVATES */
bool WatchFaceParser::translate(ArithmeticUiComponent* parent, UiType::TYPE type, std::vector<std::string> fileContent, int& i) {
    std::string parameters = this->regexMatcher->getValues(type, fileContent[i]);
    std::vector<std::string> valuesArray = this->split(parameters, ',');
    switch(type) {
        case UiType::NOOP:
            // Do nothing
            break;
        case UiType::LINE:
            parent->addCodeBlockComponent(LineUiComponent::parseValues(valuesArray));
            break;
        case UiType::CIRCLE:
            parent->addCodeBlockComponent(CircleUiComponent::parseValues(valuesArray));
            break;
        case UiType::TEXT:
            parent->addCodeBlockComponent(TextUiComponent::parseValues(valuesArray));
            break;
        case UiType::RECTANGLE:
            parent->addCodeBlockComponent(RectangleUiComponent::parseValues(valuesArray));
            break;
        case UiType::COLOR:
            parent->addCodeBlockComponent(ColorUiComponent::parseValues(valuesArray));
            break;
        case UiType::IF:
            return this->addCodeBlockComponent(parent, IfUiComponent::parseValues(parameters), fileContent, i);
        case UiType::ELSE_IF:
            return this->addIfComponent(parent, IfUiComponent::parseValues(parameters), fileContent, i);
        case UiType::ELSE:
            return this->addIfComponent(parent, IfUiComponent::emptyValues(), fileContent, i);
        case UiType::FOR:
            return this->addCodeBlockComponent(parent, ForUiComponent::parseValues(parameters), fileContent, i);
        case UiType::ARI_END:
        default:
            return false;
    }
    return true;
}

bool WatchFaceParser::addIfComponent(ArithmeticUiComponent* parent, IfUiComponent* component, std::vector<std::string> fileContent, int& i) {
    IfUiComponent* ifStatement = dynamic_cast<IfUiComponent*>(parent);
    if (ifStatement != nullptr) {
        ifStatement->addIfComponent(component);
        i = this->parse(component, fileContent, ++i);
    }
    return false;
}

bool WatchFaceParser::addCodeBlockComponent(ArithmeticUiComponent* parent, ArithmeticUiComponent* component, std::vector<std::string> fileContent, int& i) {
    parent->addCodeBlockComponent(component);
    i = this->parse(component, fileContent, ++i);
    return true;
}

std::vector<std::string> WatchFaceParser::split(const std::string& filecontent, char delimiter) {
    std::vector<std::string> lines;
    std::string line;

    std::istringstream ss(filecontent);
    while (std::getline(ss, line, delimiter)) {
        lines.push_back(line);
    }

    return lines;
}

int WatchFaceParser::parse(ArithmeticUiComponent* parent, std::vector<std::string> fileContent, int start = 0) {
    int i = start;
    UiType::TYPE type = UiType::NOOP;
    for (; i < fileContent.size(); i++) {
        type = this->regexMatcher->match(fileContent[i]);
        std::string arithmetic = this->regexMatcher->getValues(type, fileContent[i]);
        if (type == UiType::MISSING || !this->translate(parent, type, fileContent, i)) {
            break;
        }
    }
    return i;
}

/* PUBLICS */
WatchFaceParser::WatchFaceParser () {
    this->regexMatcher = new RegexMatcher();
}

WatchFaceParser::~WatchFaceParser () {
    delete this->regexMatcher;
}

WatchFace* WatchFaceParser::generateWatchFace(std::string filename, std::vector<std::string> fileContent) {
    ArithmeticUiComponent* parent = ArithmeticUiComponent::empty();
    int i = this->parse(parent, fileContent);
    if (i != fileContent.size()) {
        throw ParserException(i + 1, fileContent[i]);
    }
    return new WatchFace(filename, parent);
}