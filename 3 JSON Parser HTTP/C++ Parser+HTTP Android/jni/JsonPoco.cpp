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
void jsonParse(JNIEnv* aEnv, jobject aObj, jstring str);


static JNINativeMethod methodTable[] = {
		{"json_parse", "(Ljava/lang/String;)V", (void *) jsonParse}
};
//------------------------------------------------------------------------
void jsonParse(JNIEnv* aEnv, jobject aObj, jstring str){

	//JSON FROM NETWORK:
	RefListType *ref= NetPoco::getRefListType();

	//Callback to populate ArrayList in java:
	jclass cls = aEnv->FindClass("com/example/jsonpoco/MainActivity");
	jmethodID methodid = aEnv->GetMethodID(cls, "add", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;DD)V");
    std::list<RefType>::iterator it = ref->refs.begin();
	for(int i = 0; i < ref->refs.size();i++){
	    jstring no = aEnv->NewStringUTF(it->getNo().c_str());
	    jstring name = aEnv->NewStringUTF(it->getName().c_str());
	    jstring url = aEnv->NewStringUTF(it->getUrl().c_str());
		aEnv->CallVoidMethod(aObj,methodid, no, name, url, it->getLocation()->getLatitude(), it->getLocation()->getLongitude());
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
