#ifndef _FOR_UI_COMPONENT_H_
#define _FOR_UI_COMPONENT_H_

#include "ArithmeticUiComponent.h"
#include "../../parser/matchers/ForRegexMatcher.h"
#include "../../parser/exceptions/ArithmeticException.h"
#include <iostream>
#include <vector>
#include <string>

class ForUiComponent: public ArithmeticUiComponent {
    private:
        /* VARIABLES */
        std::string firstComparison, secondComparison;

        /* FUNCTIONS */
        ForUiComponent(UiType::TYPE type, std::string firstComparison, std::string secondComparison);
        virtual std::string toStringAppendix();
    public:
        ~ForUiComponent();

        static ForUiComponent* parseValues(std::string values);
};

#endif // _FOR_UI_COMPONENT_H_