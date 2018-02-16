//
// Created by Jean-Adrien on 15/02/18.
//

#pragma once

#include <assimp/Importer.hpp>
#include <assimp/Exporter.hpp>

#include <assimp/version.h>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include <string>

class AssimpExporter {
public:
    AssimpExporter(std::string  &in, std::string &out);

    bool                  exec(void);
    std::string     &getError(void);

private:
    std::string               _err;
    std::string               &_in;
    std::string               &_out;
    Assimp::Importer    imp;
};