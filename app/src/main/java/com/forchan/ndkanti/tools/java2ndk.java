package com.forchan.ndkanti.tools;

import android.content.Context;
import android.util.Log;

public class java2ndk {
    public static final String tag = "forchan";

    //开始加载本地库
    static {
        System.loadLibrary("ndkanti");
    }

    public static void  init(){
        Log.d("tag", "instance initializer:frochan开始初始化");
    }

    public static void  check(String val, Context context){
        Log.d("check:","c");
        native_check(val,context);
    }

    public static String md5(String input){
        return native_md5(input);
    }


    private static native void native_check(String val,Context context);
    public static native String native_getPassValue();

    public static native String native_md5(String str);


}
