#ifndef _ARITHMETICS_UI_COMPONENT_H
#define _ARITHMETICS_UI_COMPONENT_H

#include "../UiComponent.h"

class ArithmeticUiComponent: public UiComponent {
    private:
        /* FUNCTIONS */
        virtual std::string toStringAppendix();

    protected:
        /* VARIABLES */
        std::vector<UiComponent*> codeBlock;

        /* FUNCTIONS */
        ArithmeticUiComponent(UiType::TYPE type);

    public:
        ~ArithmeticUiComponent();
        std::vector<UiComponent*>& getCodeBlock();
        void addCodeBlockComponent(UiComponent* component);
        static ArithmeticUiComponent* empty();
};

#endif // _ARITHMETICS_UI_COMPONENT_H