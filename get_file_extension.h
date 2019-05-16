#ifndef GET_FILE_EXTENSION_H
#define GET_FILE_EXTENSION_H


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
#include <cassert>


namespace GetFileExtension {

    std::string get_file_extension(const fs::path &file_path) {

        if (file_path.has_extension()) {
            // Get file extension as string, we could also get it tas wstring
            return file_path.extension().string();
        }

        // No file extension, return empty string
        return "";
    }

    int main() {
        std::wstring filePath = L"D:\\temp\\file_text.txt";

        std::string extension = get_file_extension(filePath);
        std::wcout << "Testing: " << filePath << std::endl;
        std::cout << "Extension : " << extension << std::endl;

        assert(extension == ".txt");
        filePath = L"D:\\temp\\"; // It is a directory
        std::wcout << "Testing: " << filePath << std::endl;
        extension = get_file_extension(filePath);
        std::cout << "Extension : " << extension << std::endl;

        assert(extension.empty());
        return 0;
    }
}
#endif //GET_FILE_EXTENSION_H
