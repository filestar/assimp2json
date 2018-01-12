//
// Created by Jean-Adrien on 11/01/18.
//

#pragma once

#include <assimp/Importer.hpp>
#include <assimp/Exporter.hpp>

#include <assimp/version.h>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include <iostream>

#include "../assimp2json/version.h"

class AssimpToJson {
public:
    AssimpToJson(std::string &in, std::string &out);

    bool                  exec(void);
    std::string     &getError(void);

private:
    std::string               _err;
    std::string               &_in;
    std::string               &_out;
    Assimp::Importer    imp;
};
