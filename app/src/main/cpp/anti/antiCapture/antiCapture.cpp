//
// Created by forchan on 2024/9/27.
//

#include "antiCapture.h"
#include "../../include/include.h"
#include "../../include/global.h"
#include "../../base/call/Method.h"
#include "../../base/str/Str.h"




int antiCapture::checkproxy(JNIEnv *env) {
    // 使用局部静态变量确保初始化顺序
    // 直接调用类的静态函数来获取加密后的字符串
    const char* encrypted  = GlobalString::encrypt(GlobalString::str_AntiCapture_proxyHost);
    const char* str_AntiCapture_System = GlobalString::encrypt(GlobalString::str_AntiCapture_System);
    const char* str_AntiCapture_getProperty = GlobalString::encrypt(GlobalString::str_AntiCapture_getProperty);
    const char* str_AntiCapture_siggerProperty = GlobalString::encrypt(GlobalString::str_AntiCapture_SiggetProperty);



    jstring jsproxyhost = env->NewStringUTF(GlobalString::encrypt(GlobalString::str_AntiCapture_proxyHost));
    jstring jsproxyport = env->NewStringUTF(GlobalString::encrypt(GlobalString::str_AntiCapture_proxyPort));

    jstring proxyhost = static_cast<jstring>(Method::callStaticMethodObject(env,str_AntiCapture_System,
                                                                            str_AntiCapture_getProperty,
                                                                            str_AntiCapture_siggerProperty,
                                                                            jsproxyhost));
    jstring proxyport = static_cast<jstring>(Method::callStaticMethodObject(env,str_AntiCapture_System,
                                                                            str_AntiCapture_getProperty,
                                                                            str_AntiCapture_siggerProperty,
                                                                            jsproxyport));
    char* cproxyhost = const_cast<char *>(env->GetStringUTFChars(proxyhost, nullptr));
    char* cproxyport = const_cast<char *>(env->GetStringUTFChars(proxyport, nullptr));

    LOGI("native http.proxyHost = %s", cproxyhost);
    LOGI("native http.proxyPort = %s", cproxyport);

    if (Str::strlen(const_cast<char*>(cproxyhost))>=2 && Str::strlen(const_cast<char*>(cproxyport))>2){
        //TODO 开启代理
        env->ReleaseStringUTFChars(proxyhost,cproxyhost);
        env->ReleaseStringUTFChars(proxyport,cproxyport);
        env->DeleteLocalRef(jsproxyhost);
        env->DeleteLocalRef(jsproxyport);
        LOGI("check_proxy ======>find proxy");
        return 1;
    }

    env->ReleaseStringUTFChars(proxyhost,cproxyhost);
    env->ReleaseStringUTFChars(proxyport,cproxyport);
    env->DeleteLocalRef(jsproxyhost);
    env->DeleteLocalRef(jsproxyport);


    return 1;

}

void antiCapture::checkvpn(JNIEnv *env) {

}
