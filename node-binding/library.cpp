//
// Created by Jean-Adrien on 12/01/18.
//

#include <iostream>
#include "AssimpToJson.hpp"
#include "AssimpExporter.hpp"

extern "C" {

    int     prologue(std::string &file) {
        return  0;
    }


    int loader(const char *str) {
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
                throw std::logic_error(output);
            }
        }
        catch (std::exception &e) {
            std::cerr << "[CONVERTER]  " <<  e.what() << std::endl;
            return 1;
        }
        return 0;
    }

    int exporter(const char *str, const char *type) {
        try {
            std::string path = str;
            size_t pos = path.find_last_of('.');
            if (pos == std::string::npos) {
                return 1;
            }
            std::string output;
            output = (path.substr(0, pos));
            output.append(".");
            output.append(type);
            // Perform the conversion
            AssimpExporter Aexporter(path, output);
            if (!Aexporter.exec()) {
                output = Aexporter.getError();
                throw std::logic_error(output);
            }
        }
        catch (std::exception &e) {
            std::cerr << "[EXPORTER]  " <<  e.what() << std::endl;
            return 1;
        }
        return 0;
    }

}