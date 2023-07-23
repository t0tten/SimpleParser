#ifndef _LINE_UI_COMPONENT_H_
#define _LINE_UI_COMPONENT_H_

#include "../UiComponent.h"
#include <iostream>
#include <vector>

class LineUiComponent: public UiComponent {
    private:
        /* VARIABLES */
        int x,y;
        int xx, yy;

        /* FUNCTIONS */
        LineUiComponent(UiType::TYPE type);
        LineUiComponent(UiType::TYPE type, int x, int y, int xx, int yy);
        virtual std::string toStringAppendix(std::string tabs);
    public:
        ~LineUiComponent();

        static UiComponent* parseValues(std::vector<std::string> values);
        virtual void execute();
};

#endif // _LINE_UI_COMPONENT_H_