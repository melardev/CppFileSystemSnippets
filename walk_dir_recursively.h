
#ifndef WALK_DIR_RECURSIVELY_H
#define WALK_DIR_RECURSIVELY_H

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
#include <iomanip>

namespace WalkDirRecursively {


    void walk_dir_recursively(const fs::path &p) {
        std::wcout << L"Walking " << p.wstring() << L" recursively" << std::endl;
        for (fs::recursive_directory_iterator it{p}, end; it != end; ++it) {
            if (is_regular_file(it->status())) {
                std::wcout << std::setw(it.depth() * 4) << L" " << it->path() << std::endl;
            } else if (is_directory(it->status())) {
                std::wcout << std::setw(it.depth() * 4) << L" " << "Dir: " << it->path().filename() << std::endl;
            }
        }
    }


    int main() {
        fs::path path(L"./");
        walk_dir_recursively(path);
        return 0;
    }
}
#endif //WALK_DIR_RECURSIVELY_H
