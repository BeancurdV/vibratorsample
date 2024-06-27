#include <jni.h>
#include <android/binder_ibinder.h>


extern "C" JNIEXPORT jstring JNICALL
Java_com_beancurdv_vibrator_1sample_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}