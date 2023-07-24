#ifndef _BLUETOOTH_VARIABLE_UI_COMPONENT_H_
#define _BLUETOOTH_VARIABLE_UI_COMPONENT_H_

#include "../../parser/types/UiType.h"
#include "VariableUiComponent.h"
#include <iostream>
#include <string>
#include <vector>

class BluetoothVariableUiComponent: public VariableUiComponent {
    private:
        /* VARIBALES */
        UiType::TYPE type;
        std::string value;
        
        /* FUNCTIONS */
        virtual std::string toStringAppendix(std::string tabs);

    protected:
        BluetoothVariableUiComponent(UiType::TYPE type, std::string value);

    public:
        virtual ~BluetoothVariableUiComponent();
        virtual std::string getValue(UiComponent* component);

        static VariableUiComponent* create(UiType::TYPE type, std::string value);
};

#endif // _BLUETOOTH_VARIABLE_UI_COMPONENT_H_