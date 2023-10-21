//
// Created by Joaquina Daeron on 10/21/23.
//

#ifndef FILESYSTEM_CONTROLLER_H
#define FILESYSTEM_CONTROLLER_H

#include <finder.h>

namespace joaquind {
    template<typename T>
    class Controller {
    public:
        Controller() : fsm_{}, finder_{&fsm_} {};

        std::string GetPath() { return fsm_.GetCurrentPath; }

        std::vector<std::string> GetGilesFromFile(bool with_path = true) {
            return fsm_.GetFilesNameFromFile(with_path);
        }

        void GoToTheNextDirectory(std::string s) { fsm_.IntoNextDirectory(std::move(s)); }

        void GoToThePreviousDirectory() { fsm_.IntoParentDirectory(); }

        std::vector<std::string> FindFiles(std::string s) { return finder_.FindSuitableFiles(std::move(s)); }

    private:
        T fsm_;
        Finder<T> finder_;
    };
} // joaquind


#endif //FILESYSTEM_CONTROLLER_H
