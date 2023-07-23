#ifndef _IF_UI_COMPONENT_H_
#define _IF_UI_COMPONENT_H_

#include "ArithmeticUiComponent.h"
#include "../../parser/matchers/IfRegexMatcher.h"
#include "../../parser/matchers/VariableRegexMatcher.h"
#include "../../parser/exceptions/ArithmeticException.h"
#include "../built-in_variables/VariableUiComponent.h"
#include "../built-in_variables/StringVariableUiComponent.h"
#include "../built-in_variables/ClockVariableUiComponent.h"
#include "../built-in_variables/BooleanVariableUiComponent.h"
#include "../built-in_variables/BatteryVariableUiComponent.h"
#include "../built-in_variables/BluetoothVariableUiComponent.h"
#include "../built-in_variables/DateVariableUiComponent.h"
#include "../built-in_variables/HeartVariableUiComponent.h"
#include "../built-in_variables/StepsVariableUiComponent.h"
#include <iostream>
#include <vector>

class IfUiComponent: public ArithmeticUiComponent {
    private:
        /* VARIABLES */
        std::string op;
        VariableUiComponent* component1;
        VariableUiComponent* component2;
        std::vector<IfUiComponent*> ifComponents;

        /* FUNCTIONS */
        IfUiComponent(UiType::TYPE type, std::string op, VariableUiComponent* component1, VariableUiComponent* component2);
        virtual std::string toStringAppendix(std::string tabs);
        void continueWithNextIfStatement();

    public:
        ~IfUiComponent();
        void addIfComponent(IfUiComponent* ifComponent);
        virtual void execute();

        static IfUiComponent* parseValues(std::string values);
        static IfUiComponent* emptyValues();
        static VariableUiComponent* translateToVariable(UiType::TYPE type, std::string value);
};

#endif // _IF_UI_COMPONENT_H_