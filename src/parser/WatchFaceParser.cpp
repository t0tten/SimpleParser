#include "WatchFaceParser.h"

/* PRIVATES */
bool WatchFaceParser::translateBuiltIns(ArithmeticUiComponent* parent, UiType::TYPE type, std::string values) {
    std::vector<std::string> valuesArray = this->split(values, ',');
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
        default:
            return true;
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

int WatchFaceParser::parse(ArithmeticUiComponent* parent, std::vector<std::string> fileContent, int start = 0) {
    int i = start;
    UiType::TYPE type = UiType::NOOP;
    for (; i < fileContent.size(); i++) {
        type = this->regexMatcher->match(fileContent[i]);

        if (type == UiType::MISSING) {
            break;
        }
        std::string arithmetic = this->regexMatcher->getValues(type, fileContent[i]);
        if (type == UiType::IF) {
            IfUiComponent* ifStatement = IfUiComponent::parseValues(arithmetic);
            i = this->parse(ifStatement, fileContent, ++i);
            parent->addCodeBlockComponent(ifStatement);
        } else if (type == UiType::ELSE_IF) {
            IfUiComponent* ifStatement = dynamic_cast<IfUiComponent*>(parent);
            if (ifStatement != nullptr) {
                IfUiComponent* elseIfStatement = IfUiComponent::parseValues(arithmetic);
                i = this->parse(elseIfStatement, fileContent, ++i);
                ifStatement->addIfComponent(elseIfStatement);
                break;
            }
        } else if (type == UiType::ELSE) {
            IfUiComponent* ifStatement = dynamic_cast<IfUiComponent*>(parent);
            if (ifStatement != nullptr) {
                IfUiComponent* elseStatement = IfUiComponent::emptyValues();
                i = this->parse(elseStatement, fileContent, ++i);
                ifStatement->addIfComponent(elseStatement);
                break;
            }
        } else if (type == UiType::FOR) {
            ForUiComponent* forLoop = ForUiComponent::parseValues(arithmetic);
            i = this->parse(forLoop, fileContent, ++i);
            parent->addCodeBlockComponent(forLoop);
        } else if (type == UiType::ARI_END) {
            break;
        } else {
            std::string parameters = this->regexMatcher->getValues(type, fileContent[i]);
            if (this->translateBuiltIns(parent, type, parameters)) {
                break;
            }
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