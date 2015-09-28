#include <jni.h>
#include <stdio.h>
#include "TestJNI.h"

JNIEXPORT void JNICALL Java_TestJNI_helloWorld(JNIEnv *env, jobject thisObj){
	printf("Hello World!\n");
	return;
}