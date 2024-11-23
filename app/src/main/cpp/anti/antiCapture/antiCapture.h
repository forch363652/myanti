//
// Created by forchan on 2024/9/27.
//

#ifndef NDKANTI_ANTICAPTURE_H
#define NDKANTI_ANTICAPTURE_H

#pragma onceonce
#include "../../include/include.h"


class antiCapture {
public:
//    检查是否开启了网络代理
        static int  checkproxy(JNIEnv *env);

        static void checkvpn(JNIEnv* env);


};


#endif //NDKANTI_ANTICAPTURE_H
