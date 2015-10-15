#include <jni.h>
#include <stdio.h>
#include "TestJNIPrimitiveArray.h"

JNIEXPORT jdoubleArray JNICALL Java_TestJNIPrimitiveArray_sumAndAverage (JNIEnv *env, jobject thisObj, jintArray inJNIArray) {
	

	//Convert JNI jintarray to C's jint[]
	jint *inCArray = (*env)->GetIntArrayElements(env, inJNIArray, NULL);
	if (NULL == inCArray) return NULL;
	jsize length = (*env)->GetArrayLength(env, inJNIArray);

	//Perform operation
	jint sum = 0;
	int i;
	for (i = 0; i< length; i++){
		sum += inCArray[i];
	}
	
	jdouble average = (jdouble)sum / length;
	(*env)->ReleaseIntArrayElements(env, inJNIArray, inCArray, 0); //releases resources

	jdouble outCArray[] = {sum, average};

	//Convert C's native jdouble[] to JNI jdoublearray

	jdoubleArray outJNIArray = (*env)->NewDoubleArray(env, 2);
	if (NULL == outJNIArray) return NULL;
	(*env)->SetDoubleArrayRegion(env, outJNIArray, 0, 2, outCArray);
	return outJNIArray;

}