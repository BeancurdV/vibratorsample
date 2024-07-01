#pragma once

#include <binder/IInterface.h>
#include <android/os/IVibratorStateListener.h>

namespace android {

namespace os {

class BnVibratorStateListener : public ::android::BnInterface<IVibratorStateListener> {
public:
  static constexpr uint32_t TRANSACTION_onVibrating = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnVibratorStateListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnVibratorStateListener

}  // namespace os

}  // namespace android
