//
// Created by Jean-Adrien on 12/01/18.
//

#ifndef ASSIMP2JSON_PLUGIN_HPP
#define ASSIMP2JSON_PLUGIN_HPP

#include <string>
#include "../../../interfaces/IModule.hpp"

class plugin : public IModule {
public:
    plugin(const char *);

    std::string run(const char *, IJsonHandler *) ;

private:
    std::string     _path;
};


#endif //ASSIMP2JSON_PLUGIN_HPP
