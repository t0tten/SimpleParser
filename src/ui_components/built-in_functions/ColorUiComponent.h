#ifndef _COLOR_UI_COMPONENT_H_
#define _COLOR_UI_COMPONENT_H_

#include "../UiComponent.h"
#include <vector>

class ColorUiComponent: public UiComponent {
    private:
        /* VARIABLES */
        int r,g,b;

        /* FUNCTIONS */
        ColorUiComponent(UiType::TYPE type, int r, int g, int b);
        virtual std::string toStringAppendix();

    public:
        virtual ~ColorUiComponent();
        static UiComponent* parseValues(std::vector<std::string> values);
};

#endif // _COLOR_UI_COMPONENT_H_