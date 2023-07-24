#ifndef _WATCH_FACE_PARSER_H_
#define _WATCH_FACE_PARSER_H_

#include "../WatchFace.h"
#include "../ui_components/UiComponent.h"
#include "../ui_components/built-in_functions/LineUiComponent.h"
#include "../ui_components/built-in_functions/CircleUiComponent.h"
#include "../ui_components/built-in_functions/TextUiComponent.h"
#include "../ui_components/built-in_functions/RectangleUiComponent.h"
#include "../ui_components/built-in_functions/ColorUiComponent.h"
#include "../ui_components/arithmetics/ArithmeticUiComponent.h"
#include "../ui_components/arithmetics/IfUiComponent.h"
#include "../ui_components/arithmetics/ForUiComponent.h"
#include "matchers/RegexMatcher.h"
#include "exceptions/ParserException.h"
#include "types/UiType.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class WatchFaceParser {
    private:
        /* Variables */
        RegexMatcher* regexMatcher;

        /* Functions */
        std::vector<std::string> split(const std::string& filecontent, char delimiter);
        void parse(ArithmeticUiComponent* parent, std::string& filecontent);
        bool translate(ArithmeticUiComponent* parent, UiType::TYPE type, std::string& parameters, std::string& filecontent);
        bool addCodeBlockComponent(ArithmeticUiComponent* parent, ArithmeticUiComponent* component, std::string& filecontent);
        bool addIfComponent(ArithmeticUiComponent* parent, IfUiComponent* component, std::string& filecontent);

    public:
        WatchFaceParser ();
        ~WatchFaceParser ();

        WatchFace* generateWatchFace(std::string filename, std::string& filecontent);
};

#endif // _WATCH_FACE_PARSER_H_