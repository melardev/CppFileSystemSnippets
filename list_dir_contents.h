
#ifndef LIST_DIR_CONTENTS_H
#define LIST_DIR_CONTENTS_H

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

namespace ListDirContents {
    // List files and directories in the specified path
    void list_dir_contents(const fs::path &p) {
        if (fs::exists(p) && fs::is_directory(p)) {
            for (const auto &entry : fs::directory_iterator{p}) {
                std::wcout << entry.path().filename();
                if (is_regular_file(entry.status())) {
                    std::wcout << L"\t\t\t\t[File]" << std::endl;
                } else if (fs::is_directory(entry.status())) {
                    std::wcout << L"\t\t\t\t[Dir]" << std::endl;
                }
            }
        } else {

            std::cout << p.string() << "Does not exist " << std::endl;
        }
    }

    int main() {
        fs::path path("./");
        list_dir_contents(path);
        return 0;
    }
}
#endif //LIST_DIR_CONTENTS_H
