#ifndef GET_FILE_SIZE_H
#define GET_FILE_SIZE_H

#if __cplusplus == 201703L // C++17
#include <filesystem>
namespace fs = std::filesystem;
#elif  __cplusplus == 201402L // C++14

#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

#elif __cplusplus == 201103L // C++11

#elif __cplusplus == 199711L // C++98
#endif

#include <string>
#include <iostream>

#include <chrono>

namespace GetFileSizeFileSystemApi {
    int main() {

        std::string path = "D:\\temp\\text_file.txt";
        try {
            uint64_t file_size = fs::file_size(path);
            std::cout << "size of " << path << " : " << file_size << std::endl;
        }
        catch (const fs::filesystem_error &err) {
            std::cerr << "filesystem::filesystem_error;\n\twhat: " << err.what() << std::endl;

            if (!err.path1().empty())
                std::cerr << "\tpath1: " << err.path1().string() << std::endl;
            if (!err.path2().empty())
                std::cerr << "\tpath2: " << err.path2().string() << std::endl;
        }
        catch (const std::exception &ex) {
            std::cerr << "std::exception; what: " << ex.what() << std::endl;
        }
    }
}
#endif //GET_FILE_SIZE_H
