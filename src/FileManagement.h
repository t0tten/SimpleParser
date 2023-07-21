#ifndef _FILE_MANAGEMENT_H_
#define _FILE_MANAGEMENT_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class FileManagement {
    private:
        std::string folderPath;
        std::vector<std::string> filecontent;

    public:
        FileManagement(std::string folderPath);
        ~FileManagement();

        bool loadFile (std::string filename);
        std::vector<std::string> getFilecontent();
};

#endif // _FILE_MANAGEMENT_H_