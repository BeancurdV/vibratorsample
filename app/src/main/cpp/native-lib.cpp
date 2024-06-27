#include <jni.h>
#include <string>
#include "android/binder_manager.h"


extern "C" JNIEXPORT jstring JNICALL
Java_com_beancurdv_vibrator_1sample_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    AIBinder *bpVibrator = AServiceManager_checkService("vibrator");

    std::string hello;
    if(bpVibrator) {
        hello = "bpVibrator ok";
    } else {
        hello = "hello";
    }

    return env->NewStringUTF(hello.c_str());
}