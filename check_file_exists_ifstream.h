
#ifndef CHECK_FILE_EXISTS_IFSTREAM_H
#define CHECK_FILE_EXISTS_IFSTREAM_H

#include <fstream> // needed for ifstream
#include <string>
#include <iostream>

namespace CheckFileExistsIfStream {
    inline bool file_exists(const std::string &name) {
        std::ifstream f(name.c_str());
        return f.good();
    }

    int main() {
        std::string filename = "D:/temp/text_file.txt";
        // Make std::cout print true or false instead of 0 or 1
        std::cout << std::boolalpha;
        std::cout << "Does " << filename << " Exists ? "
                  << file_exists(filename) << std::endl;
    }
}
#endif //CHECK_FILE_EXISTS_IFSTREAM_H
