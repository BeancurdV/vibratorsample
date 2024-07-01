#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IVibratorStateListener.h>

namespace android {

namespace os {

class BpVibratorStateListener : public ::android::BpInterface<IVibratorStateListener> {
public:
  explicit BpVibratorStateListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpVibratorStateListener() = default;
  ::android::binder::Status onVibrating(bool vibrating) override;
};  // class BpVibratorStateListener

}  // namespace os

}  // namespace android
