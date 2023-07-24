#ifndef _TEXT_UI_COMPONENT_H_
#define _TEXT_UI_COMPONENT_H_

#include "../UiComponent.h"
#include "../built-in_variables/StringVariableUiComponent.h"
#include <vector>

class TextUiComponent: public UiComponent {
    private:
        /* VARIABLES */
        std::string x, y;
        std::string thickness;
        VariableUiComponent* text;

        /* FUNCTIONS */
        TextUiComponent(UiType::TYPE type, std::string x, std::string y, std::string thickness, VariableUiComponent* text);
        virtual std::string toStringAppendix(std::string tabs);

    public:
        virtual ~TextUiComponent();

        static UiComponent* parseValues(std::vector<std::string> values);
        virtual void execute(UiComponent* component);
};

#endif // _TEXT_UI_COMPONENT_H_