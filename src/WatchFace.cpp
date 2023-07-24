#include "WatchFace.h"

WatchFace::WatchFace(std::string name, ArithmeticUiComponent* root) {
    this->name = name;
    this->root = root;
}

WatchFace::~WatchFace() {
    std::vector<UiComponent*> codeBlock = this->root->getCodeBlock();
    for (int i = 0; i < codeBlock.size(); i++) {
        delete codeBlock[i];
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