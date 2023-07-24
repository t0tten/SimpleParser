#include "Pinetime.h"

Pinetime::Pinetime() {
    this->watchFace = NULL;
    this->watchFaceParser = new WatchFaceParser();
    this->fileManagement = new FileManagement("resources/");
}

Pinetime::~Pinetime() {
    if (this->watchFace != NULL) {
        delete this->watchFace;
    }
    delete this->fileManagement;
    delete this->watchFaceParser;
}

void Pinetime::printWatchFaceInformation() {
    if (this->watchFace != NULL) {
        std::cout << this->watchFace->toString();
    }
}

void Pinetime::executeWatchFace() {
    if (this->watchFace != NULL) {
        this->watchFace->execute();
    }
}

bool Pinetime::loadWatchFace(std::string filename) {
    if (this->fileManagement->loadFile(filename)) {
        std::string filecontent = this->fileManagement->getFilecontent();
        try {
            WatchFace* watchFace =this->watchFaceParser->generateWatchFace(filename, filecontent);
            if (watchFace != NULL) {
                this->watchFace = watchFace;
                return true;
            }
        } catch(ParserException e) {
            std::cout << e.getMessage() << std::endl;
            exit(-1);
        } catch (ArithmeticException e) {
            std::cout << e.getMessage() << std::endl;
            exit(-1);
        }
    }
    return false;
}