//
// Created by Jean-Adrien on 12/01/18.
//

#include <iostream>
#include "AssimpToJson.hpp"

extern "C" {

    int     prologue(std::string &file) {
        return  0;
    }


    int load(const char *str) {
        try {
            std::string path = str;
            size_t pos = path.find_last_of('.');
            if (pos == std::string::npos) {
                return 1;
            }
            std::string output;
            output = (path.substr(0, pos));
            output.append(".json");

            // Perform the conversion
            AssimpToJson a2jConverter(path, output);
            if (!a2jConverter.exec()) {
                output = a2jConverter.getError();
            }
        }
        catch (std::exception &e) {
            std::cerr << "[CONVERTER]  " <<  e.what() << std::endl;
        }
        return 0;
    }

    int exportFile(const char *str, int type) {

    }

}