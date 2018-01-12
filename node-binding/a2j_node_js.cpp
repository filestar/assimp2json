//
// Created by Jean-Adrien on 11/01/18.
//

#include <node/node.h>
#include "AssimpToJson.hpp"

//  I do this because writing code giving namespace with v8 make it really difficult to read and error friendly
using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

/**
 * @name     import     import a 3D representation to a JSON file Format
 * @param   args        the pathFile to be converted
 * @return    the path file to the converted file with extension (.json)
 */

void importConverter(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() != 1) {
        // Throw an Error that is passed back to JavaScript
        isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    // Check the argument types
    if (!args[0]->IsString() ) {
        isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Wrong arguments")));
        return;
    }

    // Perform extension change to ".json"
    String::Utf8Value   param(args[0]);
    std::string pathfile = *param;
    size_t pos = pathfile.find_last_of('.');
    if (pos == std::string::npos) {
        isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Can\'t find the file extention")));
        return;
    }
    std::string  output;
    output.operator=(pathfile.substr(0, pos));
    output.append(".json");

    // Perform the conversion
    AssimpToJson    a2jConverter(pathfile, output);
    if ( ! a2jConverter.exec()) {
        output = a2jConverter.getError();
    }

    // Set the return value (using the passed in
    // FunctionCallbackInfo<Value>&)
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, output.c_str()));
}

void Init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "importConverter", importConverter);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

