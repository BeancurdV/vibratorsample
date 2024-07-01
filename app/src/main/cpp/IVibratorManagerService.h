#pragma once

#include "VibrationAttributes.h"
#include "VibratorInfo.h"
#include "IVibratorStateListener.h"
#include "CombinedVibration.h"
#include "VibratorInfo.h"
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace os {

class IVibratorManagerService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(VibratorManagerService)
  virtual ::android::binder::Status getVibratorIds(::std::vector<int32_t>* _aidl_return) = 0;
  virtual ::android::binder::Status getVibratorInfo(int32_t vibratorId, ::android::os::VibratorInfo* _aidl_return) = 0;
  virtual ::android::binder::Status isVibrating(int32_t vibratorId, bool* _aidl_return) = 0;
  virtual ::android::binder::Status registerVibratorStateListener(int32_t vibratorId, const ::android::sp<::android::os::IVibratorStateListener>& listener, bool* _aidl_return) = 0;
  virtual ::android::binder::Status unregisterVibratorStateListener(int32_t vibratorId, const ::android::sp<::android::os::IVibratorStateListener>& listener, bool* _aidl_return) = 0;
  virtual ::android::binder::Status setAlwaysOnEffect(int32_t uid, const ::android::String16& opPkg, int32_t alwaysOnId, const ::android::os::CombinedVibration& vibration, const ::android::os::VibrationAttributes& attributes, bool* _aidl_return) = 0;
  virtual ::android::binder::Status vibrate(int32_t uid, const ::android::String16& opPkg, const ::android::os::CombinedVibration& vibration, const ::android::os::VibrationAttributes& attributes, const ::android::String16& reason, const ::android::sp<::android::IBinder>& token) = 0;
  virtual ::android::binder::Status cancelVibrate(int32_t usageFilter, const ::android::sp<::android::IBinder>& token) = 0;
};  // class IVibratorManagerService

class IVibratorManagerServiceDefault : public IVibratorManagerService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getVibratorIds(::std::vector<int32_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getVibratorInfo(int32_t, ::android::os::VibratorInfo*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isVibrating(int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerVibratorStateListener(int32_t, const ::android::sp<::android::os::IVibratorStateListener>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unregisterVibratorStateListener(int32_t, const ::android::sp<::android::os::IVibratorStateListener>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAlwaysOnEffect(int32_t, const ::android::String16&, int32_t, const ::android::os::CombinedVibration&, const ::android::os::VibrationAttributes&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status vibrate(int32_t, const ::android::String16&, const ::android::os::CombinedVibration&, const ::android::os::VibrationAttributes&, const ::android::String16&, const ::android::sp<::android::IBinder>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status cancelVibrate(int32_t, const ::android::sp<::android::IBinder>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IVibratorManagerServiceDefault

}  // namespace os

}  // namespace android
