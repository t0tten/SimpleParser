#ifndef _HEART_VARIABLE_UI_COMPONENT_H_
#define _HEART_VARIABLE_UI_COMPONENT_H_

#include "../../parser/types/UiType.h"
#include "VariableUiComponent.h"
#include <iostream>
#include <string>
#include <vector>

class HeartVariableUiComponent: public VariableUiComponent {
    private:
        /* VARIBALES */
        UiType::TYPE type;
        std::string value;
        
        /* FUNCTIONS */
        virtual std::string toStringAppendix(std::string tabs);

    protected:
        HeartVariableUiComponent(UiType::TYPE type, std::string value);

    public:
        virtual ~HeartVariableUiComponent();
        virtual std::string getValue(UiComponent* component);

        static VariableUiComponent* create(UiType::TYPE type, std::string value);
};

#endif // _HEART_VARIABLE_UI_COMPONENT_H_