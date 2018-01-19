//
// Created by Jean-Adrien on 12/01/18.
//

#include "plugin.hpp"

extern "C" {

    int     prologue(std::string &file) {
        return  0;
    }

    IModule *load(const char *str) {
        return new plugin(str);
    }
}