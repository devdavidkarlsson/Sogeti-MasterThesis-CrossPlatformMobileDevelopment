//Prototype1Android.cpp
#include <jni.h>
#include "CppTransform.cpp"
#include <android/log.h>

#ifndef _Included_com_example_prototype1android_MainActivity
#define _Included_com_example_prototype1android_MainActivity
#ifdef __cplusplus
extern "C" {
#endif

namespace com_example_prototype1android{
	//static jstring transform(JNIEnv *, jclass, jstring);

	static jstring transform(JNIEnv * env, jclass jc, jstring input){

		const char *nativeString = (env)->GetStringUTFChars(input,0);
		char* res = NativeCpp::transform(nativeString);
		(env)->ReleaseStringUTFChars(input, nativeString);
		return env->NewStringUTF(res);

		//return input;
	}


static JNINativeMethod method_table[]{
			{"transform", "(Ljava/lang/String;)Ljava/lang/String;", (void *) transform}
			//{"transform", "(J)J", (void *) transform}
			//{"JavaMethodName", "(JavaVMTypeSignatureInput)JavaVMTypeSignatureOutput", (createPointerToCppMethod) CppMethodName}
	};

jint JNI_OnLoad(JavaVM* aVm, void* aReserved)
{
JavaVM* gJavaVM = NULL;
jobject gJavaActivityClass;
 // cache java VM
 gJavaVM = aVm;

 JNIEnv* env;
 if (aVm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK)
 {
  //LOGE("Failed to get the environment");
  return -1;
 }

 // Get SBCEngine activity class
 jclass activityClass = env->FindClass("com/example/prototype1android/MainActivity");
 if (!activityClass)
 {
  //LOGE("failed to get %s class reference", "com/example/prototype1android/MainActivity");
  return -1;
 }
 gJavaActivityClass = env->NewGlobalRef(activityClass);

 // Register methods with env->RegisterNatives.
 env->RegisterNatives(activityClass, method_table, sizeof(method_table) / sizeof(method_table[0]));

 return JNI_VERSION_1_6;
}

} // extern "C"


#ifdef __cplusplus
}
#endif
#endif

