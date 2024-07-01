#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include "IVibratorManagerService.h"

namespace android {

namespace os {

class BpVibratorManagerService : public ::android::BpInterface<IVibratorManagerService> {
public:
  explicit BpVibratorManagerService(const ::android::sp<::android::IBinder>& impl)
  : BpInterface<IVibratorManagerService>(impl) {

  }

  virtual ~BpVibratorManagerService(){

  }
  ::android::binder::Status getVibratorIds(::std::vector<int32_t>* _aidl_return) {
      Parcel data, reply;
      data.writeInterfaceToken(IVibratorManagerService::getInterfaceDescriptor());
      status_t err = remote()->transact(GET_VIBRATOR_IDS, data, &reply);
      if (err != NO_ERROR || ((err = reply.readExceptionCode()) != NO_ERROR)) {
          return ::android::binder::Status::fromExceptionCode(err);
      }
      reply.readInt32Vector(_aidl_return);
      return ::android::binder::Status::ok();
  }
  ::android::binder::Status getVibratorInfo(int32_t vibratorId, ::android::os::VibratorInfo* _aidl_return){
      return ::android::binder::Status::ok();
  };
  ::android::binder::Status isVibrating(int32_t vibratorId, bool* _aidl_return){
      return ::android::binder::Status::ok();
  };
  ::android::binder::Status registerVibratorStateListener(int32_t vibratorId, const ::android::sp<::android::os::IVibratorStateListener>& listener, bool* _aidl_return){
      return ::android::binder::Status::ok();
  }
  ::android::binder::Status unregisterVibratorStateListener(int32_t vibratorId, const ::android::sp<::android::os::IVibratorStateListener>& listener, bool* _aidl_return) {
      return ::android::binder::Status::ok();
  }
  ::android::binder::Status setAlwaysOnEffect(int32_t uid, const ::android::String16& opPkg, int32_t alwaysOnId, const ::android::os::CombinedVibration& vibration, const ::android::os::VibrationAttributes& attributes, bool* _aidl_return){
      return ::android::binder::Status::ok();
  }
  ::android::binder::Status vibrate(int32_t uid, const ::android::String16& opPkg, const ::android::os::CombinedVibration& vibration, const ::android::os::VibrationAttributes& attributes, const ::android::String16& reason, const ::android::sp<::android::IBinder>& token) override{
      return ::android::binder::Status::ok();
  }
  ::android::binder::Status cancelVibrate(int32_t usageFilter, const ::android::sp<::android::IBinder>& token) override {
      return ::android::binder::Status::ok();
  }
};  // class BpVibratorManagerService

}  // namespace os

}  // namespace android
