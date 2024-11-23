//
// Created by root on 9/21/24.
//

#ifndef NDKANTI_ENV_H
#define NDKANTI_ENV_H
#pragma
#include "../../include/include.h"
#include "../call/Method.h"
class Env {
private:
    JNIEnv *mEnv;
public:
    //构造函数
    Env(JNIEnv* env,ENV_APP* env_p){
        LOGD("forchan","Env开始初始化");
        mEnv = env;
        getEnv(env_p);
    }
    void getEnv(ENV_APP* env_p);
    /**
    * 读取maps文件的标志
    * 任何函数若要读取maps文件需先设置此值为true，读取完毕再设置为false，否则会被检测为进程读取maps，导致程序闪退
    */
    static bool thread_share_switch_maps;
    static bool thread_share_switch_mem;
    static bool thread_share_switch_pagemap;
private:
    void setCPU(char **cpu);
    void setPKG(char **pkg);
    jobject getApplication();

};


#endif //NDKANTI_ENV_H
