//
// Created by root on 9/21/24.
//

#include "Method.h"
#include "../../include/include.h"

//调用静态方法类
UNEXPORT jobject Method::callstaticMethodObject(JNIEnv *env, const char *clsName, const char *methodName,
                                       const char *sig, ...) {
    //找到对应的classname
    jclass cls = env->FindClass(clsName);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();   //调试阶段打开此开关
        env->ExceptionClear();
        LOGE("callStaticMethodObject FindClass %s Error", clsName);
        return NULL;
    }
    LOGD("callStaticMethodObject cls=%p", cls);
    jmethodID method  = env->GetStaticMethodID(cls,methodName,sig);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();   //调试阶段打开此开关
        env->ExceptionClear();
        LOGE("callStaticMethodObject GetStaticMethodID name:%s sig:%s Error", methodName, sig);
        return NULL;
    }

// va_start宏的第一个参数是va_list变量，第二个参数是最后一个已知参数之前的参数
    va_list args;
    //设置可变参数的最后一个参数
    va_start(args,method);
    jobject objret = env->CallStaticObjectMethodV(cls,method,args);
    va_end(args);

    if(env->ExceptionCheck()){
        env->ExceptionClear();
        LOGE("callstaticMethodObject name：%s Error",methodName,sig);
        return NULL;
    }
    if (objret == nullptr){
        LOGE("CallStaticObjectMethodV","返回值为空");
        return NULL;
    }
    return objret;
}

UNEXPORT jobject Method::callMethodObject(JNIEnv *env, jobject obj,const char *clsName, const char *methodName, const char *sig,
                         ...) {
    LOGD("callMethodObject &s --> %s %s",clsName,methodName,sig);
    jclass cls = env->FindClass(clsName);
    //调试开关
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();   //调试阶段打开此开关
        env->ExceptionClear();
        LOGE("callStaticMethodObject FindClass %s Error", clsName);
        return NULL;
    }
    LOGD("callMethodObject FindClass %p",cls);
    jmethodID method = env->GetMethodID(cls,methodName,sig);
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
    if (env->ExceptionCheck()){
        env->ExceptionDescribe();
        LOGE("callMethodObject %s --> %s Error",methodName,sig);
        return NULL;
    }
    LOGI("callMethodObject success");
    if (ret ==NULL){
        LOGE("callMethodObject %s --> %s Error",methodName,sig);
    }
    return ret;
}
