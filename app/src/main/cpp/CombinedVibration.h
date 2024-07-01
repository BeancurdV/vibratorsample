//
// Created by 张凤成 on 2024/7/1.
//

#ifndef VIBRATOR_SAMPLE_COMBINEDVIBRATION_H
#define VIBRATOR_SAMPLE_COMBINEDVIBRATION_H
namespace android {
    namespace os {

        class CombinedVibration : public android::Parcelable {
        public:
            CombinedVibration();
            virtual ~CombinedVibration();

            // Parcelable interface
            virtual status_t writeToParcel(Parcel* parcel) const override;
            virtual status_t readFromParcel(const Parcel* parcel) override;

            // 添加其他成员函数和变量
        };

    } // namespace os
} // namespace android
#endif //VIBRATOR_SAMPLE_COMBINEDVIBRATION_H
