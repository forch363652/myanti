#include <jni.h>
#include <string>
#include "include/include.h"
#include "base/Env/Env.h"

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
void * check(JNIEnv* env,jclass cls,jstring key,jobject thiz){
    LOGD("forchan","已经进入了check函数");



}



UNEXPORT void init_env(JNIEnv *env) {
    //初始化globalEnv
    LOGD("forchan","初始化环境ing");
    globalEnv = (ENV_APP*) malloc(sizeof (ENV_APP));
    Env *app = new Env(env,globalEnv);

}

jint JNI_OnLoad(JavaVM* vm, void* reserved){
    LOGD("forchan","已经进入了JNI_ONLOAD");
    globalJvm =vm;
    JNIEnv *env = nullptr;
    //获取env
    globalJvm->GetEnv((void**)&env,JNI_VERSION_1_6);

    //初始化环境，一定要在JNI_ONLOAD之前执行
    init_env(env);
    LOGI("JNI_OnLoad ------------- get cpu -> %s", globalEnv->cpu);
    LOGI("JNI_OnLoad ------------- get pkgname -> %s", globalEnv->pkgname);
    //动态注册JNI函数
    jclass clsForchan = env->FindClass("com/forchan/ndkanti/tools/java2ndk");
    if (env->ExceptionCheck()) {   //检测异常
        env->ExceptionClear();     //清除异常
        env->ExceptionDescribe();  //显示异常信息
        LOGE("JNI_OnLoad FindClass error");
        return JNI_ERR;
    }


    JNINativeMethod nativemethods[]={
            {"native_check","(Ljava/lang/String;Ljava/lang/Object;)V",(void*)check}
    };
    if (env->RegisterNatives(clsForchan,nativemethods, NELEM(nativemethods))<0){
        LOGE("JNI_OnLoad RegisterNatives error");
        LOGI("JNI_OnLoad over");
        return JNI_VERSION_1_6;
    }




};




