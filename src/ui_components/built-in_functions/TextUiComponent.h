#ifndef _TEXT_UI_COMPONENT_H_
#define _TEXT_UI_COMPONENT_H_

#include "../UiComponent.h"
#include "../built-in_variables/StringVariableUiComponent.h"
#include <vector>

class TextUiComponent: public UiComponent {
    private:
        /* VARIABLES */
        int x, y;
        int thickness;
        VariableUiComponent* text;

        /* FUNCTIONS */
        TextUiComponent(UiType::TYPE type, int x, int y, int thickness, VariableUiComponent* text);
        virtual std::string toStringAppendix(std::string tabs);

    public:
        virtual ~TextUiComponent();

        static UiComponent* parseValues(std::vector<std::string> values);
        virtual void execute();
};

#endif // _TEXT_UI_COMPONENT_H_