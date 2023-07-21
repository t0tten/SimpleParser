#ifndef _WATCH_FACE_H_
#define _WATCH_FACE_H_

#include "ui_components/arithmetics/ArithmeticUiComponent.h"
#include <string>

class WatchFace {
    private:
        std::string name;
        ArithmeticUiComponent* root;

    public:
        WatchFace(std::string name, ArithmeticUiComponent* root);
        ~WatchFace();

        std::string toString();
};

#endif //_WATCH_FACE_H_