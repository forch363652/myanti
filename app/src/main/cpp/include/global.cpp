//
// Created by Administrator on 2023/6/6.
//

#include "global.h"


 ENCRYPTSTRING GlobalString::str_AntiCapture_proxyHost = {R"(nxyr6yyu"$Jw"!)", {6,4,5,2,8,9,7}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_proxyPort = {R"(kvyy5sxrz$Yvuz)", {3,2,5,9,7,3,6}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_System = {R"(mfzj6nbql3\&uuhr)", {3,5,4,9,7,2,1}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_getProperty = {R"(hmvTwuyfzv#)", {1,8,2,4,5,6,9}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_SiggetProperty = {R"(.Ooczb7rdsi3T"xlsi?*Tpd!c3mitj4Uxsqtj@)", {6,3,5,2,4,1,8}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_NetworkInterface = {R"(lf"j7ufv4Tn"$ptpOw"lshfin)", {2,5,6,9,8,7,1}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_getNetworkInterfaces = {R"(kfvQk""ssmLt"jvgcfk!)", {4,1,2,3,6,8,5}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_Enumeration = {R"(..Ukdxh5z#jo1Ltzvfuc!otw<)", {6,5,9,1,3,2,7}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_Collections = {R"(pd!g3$"oo4Isutkfyosw!)", {6,3,5,6,4,9,8}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_list = {R"(njvz)", {2,1,3,6,8,5,7}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_Siglist = {R"(1Rmfzi0$zlq3Mo$shwe"jxt>.Prb%g2zxqm8Guwe'Mryw@)", {9,6,3,5,4,8,1}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_ArrayList = {R"(pd!c7$!oo4Cz!h%Onu")", {6,3,5,2,8,9,7}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_size = {R"("n!h)", {9,5,1,3,6,8,7}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_Sigsize = {"..Q", {6,5,8,7,3,1,2}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_get = {"nmx", {7,8,4,3,6,5,1}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_Object = {",P.Mld%e6qbpj8SiofewD", {4,7,5,1,2,3,9}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_isUp = {"ry]s", {9,6,8,3,2,1,7}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_SigisUp = {"--`", {5,4,6,3,1,2,8}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_getInterfaceAddresses = {"ofxNt!mzgehkHllsixyl!", {8,1,4,5,6,7,8}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_List = {"1,Mqixf8xupt1QrvuB", {9,3,1,7,8,2,5}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_getName = {"miyOdul", {6,4,5,1,3,8,7}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_String = {"1/Onb!c8rdrh4U#xlrh@", {9,6,3,4,1,5,2}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_tun0 = {R"(""s2)", {8,7,5,2,1,3,6}};
 ENCRYPTSTRING GlobalString::str_AntiCapture_ppp0 = {"vty7", {6,4,9,7,5,1,3}};


 void GlobalString::teststr() {
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_proxyHost));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_proxyPort));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_System));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_getProperty));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_SiggetProperty));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_NetworkInterface));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_getNetworkInterfaces));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_Enumeration));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_Collections));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_list));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_Siglist));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_ArrayList));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_size));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_Sigsize));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_get));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_Object));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_isUp));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_SigisUp));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_getInterfaceAddresses));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_List));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_getName));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_String));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_tun0));
    LOGI("testyooha   -> %s\n", encrypt(str_AntiCapture_ppp0));
}
 const char *GlobalString::decrypt(ENCRYPTSTRING& str) {
    int len = 0;
    for (int i = 0; i < 16; i++){
        if(str.key[i] == 0){
            len = i;
            break;
        }
    }
    for(int i = 0, j = 0; str.str[j]; j++, i = (i + 1) % len){
        str.str[j] += str.key[i];
        if(str.str[j] > 122){
            str.str[j] -= 90;
        }
    }
    return str.str.c_str();
}
 const char *GlobalString::encrypt(ENCRYPTSTRING &str) {
     std::string encrypted_str = str.str;
     static std::string result;
     result = "";
     int len = 0;
     while (str.key[len]!= 0) {
         if (len >= sizeof(str.key)) {
             return nullptr;
         }
         len++;
     }
     if (len == 0) {
         return nullptr;
     }


     for (int i = 0, j = 0; j < encrypted_str.size(); j++, i = (i + 1) % len) {
         encrypted_str[j] -= str.key[i];
         if (encrypted_str[j] <= 32) {
             encrypted_str[j] += 90;
         }
     }

     result = encrypted_str;
     // 分配足够的内存来存储结果字符串
     char *newResult = new char[result.size() + 1];
     std::strcpy(newResult, result.c_str());
     return newResult;
}
//*************************************************************************************************




