#include <cstdio>  /* defines FILENAME_MAX */

#if defined(_WIN32) || defined(_WIN64)
#include <direct.h>
#include <string>
#define getCurrentWorkingDirectory _getcwd
#else

#include <unistd.h>

#define getCurrentWorkingDirectory getcwd
#endif

#include <iostream>


namespace GetCurrentWorkingDirectory {
    std::string get_current_working_directory() {
        char buffer[FILENAME_MAX];
        getCurrentWorkingDirectory(buffer, FILENAME_MAX);
        std::string current_working_dir(buffer);
        return current_working_dir;
    }

    int main() {
        const std::string &cwd = get_current_working_directory();
        std::cout << cwd << std::endl;
        return 1;
    }
}
