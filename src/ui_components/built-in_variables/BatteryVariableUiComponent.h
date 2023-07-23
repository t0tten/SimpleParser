#ifndef _BATTERY_VARIABLE_UI_COMPONENT_H_
#define _BATTERY_VARIABLE_UI_COMPONENT_H_

#include "../../parser/types/UiType.h"
#include "VariableUiComponent.h"
#include <iostream>
#include <string>
#include <vector>

class BatteryVariableUiComponent: public VariableUiComponent {
    private:
        /* VARIBALES */
        UiType::TYPE type;
        std::string value;
        
        /* FUNCTIONS */
        virtual std::string toStringAppendix(std::string tabs);

    protected:
        BatteryVariableUiComponent(UiType::TYPE type, std::string value);

    public:
        virtual ~BatteryVariableUiComponent();
        virtual std::string getValue();

        static VariableUiComponent* create(UiType::TYPE type, std::string value);
};

#endif // _BATTERY_VARIABLE_UI_COMPONENT_H_