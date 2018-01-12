//
// Created by Jean-Adrien on 11/01/18.
//

#include "AssimpToJson.hpp"

extern Assimp::Exporter::ExportFormatEntry Assimp2Json_desc;

AssimpToJson::AssimpToJson(std::string &in, std::string &out): _in(in), _out(out)
{
    imp.SetPropertyBool(AI_CONFIG_PP_FD_REMOVE, true);
    imp.SetPropertyInteger(AI_CONFIG_PP_SBP_REMOVE, aiPrimitiveType_POINT | aiPrimitiveType_LINE);

    imp.SetPropertyFloat(AI_CONFIG_PP_GSN_MAX_SMOOTHING_ANGLE, 70.0f);
    imp.SetPropertyFloat(AI_CONFIG_PP_CT_MAX_SMOOTHING_ANGLE, 70.0f);
 }

bool AssimpToJson::exec(void) {

    const aiScene* const sc = imp.ReadFile(_in, aiProcessPreset_TargetRealtime_MaxQuality);
    if (!sc) {
        _err =  "failure reading file: " + _in;
        return false;
    }

    Assimp::Exporter exp;
    exp.RegisterExporter(Assimp2Json_desc);

    if( ! _out.empty()) {
        if(aiReturn_SUCCESS != exp.Export(sc, "assimp.json", _out)) {
            _err = "failure exporting file: " + _out + ": " + exp.GetErrorString();
            return false;
        }
    }
    else {
        const aiExportDataBlob* const blob = exp.ExportToBlob(sc,"assimp.json");
        if(!blob) {
            _err  = "failure exporting";
            return false;
        }

        const std::string s(static_cast<char*>( blob->data), blob->size);
        std::cout << s << std::endl;
    }
   return true;
}

std::string &AssimpToJson::getError(void) {
    return _err;
}
