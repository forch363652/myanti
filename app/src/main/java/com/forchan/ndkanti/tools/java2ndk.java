package com.forchan.ndkanti.tools;

import android.content.Context;
import android.util.Log;

public class java2ndk {
    public static final String tag = "forchan";

    //开始加载本地库
    static {
        System.loadLibrary("forchan");
    }

    public static void  init(){
        Log.d("tag", "instance initializer:frochan开始初始化");
    }

    public static void  check(String val, Context context){
        native_check(val,context);
    }

    private static native void native_check(String val,Context context);


}
