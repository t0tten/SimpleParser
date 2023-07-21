#include "FileManagement.h"

FileManagement::FileManagement(std::string folderPath) {
    this->folderPath = folderPath;
}
FileManagement::~FileManagement() {}

bool FileManagement::loadFile (std::string filename) {
    std::ifstream file(this->folderPath + filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            this->filecontent.push_back(line);
        }

        file.close();
        return true;
    }
    return false;
}

std::vector<std::string> FileManagement::getFilecontent() {
    return this->filecontent;
}