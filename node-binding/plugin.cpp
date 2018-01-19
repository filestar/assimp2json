//
// Created by Jean-Adrien on 12/01/18.
//

#include "AssimpToJson.hpp"
#include "plugin.hpp"

plugin::plugin(const char *path) : _path(path)
{}

std::string plugin::run(const char *a, IJsonHandler *b) {
    size_t pos = _path.find_last_of('.');
    if (pos == std::string::npos) {
        return std::string ();
    }
    std::string  output;
    output=(_path.substr(0, pos));
    output.append(".json");

    // Perform the conversion
    AssimpToJson    a2jConverter(_path, output);
    if ( ! a2jConverter.exec()) {
        output = a2jConverter.getError();
    }
    return output;
}
