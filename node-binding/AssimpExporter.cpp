//
// Created by Jean-Adrien on 15/02/18.
//

#include <iostream>
#include "assimp/Exporter.hpp"
#include "AssimpExporter.hpp"
#include "../assimp/code/AssetLib/STL/STLExporter.h"

AssimpExporter::AssimpExporter(std::string &in, std::string &out)
:   _in(in),
    _out(out)
{
    imp.SetPropertyBool(AI_CONFIG_PP_FD_REMOVE, true);
    imp.SetPropertyInteger(AI_CONFIG_PP_SBP_REMOVE, aiPrimitiveType_POINT | aiPrimitiveType_LINE);

    imp.SetPropertyFloat(AI_CONFIG_PP_GSN_MAX_SMOOTHING_ANGLE, 70.0f);
    imp.SetPropertyFloat(AI_CONFIG_PP_CT_MAX_SMOOTHING_ANGLE, 70.0f);
}

bool AssimpExporter::exec(void) {

    const aiScene* const sc = imp.ReadFile(_in, aiProcessPreset_TargetRealtime_MaxQuality);
    if (!sc) {
        _err =  "failure reading file: " + _in;
        return false;
    }

    Assimp::Exporter exp;

    if( ! _out.empty()) {
        if(aiReturn_SUCCESS != exp.Export(sc, "stl", _out)) {
            _err = "failure exporting file: " + _out + ": " + exp.GetErrorString();
            return false;
        }
    }
    else {
        const aiExportDataBlob* const blob = exp.ExportToBlob(sc,"stl");
        if(!blob) {
            _err  = "failure exporting";
            return false;
        }

        const std::string s(static_cast<char*>( blob->data), blob->size);
        std::cout << s << std::endl;
    }
    return true;
}

std::string &AssimpExporter::getError(void) {
    return _err;
}
