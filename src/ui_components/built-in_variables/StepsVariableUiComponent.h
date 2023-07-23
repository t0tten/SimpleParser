#ifndef _STEPS_VARIABLE_UI_COMPONENT_H_
#define _STEPS_VARIABLE_UI_COMPONENT_H_

#include "../../parser/types/UiType.h"
#include "VariableUiComponent.h"
#include <iostream>
#include <string>
#include <vector>

class StepsVariableUiComponent: public VariableUiComponent {
    private:
        /* VARIBALES */
        UiType::TYPE type;
        std::string value;
        
        /* FUNCTIONS */
        virtual std::string toStringAppendix(std::string tabs);

    protected:
        StepsVariableUiComponent(UiType::TYPE type, std::string value);

    public:
        virtual ~StepsVariableUiComponent();
        virtual std::string getValue();

        static VariableUiComponent* create(UiType::TYPE type, std::string value);
};

#endif // _STEPS_VARIABLE_UI_COMPONENT_H_