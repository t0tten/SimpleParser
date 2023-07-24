#include "WatchFaceParser.h"

/* PRIVATES */
bool WatchFaceParser::translate(ArithmeticUiComponent* parent, UiType::TYPE type, std::string& parameters, std::string& filecontent) {
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
            return this->addCodeBlockComponent(parent, IfUiComponent::parseValues(parameters), filecontent);
        case UiType::ELSE_IF:
            return this->addIfComponent(parent, IfUiComponent::parseValues(parameters), filecontent);
        case UiType::ELSE:
            return this->addIfComponent(parent, IfUiComponent::emptyValues(), filecontent);
        case UiType::FOR:
            return this->addCodeBlockComponent(parent, ForUiComponent::parseValues(parameters), filecontent);
        case UiType::ARI_END:
        default:
            return false;
    }
    return true;
}
bool WatchFaceParser::addCodeBlockComponent(ArithmeticUiComponent* parent, ArithmeticUiComponent* component, std::string& filecontent) {
    parent->addCodeBlockComponent(component);
    this->parse(component, filecontent);
    return true;
}

bool WatchFaceParser::addIfComponent(ArithmeticUiComponent* parent, IfUiComponent* component, std::string& filecontent) {
    IfUiComponent* ifStatement = dynamic_cast<IfUiComponent*>(parent);
    if (ifStatement != nullptr) {
        ifStatement->addIfComponent(component);
        this->parse(component, filecontent);
    }
    return false;
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

/* PUBLICS */
WatchFaceParser::WatchFaceParser () {
    this->regexMatcher = new RegexMatcher();
}

WatchFaceParser::~WatchFaceParser () {
    delete this->regexMatcher;
}

void WatchFaceParser::parse(ArithmeticUiComponent* parent, std::string& filecontent) {
    UiType::TYPE type;
    while (type != UiType::MISSING && filecontent.size() > 0) {
        type = this->regexMatcher->match(filecontent);
        if (type != UiType::MISSING) {
            std::string values = this->regexMatcher->getValues(type, filecontent);
            if (!translate(parent, type, values, filecontent)) {
                break;
            }
        } else {
            throw ParserException(0, filecontent);
        }
    }
}

WatchFace* WatchFaceParser::generateWatchFace(std::string filename, std::string& filecontent) {
    ArithmeticUiComponent* parent = ArithmeticUiComponent::empty();
    this->parse(parent, filecontent);
    if (filecontent.length() != 0) {
        throw ParserException(0, filecontent);
    }
    return new WatchFace(filename, parent);
 }