#include <iostream>
#include "src/Pinetime.h"

using namespace std;

int main() {
    Pinetime* pinetime = new Pinetime();
    if (!pinetime->loadWatchFace("watchface0.wpt")) {
        std::cout << "Watch face does not exist!" << std::endl;
    }

    /*std::cout << std::endl << "PRINTING OBJECTS:" << std::endl;
    pinetime->printWatchFaceInformation();*/

    std::cout << std::endl <<  "EXECUTING CODE:" << std::endl;
    pinetime->executeWatchFace();

    delete pinetime;
    return 0;
}