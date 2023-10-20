//
// Created by Joaquina Daeron on 10/20/23.
//

#ifndef FILESYSTEM_FINDER_H
#define FILESYSTEM_FINDER_H

#include <filesystem_manager.h>

#include <filesystem>
#include <vector>

namespace joaquind {
    namespace fs = std::filesystem;

    // Нужен контроллер под Finder и Manager
    template<typename T>
    class Finder {
    public:
        Finder() = default;

        explicit Finder(T *filesystem_manager) : navigator_(filesystem_manager) {};

        std::vector<std::string> FindSuitableFiles(std::string s);

    private:
        T *navigator_;
    };

} // joaquind

#include "finder.tpp"
#endif //FILESYSTEM_FINDER_H
