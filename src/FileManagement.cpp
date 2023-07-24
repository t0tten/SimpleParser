#include "FileManagement.h"
#include <regex>

FileManagement::FileManagement(std::string folderPath) {
    this->folderPath = folderPath;
}
FileManagement::~FileManagement() {}

bool FileManagement::loadFile (std::string filename) {
    std::regex comment_reg("[ \n]*//.*");
    std::ifstream file(this->folderPath + filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (!std::regex_match(line, comment_reg)) {
                this->filecontentStr += line;
            }
        }

        file.close();
        return true;
    }
    return false;
}

std::string FileManagement::getFilecontent() {
    return this->filecontentStr;
}