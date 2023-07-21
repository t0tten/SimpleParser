#ifndef _CIRCLE_UI_COMPONENT_H_
#define _CIRCLE_UI_COMPONENT_H_

#include "../UiComponent.h"
#include <vector>

class CircleUiComponent: public UiComponent {
    private:
        /* VARIABLES */
        int x,y;
        int radius;

        /* FUNCTIONS */
        CircleUiComponent(UiType::TYPE type, int x, int y, int radius);
        virtual std::string toStringAppendix();

    public:
        virtual ~CircleUiComponent();
        static UiComponent* parseValues(std::vector<std::string> values);
};

#endif // _CIRCLE_UI_COMPONENT_H_