#include <jni.h>
#include <string>
#include "include/include.h"
#include "base/Env/Env.h"
#include "anti/antiCapture/antiCapture.h"
#include "include/global.h"


std::string passValue = "you pass";


void init_env(JNIEnv env);
#define NELEM(...) sizeof(__VA_ARGS__) / sizeof(JNINativeMethod)

extern "C" JNIEXPORT jstring JNICALL
Java_com_forchan_ndkanti_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_forchan_ndkanti_tools_java2ndk_native_1check(JNIEnv *env, jclass clazz, jstring val,
                                                      jobject context) {



}
void  check(JNIEnv* env,jclass cls,jstring key,jobject thiz){
    LOGD("forchan","已经进入了check函数");
    LOGD("forchan","已经进入了check函数");


}

 jstring getPassvalue(JNIEnv *env,jclass thiz){
    return env->NewStringUTF(passValue.c_str());
}




 void init_env(JNIEnv *env) {
    //初始化globalEnv
    LOGD("forchan","初始化环境ing");
    globalEnv = (ENV_APP*) malloc(sizeof (ENV_APP));
    Env *app = new Env(env,globalEnv);

}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
    int nret = 0;
    LOGD("forchan","已经进入了JNI_ONLOAD");
    globalJvm =vm;
    JNIEnv *env = nullptr;
    //获取env
    globalJvm->GetEnv((void**)&env,JNI_VERSION_1_6);

    //初始化环境，一定要在JNI_ONLOAD之前执行
    init_env(env);
    LOGI("JNI_OnLoad ------------- get cpu -> %s", globalEnv->cpu);
    LOGI("JNI_OnLoad ------------- get pkgname -> %s", globalEnv->pkgname);
    const char *encrypted = GlobalString::encrypt(GlobalString::str_AntiCapture_proxyHost);
    LOGD("打印出来的值:%s",encrypted);
    //开始检查是否开启了代理
    nret = antiCapture::checkproxy(env);
    if (nret == 0){
        LOGE("警告=====>正在开启代理");
    }
    LOGD("代理并没有开启");
    LOGD("代理并没有开启");

    LOGE("警告=====>正在开启代理");

    //动态注册JNI函数
    jclass clsForchan = env->FindClass("com/forchan/ndkanti/tools/java2ndk");
    if (env->ExceptionCheck()) {   //检测异常
        env->ExceptionClear();     //清除异常
        env->ExceptionDescribe();  //显示异常信息
        LOGE("JNI_OnLoad FindClass error");
        return JNI_ERR;
    }

    LOGD("JNI_OnLoad clsForchan overwork");

    JNINativeMethod nativemethods[]={
            {"native_check", "(Ljava/lang/String;Landroid/content/Context;)V",(void*)check},
            {"native_getPassValue", "()Ljava/lang/String;",(void*)getPassvalue}
    };
    if (env->RegisterNatives(clsForchan,nativemethods, NELEM(nativemethods))<0){
        LOGE("JNI_OnLoad RegisterNatives error");
        LOGI("JNI_OnLoad over");
        return JNI_VERSION_1_6;
    }
    LOGD("JNI_OnLoad nativemethods overwork");


    return JNI_VERSION_1_6;
};




