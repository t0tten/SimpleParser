#ifndef _IF_UI_COMPONENT_H_
#define _IF_UI_COMPONENT_H_

#include "ArithmeticUiComponent.h"
#include "../../parser/matchers/IfRegexMatcher.h"
#include "../../parser/exceptions/ArithmeticException.h"
#include <iostream>
#include <vector>

class IfUiComponent: public ArithmeticUiComponent {
    private:
        /* VARIABLES */
        std::string op;
        std::string firstComparison, secondComparison;
        std::vector<IfUiComponent*> ifComponents;

        /* FUNCTIONS */
        IfUiComponent(UiType::TYPE type, std::string op, std::string firstComparison, std::string secondComparison);
        virtual std::string toStringAppendix();
    public:
        ~IfUiComponent();
        void addIfComponent(IfUiComponent* ifComponent);

        static IfUiComponent* parseValues(std::string values);
        static IfUiComponent* emptyValues();
};

#endif // _IF_UI_COMPONENT_H_