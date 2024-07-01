#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include "IVibratorManagerService.h"

namespace android {

    namespace os {

        class BpVibratorManagerService : public ::android::BpInterface<IVibratorManagerService> {
        public:
            explicit BpVibratorManagerService(const ::android::sp<::android::IBinder>& _aidl_impl);
//            virtual ~BpVibratorManagerService() = default;
            ::android::binder::Status getVibratorIds(::std::vector<int32_t>* _aidl_return) override;
            ::android::binder::Status getVibratorInfo(int32_t vibratorId, ::android::os::VibratorInfo* _aidl_return) override;
            ::android::binder::Status isVibrating(int32_t vibratorId, bool* _aidl_return) override;
            ::android::binder::Status registerVibratorStateListener(int32_t vibratorId, const ::android::sp<::android::os::IVibratorStateListener>& listener, bool* _aidl_return) override;
            ::android::binder::Status unregisterVibratorStateListener(int32_t vibratorId, const ::android::sp<::android::os::IVibratorStateListener>& listener, bool* _aidl_return) override;
            ::android::binder::Status setAlwaysOnEffect(int32_t uid, const ::android::String16& opPkg, int32_t alwaysOnId, const ::android::os::CombinedVibration& vibration, const ::android::os::VibrationAttributes& attributes, bool* _aidl_return) override;
            ::android::binder::Status vibrate(int32_t uid, const ::android::String16& opPkg, const ::android::os::CombinedVibration& vibration, const ::android::os::VibrationAttributes& attributes, const ::android::String16& reason, const ::android::sp<::android::IBinder>& token) override;
            ::android::binder::Status cancelVibrate(int32_t usageFilter, const ::android::sp<::android::IBinder>& token) override;
        };  // class BpVibratorManagerService


    }  // namespace os

}  // namespace android
