//
// Created by Joaquina Daeron on 10/20/23.
//

#include "finder.h"
#include <iostream>

namespace joaquind {
    template<typename T>
    std::vector<std::string> Finder<T>::FindSuitableFiles(std::string s) {
        std::vector<std::string> files;
        files.reserve(20);
        for (auto &i: fs::recursive_directory_iterator(navigator_->GetCurrentPath(),
                                                       fs::directory_options::skip_permission_denied)) {
            auto tmp = i.path().filename().string();
            if (tmp.find(s) != std::string::npos)
                files.emplace_back(tmp);
        }
        return files;
    }
} // joaquind