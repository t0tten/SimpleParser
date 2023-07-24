#include "WatchFace.h"

WatchFace::WatchFace(std::string name, ArithmeticUiComponent* root) {
    this->name = name;
    this->root = root;
}

WatchFace::~WatchFace() {
    if (this->root != NULL) {
        delete this->root;
    }
}

std::string WatchFace::toString() {
    std::vector<UiComponent*> codeBlock = this->root->getCodeBlock();
    std::string retVal = "NAME: " + this->name + "\n";
    for (int i = 0; i < codeBlock.size(); i++) {
        retVal += codeBlock[i]->toString("");
    }
    return retVal;
}

void WatchFace::execute() {
    if (this->root != NULL) {
        this->root->execute(NULL);
    }
}