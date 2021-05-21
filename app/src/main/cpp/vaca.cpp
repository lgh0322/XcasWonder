#include <jni.h>
#include <string>
#include "gen.h"



using namespace std;

giac::context *contextptr;
extern "C"
JNIEXPORT jstring JNICALL
Java_com_vaca_xcas_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz, jstring operation) {
    const char *compute = env->GetStringUTFChars(operation, 0);

    try {

        giac::gen g(compute, contextptr);

        g = eval(g, contextptr);

        return env->NewStringUTF(g.print().c_str());
    }
    catch (std::runtime_error &err) {
        //std::string error = std::string("Error:") + std::string(err.what());
        //return env->NewStringUTF(error.c_str());
        env->ThrowNew(env->FindClass("java/lang/Exception"), err.what());
    }
}