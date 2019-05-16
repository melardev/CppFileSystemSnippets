
#ifndef CHECK_IS_DIRECTORY_H
#define CHECK_IS_DIRECTORY_H

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

namespace CheckIsDirectory {
    bool dir_exists(const std::wstring &dir_path_str) {
        fs::path dir_path{dir_path_str};
        return fs::is_directory(dir_path);
    }

    int main() {
        std::wstring dir = L"D:\\temp";
        bool found = dir_exists(dir);
        std::wcout << std::boolalpha;
        std::wcout << L"Directory " << dir << " does exists? " << found << std::endl;
        return 0;
    }
}
#endif //CHECK_IS_DIRECTORY_H
