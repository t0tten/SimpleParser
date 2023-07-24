#ifndef _VARIABLE_UI_COMPONENT_H_
#define _VARIABLE_UI_COMPONENT_H_

#include "../../parser/types/UiType.h"
#include "..//UiComponent.h"
#include <iostream>
#include <string>
#include <vector>

class VariableUiComponent {
    private:
        /* VARIBALES */
        UiType::TYPE type;
        
        /* FUNCTIONS */
        virtual std::string toStringAppendix(std::string tabs) = 0;

    protected:
        VariableUiComponent(UiType::TYPE type);

    public:
        virtual ~VariableUiComponent();
        virtual std::string getValue(UiComponent* component) = 0;
};

#endif // _VARIABLE_UI_COMPONENT_H_