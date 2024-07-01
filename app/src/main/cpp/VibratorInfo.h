//
// Created by 张凤成 on 2024/7/1.
//

#ifndef VIBRATOR_SAMPLE_VIBRATORINFO_H
#define VIBRATOR_SAMPLE_VIBRATORINFO_H
#include <binder/Parcel.h>
#include <utils/RefBase.h>

namespace android {
    namespace os {

        class VibratorInfo : public android::Parcelable {
        public:
            VibratorInfo();
            virtual ~VibratorInfo();

            // Parcelable interface
            virtual status_t writeToParcel(Parcel* parcel) const override;
            virtual status_t readFromParcel(const Parcel* parcel) override;

            // 添加其他成员函数和变量
        };

    } // namespace os
} // namespace android

#endif //VIBRATOR_SAMPLE_VIBRATORINFO_H
