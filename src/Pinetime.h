#ifndef _PINETIME_H_
#define _PINETIME_H_

#include "WatchFace.h"
#include "parser/WatchFaceParser.h"
#include "parser/exceptions/ParserException.h"
#include "parser/exceptions/ArithmeticException.h"
#include "FileManagement.h"
#include <iostream>
#include <vector>

class Pinetime {
    private:
        WatchFace* watchFace;
        WatchFaceParser* watchFaceParser;
        FileManagement* fileManagement;

    public:
        Pinetime();
        ~Pinetime();

        void printWatchFaceInformation();
        bool loadWatchFace(std::string filename);
};

#endif // _PINETIME_H_