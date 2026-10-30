LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := skzygisk_probe
LOCAL_SRC_FILES := ../probe.cpp
SKROOT_KIT := $(LOCAL_PATH)/../../sdk
LOCAL_C_INCLUDES := $(SKROOT_KIT)/include
LOCAL_CPPFLAGS := -std=c++20 -fPIC -fvisibility=hidden -ffunction-sections -fdata-sections
LOCAL_LDFLAGS := -Wl,--gc-sections -Wl,-z,defs -Wl,-z,max-page-size=16384
LOCAL_STATIC_LIBRARIES := skroot_kit
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := skroot_kit
LOCAL_SRC_FILES := ../../sdk/lib/libkernel_module_kit_static.a
include $(PREBUILT_STATIC_LIBRARY)
