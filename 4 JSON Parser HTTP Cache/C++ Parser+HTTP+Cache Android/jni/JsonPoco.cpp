//JsonPoco.cpp
#include <jni.h>
#include <cstddef>
#include <android/log.h>
#include "Shared/RefListType.h"
#include "Shared/NetPoco.h"

extern "C"
{

#define printf(...) __android_log_print(ANDROID_LOG_DEBUG, "TAG", __VA_ARGS__);

JavaVM* gJavaVM = NULL;
jobject gJavaActivityClass;
const char* kJavActivityClassPath = "com/example/jsonpoco/MainActivity";


//------------------------------------------------------------------------
//Method declarations and method table:
long jsonCreate(JNIEnv* aEnv, jobject aObj, jstring str);
bool jsonParse(JNIEnv* aEnv, jobject aObj, jlong pointer);
void jsonStore(JNIEnv* aEnv, jobject aObj, jlong pointer);
void jsonFlush(JNIEnv* aEnv, jobject aObj, jlong pointer);
void jsonDestroy(JNIEnv* aEnv, jobject aObj, jlong pointer);

static JNINativeMethod methodTable[] = {
		{"json_create", "(Ljava/lang/String;)J", (void *) jsonCreate},
		{"json_parse", "(J)Z", (void *) jsonParse},
		{"json_store", "(J)V", (void *) jsonStore},
		{"json_flush", "(J)V", (void *) jsonFlush},
		{"json_destroy", "(J)V", (void *) jsonDestroy}
};
//------------------------------------------------------------------------
long jsonCreate(JNIEnv* aEnv, jobject aObj, jstring str){
	const char * natStr = aEnv->GetStringUTFChars(str,0);
	return (jlong)new NetPoco(natStr);
}


bool jsonParse(JNIEnv* aEnv, jobject aObj, jlong pointer){

	//JSON FROM NETWORK:
	RefListType *ref;
	int iterations = 1;
	for (int i = 0; i < iterations; i++) {

		ref = ((NetPoco*)pointer)->getRefListType();
		if (i < iterations - 1) delete ref;
	}

	//Callback to populate ArrayList in java:
	jclass cls = aEnv->FindClass("com/example/jsonpoco/MainActivity");
	jmethodID methodid = aEnv->GetMethodID(cls, "add", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;DD)V");
	std::list<RefType>::iterator it;
	for(it = ref->refs.begin(); it!= ref->refs.end();it++){
		jstring no = aEnv->NewStringUTF(it->getNo().c_str());
		jstring name = aEnv->NewStringUTF(it->getName().c_str());
		jstring url = aEnv->NewStringUTF(it->getUrl().c_str());
		aEnv->CallVoidMethod(aObj,methodid, no, name, url, it->getLocation()->getLatitude(), it->getLocation()->getLongitude());

		aEnv->DeleteLocalRef(no);
		aEnv->DeleteLocalRef(name);
		aEnv->DeleteLocalRef(url);

	}
	aEnv->DeleteLocalRef(cls);
	delete ref;
	return ((jboolean)((NetPoco*)pointer)->usingCached);
}

void jsonStore(JNIEnv* aEnv, jobject aObj, jlong pointer){
	((NetPoco*)pointer)->storeCache();
}

void jsonFlush(JNIEnv* aEnv, jobject aObj, jlong pointer){
	((NetPoco*)pointer)->clearCache();
}

void jsonDestroy(JNIEnv* aEnv, jobject aObj, jlong pointer){
	delete ((NetPoco*)pointer);
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
