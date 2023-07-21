#ifndef _RECTANGLE_UI_COMPONENT_H_
#define _RECTANGLE_UI_COMPONENT_H_

#include "../UiComponent.h"
#include <iostream>
#include <vector>

class RectangleUiComponent: public UiComponent {
    private:
        /* VARIABLES */
        int x,y;
        int xx, yy;

        /* FUNCTIONS */
        RectangleUiComponent(UiType::TYPE type);
        RectangleUiComponent(UiType::TYPE type, int x, int y, int xx, int yy);
        virtual std::string toStringAppendix();
    public:
        ~RectangleUiComponent();

        static UiComponent* parseValues(std::vector<std::string> values);
};

#endif // _RECTANGLE_UI_COMPONENT_H_