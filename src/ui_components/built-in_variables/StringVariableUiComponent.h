#ifndef _STRING_VARIABLE_UI_COMPONENT_H_
#define _STRING_VARIABLE_UI_COMPONENT_H_

#include "../../parser/types/UiType.h"
#include "VariableUiComponent.h"
#include "../../parser/matchers/VariableRegexMatcher.h"
#include "../arithmetics/IfUiComponent.h"
#include <iostream>
#include <string>
#include <vector>
#include <regex>

class StringVariableUiComponent: public VariableUiComponent {
    private:
        /* VARIBALES */
        UiType::TYPE type;
        std::string value;
        
        /* FUNCTIONS */
        virtual std::string toStringAppendix(std::string tabs);

    protected:
        StringVariableUiComponent(UiType::TYPE type, std::string value);

    public:
        virtual ~StringVariableUiComponent();
        virtual std::string getValue();

        static VariableUiComponent* create(UiType::TYPE type, std::string value);
};

#endif // _STRING_VARIABLE_UI_COMPONENT_H_