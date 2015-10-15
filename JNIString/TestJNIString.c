#include <jni.h>
#include <stdio.h>
#include "TestJNIString.h"

JNIEXPORT jstring JNICALL Java_TestJNIString_sayHello(JNIEnv *env, jobject thisObj, jstring inJNIStr) {
	
	//Convert JNI String (jstring) into C-String (char*)
	const char * inCStr = (*env)->GetStringUTFChars(env, inJNIStr, NULL);
	if (NULL == inCStr) return NULL;

	//Perform intended operations
	printf("In C, the received string is: %s\n", inCStr);
	(*env)->ReleaseStringUTFChars(env, inJNIStr, inCStr);

	//Prompt user for C-string
	char outCStr[128];
	printf("Enter a String: ");
	scanf("%s", outCStr);

	//Convert C-string to JNI String and return

	return (*env)->NewStringUTF(env, outCStr);


}