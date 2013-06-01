//JsonPoco.cpp
#include <jni.h>
#include <cstddef>
#include <android/log.h>
#include "Shared/RefListType.h"

extern "C"
{

#define printf(...) __android_log_print(ANDROID_LOG_DEBUG, "TAG", __VA_ARGS__);

JavaVM* gJavaVM = NULL;
jobject gJavaActivityClass;
const char* kJavActivityClassPath = "com/example/jsonpoco/MainActivity";

//------------------------------------------------------------------------
//Method declarations and method table:
void jsonParse(JNIEnv* aEnv, jobject aObj, jstring str);


static JNINativeMethod methodTable[] = {
		{"json_parse", "(Ljava/lang/String;)V", (void *) jsonParse}
};
//------------------------------------------------------------------------
void jsonParse(JNIEnv* aEnv, jobject aObj, jstring str){


	const char * natStr = aEnv->GetStringUTFChars(str,0);
	RefListType* ref = new RefListType(natStr);
	aEnv->ReleaseStringUTFChars(str,natStr);
	for(int i = 0; i<100; i++){
		printf(ref->deserialize().c_str());
	}

	//Callback to populate ArrayList in java:
	jclass cls = aEnv->FindClass("com/example/jsonpoco/MainActivity");
	jmethodID methodid = aEnv->GetMethodID(cls, "add", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;DD)V");
    std::list<RefType>::iterator it = ref->refs.begin();
	for(int i = 0; i < ref->refs.size()/100;i++){
	    jstring storeNo = aEnv->NewStringUTF(it->getNo().c_str());
	    jstring storeName = aEnv->NewStringUTF(it->getName().c_str());
	    jstring storeUrl = aEnv->NewStringUTF(it->getUrl().c_str());
		aEnv->CallVoidMethod(aObj,methodid, storeNo, storeName, storeUrl, it->getLocation()->getLatitude(), it->getLocation()->getLongitude());
		std::advance(it, 1);
	}
	delete ref;

}




//------------------------------------------------------------------------
jint JNI_OnLoad(JavaVM* aVm, void* aReserved)
{
	// cache java VM
	gJavaVM = aVm;

	JNIEnv* env;
	if (aVm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK)
	{
		//LOGE("Failed to get the environment");
		return -1;
	}

	// Get SBCEngine activity class
	jclass activityClass = env->FindClass(kJavActivityClassPath);
	if (!activityClass)
	{
		//LOGE("failed to get %s class reference", kJavActivityClassPath);
		return -1;
	}
	gJavaActivityClass = env->NewGlobalRef(activityClass);

	// Register methods with env->RegisterNatives.
	env->RegisterNatives(activityClass, methodTable, sizeof(methodTable) / sizeof(methodTable[0]));

	return JNI_VERSION_1_6;

}
} // extern "C"
