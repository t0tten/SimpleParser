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
        int start, end;

        /* FUNCTIONS */
        ForUiComponent(UiType::TYPE type, int start, int end);
        virtual std::string toStringAppendix(std::string tabs);
    public:
        ~ForUiComponent();
        virtual void execute();
        static ForUiComponent* parseValues(std::string values);
};

#endif // _FOR_UI_COMPONENT_H_