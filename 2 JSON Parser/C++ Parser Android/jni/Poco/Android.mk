#ARM7
#Include POCO JSON LIBRARIES: libPocoJSON.a using the headers in ../JSON/include
include $(CLEAR_VARS)
APP_ABI := armeabi armeabi-v7a

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
#LOCAL_ARM_MODE := arm
LOCAL_MODULE := PocoJSONArm7
LOCAL_SRC_FILES := Poco/arm7/libPocoJSON.a 
LOCAL_EXPORT_C_INCLUDES :=/Users/exjobb/poco-1.5.1-all/JSON/include
LOCAL_EXPORT_CFLAGS := -DFOO=1 -fpermissive -O3
LOCAL_EXPORT_LDLIBS := -llog
include $(PREBUILT_STATIC_LIBRARY)


#Include POCO JSON LIBRARIES: libPocoFoundation.a using the headers in ../Foundation/include

include $(CLEAR_VARS)
#LOCAL_ARM_MODE := arm
LOCAL_MODULE := PocoFoundationArm7
LOCAL_SRC_FILES := Poco/arm7/libPocoFoundation.a
LOCAL_EXPORT_C_INCLUDES := /Users/exjobb/poco-1.5.1-all/Foundation/include
LOCAL_EXPORT_CFLAGS := -DFOO=1 -fpermissive -O3
LOCAL_EXPORT_LDLIBS := -llog
include $(PREBUILT_STATIC_LIBRARY)

else
#ARM:
#Include POCO JSON LIBRARIES: libPocoJSON.a using the headers in ../JSON/include
include $(CLEAR_VARS)
#LOCAL_ARM_MODE := arm
LOCAL_MODULE := PocoJSONArm
LOCAL_SRC_FILES := Poco/arm/libPocoJSON.a 
LOCAL_EXPORT_C_INCLUDES :=/Users/exjobb/poco-1.5.1-all/JSON/include
LOCAL_EXPORT_CFLAGS := -DFOO=1 -fpermissive -O3
LOCAL_EXPORT_LDLIBS := -llog
include $(PREBUILT_STATIC_LIBRARY)


#Include POCO JSON LIBRARIES: libPocoFoundation.a using the headers in ../Foundation/include

include $(CLEAR_VARS)
#LOCAL_ARM_MODE := arm
LOCAL_MODULE := PocoFoundationArm
LOCAL_SRC_FILES := Poco/arm/libPocoFoundation.a
LOCAL_EXPORT_C_INCLUDES := /Users/exjobb/poco-1.5.1-all/Foundation/include
LOCAL_EXPORT_CFLAGS := -DFOO=1 -fpermissive -O3
LOCAL_EXPORT_LDLIBS := -llog
include $(PREBUILT_STATIC_LIBRARY)

endif