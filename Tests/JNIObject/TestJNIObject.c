#include <jni.h>
#include <stdio.h>
#include "TestJNIObject.h"


JNIEXPORT void JNICALL Java_TestJNIObject_modifyInstanceVariable (JNIEnv *env, jobject thisObj) {
	
	//Get a reference to this object's class
	jclass thisClass = (*env)->GetObjectClass(env, thisObj);

	//int
	//Get the Field ID of the instance variable number
	jfieldID fidNumber = (*env)->GetFieldID(env, thisClass, "number", "I");
	if (NULL == fidNumber) return;

	//Get the int based on Field ID
	jint number = (*env)->GetIntField(env, thisObj, fidNumber);
	printf("In C, the int is %d\n", number);

	//Change the variable
	number = 1256;
	(*env)->SetIntField(env, thisObj, fidNumber, number);

	//Get Field ID of message
	jfieldID fidMessage = (*env)->GetFieldID(env, thisClass, "message", "Ljava/lang/String;");
	if (NULL==fidMessage) return;

	//Get string from field ID
	jstring message = (*env)->GetObjectField(env, thisObj, fidMessage);

	//Create a Cstring with the JNI String
	const char *cStr = (*env)->GetStringUTFChars(env, message, NULL);
	if(NULL== cStr) return;

	printf("In C, the string is %s\n", cStr);
	(*env)->ReleaseStringUTFChars(env, message, cStr);

	//Create a new Cstring and assign to the JNI string
	message = (*env)->NewStringUTF(env, "Hello from C");
	if (NULL==message) return;

	//modify the instance variables
	(*env)->SetObjectField(env, thisObj, fidMessage, message);
	

}