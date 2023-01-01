#include <napi.h>

#include "trash.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("trash", Napi::Function::New(env, Trash));
    return exports;
}

NODE_API_MODULE(trash, Init)
