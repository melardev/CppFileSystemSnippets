#ifndef WALK_DIR_YIELD_FILES_H
#define WALK_DIR_YIELD_FILES_H

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

#include <string>
#include <vector>
#include <functional>
#include <experimental/filesystem>
#include <regex>

namespace WalkDirYieldFiles {

    bool walk_dir_callback(const fs::path &file) {
        // You may have a more robust criteria obviously, such as looking for a specific filename
        const std::string &extension = file.extension().string();
        if (extension == ".cpp") {
            std::cout << "I found my cpp file that's it !" << std::endl;
            std::wcout << "\t" << file.wstring() << std::endl;
            return false; // stop walking
        }
        return true; // keep going
    }

    bool walk_dir_recursive_yield_match(const fs::path &path,
                                        const std::function<bool(fs::path)> &callback) {


        for (auto const &p : fs::recursive_directory_iterator(path)) {
            if (!fs::is_directory(p)) {
                if (!callback(p.path()))
                    return false; // not walked the whole tree
            }
        }

        return true; // walked the whole tree
    }

    int main() {
        bool walked_whole_tree = walk_dir_recursive_yield_match(L"./", walk_dir_callback);
        if (walked_whole_tree)
            std::cout << "The tree has been completely iterated recursively" << std::endl;
        else
            std::cout << "Finished before going through the whole tree " << std::endl;
        return 0;
    }

}


#endif //WALK_DIR_YIELD_FILES_H
