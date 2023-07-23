#ifndef _CLOCK_VARIABLE_UI_COMPONENT_H_
#define _CLOCK_VARIABLE_UI_COMPONENT_H_

#include "../../parser/types/UiType.h"
#include "VariableUiComponent.h"
#include <iostream>
#include <string>
#include <vector>

class ClockVariableUiComponent: public VariableUiComponent {
    private:
        /* VARIBALES */
        UiType::TYPE type;
        std::string hours, minutes, seconds;
        std::string value;
        
        /* FUNCTIONS */
        virtual std::string toStringAppendix(std::string tabs);
        std::string getHours();
        std::string getMinutes();
        std::string getSeconds();
        std::string getFullTime();
        std::string getTime();

    protected:
        ClockVariableUiComponent(UiType::TYPE type, std::string value);

    public:
        virtual ~ClockVariableUiComponent();
        virtual std::string getValue();

        static VariableUiComponent* create(UiType::TYPE type, std::string value);
};

#endif // _CLOCK_VARIABLE_UI_COMPONENT_H_