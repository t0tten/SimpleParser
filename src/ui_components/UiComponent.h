#ifndef _UI_COMPONENT_H_
#define _UI_COMPONENT_H_

#include "../parser/types/UiType.h"
#include <iostream>
#include <string>
#include <vector>

class UiComponent {
    private:
        /* VARIBALES */
        UiType::TYPE type;
        
        /* FUNCTIONS */
        UiComponent();
        virtual std::string toStringAppendix(std::string tabs) = 0;

    protected:
        UiComponent(UiType::TYPE type);

    public:
        virtual ~UiComponent();
        std::string toString(std::string tabs);
        virtual void execute(UiComponent* component) = 0;
};

#endif // _UI_COMPONENT_H_