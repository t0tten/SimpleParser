#ifndef _FILE_MANAGEMENT_H_
#define _FILE_MANAGEMENT_H_

#include <iostream>
#include <string>
#include <fstream>

class FileManagement {
    private:
        std::string folderPath;
        std::string filecontentStr;

    public:
        FileManagement(std::string folderPath);
        ~FileManagement();

        bool loadFile (std::string filename);
        std::string getFilecontent();
};

#endif // _FILE_MANAGEMENT_H_