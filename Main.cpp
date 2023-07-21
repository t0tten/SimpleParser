#include <iostream>
#include "src/Pinetime.h"

using namespace std;

int main() {
    Pinetime* pinetime = new Pinetime();
    if (!pinetime->loadWatchFace("watchface0.wpt")) {
        std::cout << "Watch face does not exist!" << std::endl;
    }
    pinetime->printWatchFaceInformation();

    delete pinetime;
    return 0;
}