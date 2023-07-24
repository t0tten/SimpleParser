#ifndef _DATE_VARIABLE_UI_COMPONENT_H_
#define _DATE_VARIABLE_UI_COMPONENT_H_

#include "../../parser/types/UiType.h"
#include "VariableUiComponent.h"
#include <iostream>
#include <string>
#include <vector>

class DateVariableUiComponent: public VariableUiComponent {
    private:
        /* VARIBALES */
        UiType::TYPE type;
        std::string value;
        std::string fullYear, year, month, day;
        
        /* FUNCTIONS */
        virtual std::string toStringAppendix(std::string tabs);
        std::string getDate();
        std::string getFullDate();
        std::string getFullYear();
        std::string getYear();
        std::string getMonth();
        std::string getDay();

    protected:
        DateVariableUiComponent(UiType::TYPE type, std::string value);

    public:
        virtual ~DateVariableUiComponent();
        virtual std::string getValue(UiComponent* component);

        static VariableUiComponent* create(UiType::TYPE type, std::string value);
};

#endif // _DATE_VARIABLE_UI_COMPONENT_H_