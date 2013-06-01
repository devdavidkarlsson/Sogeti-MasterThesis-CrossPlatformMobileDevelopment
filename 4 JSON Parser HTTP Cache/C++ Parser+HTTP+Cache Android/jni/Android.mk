LOCAL_PATH := $(call my-dir)
ROOT_PATH := $(LOCAL_PATH)

include $(call all-subdir-makefiles)
include $(CLEAR_VARS)

LOCAL_PATH = $(ROOT_PATH)




include $(CLEAR_VARS)
#LOCAL_MODULE_TAGS    := eng
LOCAL_ARM_MODE       := arm
APP_ABI := armeabi armeabi-v7a
LOCAL_MODULE    := JsonPoco # Your own library.
LOCAL_SRC_FILES := JsonPoco.cpp \
Shared/RefListType.cpp \
Shared/RefType.cpp \
Shared/LocationType.cpp \
Shared/NetPoco.cpp \
Shared/FileSystemTest.cpp \


 # Your own library source.
ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
LOCAL_STATIC_LIBRARIES := PocoJSONArm7 \
PocoNetArm7 \
PocoFoundationArm7
else
LOCAL_STATIC_LIBRARIES := PocoJSONArm \
PocoNetArm \
PocoFoundationArm

endif
LOCAL_LDLIBS     := -llog
LOCAL_CFLAGS     := -O3 -DPOCO_ANDROID -DPOCO_NO_FPENVIRONMENT -DPOCO_NO_WSTRING -DPOCO_NO_SHAREDMEMORY
LOCAL_CPPFLAGS   := -frtti -fexceptions -O3

include $(BUILD_SHARED_LIBRARY)




