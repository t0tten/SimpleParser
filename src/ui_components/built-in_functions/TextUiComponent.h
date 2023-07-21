#ifndef _TEXT_UI_COMPONENT_H_
#define _TEXT_UI_COMPONENT_H_

#include "../UiComponent.h"
#include <vector>

class TextUiComponent: public UiComponent {
    private:
        /* VARIABLES */
        int x, y;
        int thickness;
        std::string text;

        /* FUNCTIONS */
        TextUiComponent(UiType::TYPE type, int x, int y, int thickness, std::string text);
        virtual std::string toStringAppendix();

    public:
        virtual ~TextUiComponent();

        static UiComponent* parseValues(std::vector<std::string> values);
};

#endif // _TEXT_UI_COMPONENT_H_