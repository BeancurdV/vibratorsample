#pragma once

#include <binder/IInterface.h>
#include <android/os/IVibratorManagerService.h>

namespace android {

namespace os {

class BnVibratorManagerService : public ::android::BnInterface<IVibratorManagerService> {
public:
  static constexpr uint32_t TRANSACTION_getVibratorIds = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getVibratorInfo = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_isVibrating = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_registerVibratorStateListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_unregisterVibratorStateListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_setAlwaysOnEffect = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_vibrate = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_cancelVibrate = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  explicit BnVibratorManagerService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnVibratorManagerService

}  // namespace os

}  // namespace android
