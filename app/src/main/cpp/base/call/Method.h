//
// Created by root on 9/21/24.
//

#ifndef NDKANTI_METHOD_H
#define NDKANTI_METHOD_H
#pragma
#include <jni.h>

class Method {
public:
//    static callmethodvoid
    static jobject callstaticMethodObject(
                                JNIEnv* env,
                                const char* clsName,
                                const char* methodName,
                                const char* sig,
                                ...
    );
    static jobject callMethodObject(
                                JNIEnv* env,
                                jobject obj,
                                const char* clsName,
                                const char* methodName,
                                const char* sig,
                                ...
            );



};


#endif //NDKANTI_METHOD_H
