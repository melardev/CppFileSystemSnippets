#include<iostream>
#include <sys/stat.h>

namespace CheckFileExistsStat {
    bool file_exists(const std::string &name) {
        struct stat buffer;
        return (stat(name.c_str(), &buffer) == 0);
    }

    int main() {
        std::string filename = "D:/temp/text_file.txt";
        // Make std::cout print true or false instead of 0 or 1
        std::cout << std::boolalpha;
        std::cout << "Does " << filename << " Exists ? "
                  << file_exists(filename) << std::endl;
        return 0;
    }
}