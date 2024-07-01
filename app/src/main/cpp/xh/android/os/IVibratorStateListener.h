#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IVibratorStateListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(VibratorStateListener)
  virtual ::android::binder::Status onVibrating(bool vibrating) = 0;
};  // class IVibratorStateListener

class IVibratorStateListenerDefault : public IVibratorStateListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onVibrating(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IVibratorStateListenerDefault

}  // namespace os

}  // namespace android
