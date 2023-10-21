//
// Created by Joaquina Daeron on 10/20/23.
//

#include "filesystem_manager.h"

namespace joaquind {
    std::vector<std::string> FilesystemManager::GetFilesNameFromFile(bool with_path) {
        std::vector<std::string> files;
        files.reserve(20);
        for (auto &i: fs::directory_iterator(GetCurrentPath()))
            files.push_back(with_path ? i.path().filename() : i.path());
        return files;
    }
} // joaquind