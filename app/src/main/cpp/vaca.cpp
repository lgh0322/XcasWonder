#include <jni.h>
#include <string>




using namespace std;

//void
//draw (cairo_t *cr, int width, int height)
//{
//    int radius;
//
//    if (width < height)
//        radius = width/2 - 4;
//    else
//        radius = height/2 - 4;
//
//    cairo_move_to (cr, width/2 + radius, height/2);
//    cairo_arc (cr, width/2, height/2, radius,
//               0.0, 2 * M_PI);
//
//    cairo_set_source_rgb (cr, 0.6, 0.8, 1.0);
//    cairo_fill_preserve (cr);
//
//    cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
//    cairo_stroke (cr);
//}

string convertToString(char *a, int size) {
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_vaca_xcas_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
//    char buf[400];
//    mp_int q, r;
//    mp_int temp;
//    mp_init(&q);
//    mp_init(&r);
//    mp_init(&temp);
//    mp_set_int(&q, 234);
//    mp_set_int(&r, 253);
//    mp_mul(&q, &r, &temp);
//    mp_todecimal(&temp, buf);


    std::string hello = "Hello from dsfvC++ ";
//    hello += convertToString(buf, sizeof(buf));
    return env->NewStringUTF(hello.c_str());
}