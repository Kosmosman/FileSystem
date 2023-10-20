//
// Created by Joaquina Daeron on 10/20/23.
//
// Class represent interface for find a way from home directory of current user
// and returns a files from directories
//

#ifndef FILESYSTEM_FILESYSTEM_MANAGER_H
#define FILESYSTEM_FILESYSTEM_MANAGER_H

#include <vector>
#include <filesystem>
#include <cstdlib>

namespace joaquind {
    namespace fs = std::filesystem;

    class FilesystemManager {
    public:
        FilesystemManager() :current_path_{std::getenv("HOME")} {}
        std::vector<std::string> GetFilesNameFromFile();
        void IntoNextDirectory(std::string s) {current_path_.emplace_back(s); };
        void IntoPrevDirectory() {if (current_path_. size() > 1) current_path_.pop_back(); };
    private:
        std::vector<std::string> current_path_;
    };

} // joaquind

#endif //FILESYSTEM_FILESYSTEM_MANAGER_H
