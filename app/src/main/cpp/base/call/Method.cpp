//
// Created by root on 9/21/24.
//

#include "Method.h"
#include "../../include/include.h"

//调用静态方法类
UNEXPORT jobject Method::callMethodObject(JNIEnv *env,
                                          jobject obj,
                                          const char* clsName,
                                          const char* methodName,
                                          const char* sig,
                                          ...){
    LOGI("in callMethodObject %s -> %s %s", clsName, methodName, sig);
    jclass cls = env->FindClass(clsName);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();//调试阶段打开此开关
        env->ExceptionClear();
        LOGE("callMethodObject FindClass %s Error", clsName);
        return NULL;
    }
    LOGI("callMethodObject FindClass %p", cls);
    jmethodID  method = env->GetMethodID(cls, methodName, sig);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();//调试阶段打开此开关
        env->ExceptionClear();
        LOGE("callMethodObject GetMethodID name:%s sig:%s Error", methodName, sig);
        return NULL;
    }
    LOGI("callMethodObject GetMethodID %p", method);
    va_list args;
    va_start(args, method);
    jobject ret = env->CallObjectMethodV(obj, method, args);
    va_end(args);

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();//调试阶段打开此开关
        env->ExceptionClear();
        LOGE("callMethodObject name:%s sig:%s Error", methodName, sig);
        return NULL;
    }
    LOGI("callMethodObject success");
    return ret;
}


UNEXPORT jobject Method::callStaticMethodObject(JNIEnv *env,
                                                const char* clsName,
                                                const char* methodName,
                                                const char* sig,
                                                ...){
    //LOGI("in callStaticMethodObject %s -> %s %s", clsName, methodName, sig);
    jclass cls = env->FindClass(clsName);
    if (cls == nullptr){
        return nullptr;
        LOGD("callStaticMethodObject cls init failed");
    };
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe(); //调试阶段打开此开关
        env->ExceptionClear();
        LOGE("callStaticMethodObject FindClass %s Error", clsName);
        return NULL;
    }
    //LOGI("callStaticMethodObject cls=%p", cls);

    jmethodID  method = env->GetStaticMethodID(cls, methodName, sig);
    if (method == nullptr){
        return nullptr;
        LOGD("callStaticMethodObject method init failed");
    };
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe(); //调试阶段打开此开关
        env->ExceptionClear();
        LOGE("callStaticMethodObject GetStaticMethodID name:%s sig:%s Error", methodName, sig);
        return NULL;
    }

    //LOGI("callStaticMethodObject method=%p", method);

    va_list args;
    va_start(args, method);
    auto  ret = env->CallStaticObjectMethodV(cls, method, args);
    va_end(args);

    //LOGI("callStaticMethodObject ret=%p", method);

    if (env->ExceptionCheck()) {
        env->ExceptionClear();
        LOGE("callStaticMethodObject name:%s sig:%s Error", methodName, sig);
        return NULL;
    }

    if (ret == nullptr){
        return nullptr;
        LOGD("callStaticMethodObject method init failed");
    };

    return ret;
}
