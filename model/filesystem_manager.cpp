//
// Created by Joaquina Daeron on 10/20/23.
//

#include "filesystem_manager.h"
#include <numeric>

namespace joaquind {
    std::vector<std::string> FilesystemManager::GetFilesNameFromFile() {
        std::vector<std::string> files;
        files.reserve(20);
        fs::path current_path = std::accumulate(current_path_.begin(), current_path_.end(), std::string());
        for (auto &i: fs::directory_iterator(current_path)) {
            files.push_back(i.path());
        }
        return files;
    }
} // joaquind