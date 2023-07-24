#ifndef _ARITHMETICS_UI_COMPONENT_H
#define _ARITHMETICS_UI_COMPONENT_H

#include "../UiComponent.h"

class ArithmeticUiComponent: public UiComponent {
    private:
        /* FUNCTIONS */
        virtual std::string toStringAppendix(std::string tabs);

    protected:
        /* VARIABLES */
        std::vector<UiComponent*> codeBlock;

        /* FUNCTIONS */
        ArithmeticUiComponent(UiType::TYPE type);

        void executeCodeBlock(UiComponent* component);

    public:
        ~ArithmeticUiComponent();
        std::vector<UiComponent*>& getCodeBlock();
        void addCodeBlockComponent(UiComponent* component);
        static ArithmeticUiComponent* empty();
        virtual void execute(UiComponent* component);
};

#endif // _ARITHMETICS_UI_COMPONENT_H