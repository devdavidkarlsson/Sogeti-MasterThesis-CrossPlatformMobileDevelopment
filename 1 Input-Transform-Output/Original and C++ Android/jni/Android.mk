#Android.mk
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := Prototype1Android
LOCAL_SRC_FILES := Prototype1Android.cpp

include $(BUILD_SHARED_LIBRARY)
