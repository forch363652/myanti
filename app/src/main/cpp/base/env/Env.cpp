//
// Created by root on 9/21/24.
//

#include "Env.h"
#include <jni.h>
#include <string>

bool Env::thread_share_switch_maps= false;
bool Env::thread_share_switch_mem = false;
bool Env::thread_share_switch_pagemap = false;

UNEXPORT  void Env::getEnv(ENV_APP* env_p) {
    setCPU(&env_p->cpu);
    setPKG(&env_p->pkgname);
}


UNEXPORT void Env::setCPU(char **cpu) {
    jstring jsArch = mEnv->NewStringUTF("os.arch");
    jstring arch = static_cast<jstring>(Method::callstaticMethodObject(mEnv,"java/lang/System",
                                                                       "getProperty",
                                                                       "(Ljava/lang/String;)Ljava/lang/String;",
                                                                       jsArch
                                                                       ));
    char *cArch = "";
    if (arch!= nullptr){
        //把arch转化为char*类型
        cArch = const_cast<char*>(mEnv->GetStringUTFChars(arch,NULL));
        LOGD("setCPU os.arch = %s",cArch);
    }
    *cpu  = (char*) malloc(strlen(cArch)+1);
    memcpy(*cpu,cArch, strlen(cArch)+1);
    mEnv->DeleteLocalRef(jsArch);
    if (arch !=NULL){
        mEnv->ReleaseStringUTFChars(arch,cArch);
    }
}

UNEXPORT void Env::setPKG(char **pkg) {
    jobject application = getApplication();
    jstring pkgname = static_cast<jstring>(Method::callMethodObject(mEnv,application,
                                                                    "android/app/Application",
                                                                    "getPackageName",
                                                                    "()Ljava/lang/String;"));
    char *cPkg = const_cast<char *>(mEnv->GetStringUTFChars(pkgname,NULL));
    *pkg = (char*) malloc(strlen(cPkg+1));
    memcpy(*pkg,cPkg, strlen(cPkg+1));
    mEnv->ReleaseStringUTFChars(pkgname,cPkg);
}
UNEXPORT jobject Env::getApplication(){
    return Method::callstaticMethodObject(mEnv,
                                          "android/app/ActivityThread",
                                          "currentApplication",
                                          "()Landroid/app/Application;"
                                          );
}