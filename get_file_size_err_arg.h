
#ifndef GET_FILE_SIZE_ERR_ARG_H
#define GET_FILE_SIZE_ERR_ARG_H

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

namespace GetFileSizeFileSystemApiErrorArg {
    int main() {

        std::string path = "D:\\temp\\text_file.txt";
        // using error_code
        std::error_code ec{};

        uint64_t file_size = fs::file_size(path, ec);
        if (ec == std::error_code{})
            std::cout << "size of " << path << " : " << file_size << std::endl;
        else
            std::cout << "An error occurred; error message: " << " message: " << ec.message()
                      << std::endl;
    }
}

#endif //GET_FILE_SIZE_ERR_ARG_H
