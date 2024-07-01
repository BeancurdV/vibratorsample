//
// Created by sharknade on 2024/6/30.
//
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <android-base/logging.h>
// libbinder
// libbase
int main(int, char**) {

    // When SF is launched in its own process, limit the number of
    // binder threads to 1.
    ProcessState::self()->setThreadPoolMaxThreadCount(1);


    // start the thread pool
    sp<ProcessState> ps(ProcessState::self());
    ps->startThreadPool();


    // publish surface flinger
    // sp<IServiceManager> sm(defaultServiceManager());
    sp<IServiceManager> sm = defaultServiceManager();
    // sp<content::pm::IPackageManagerNative> package_mgr;
    if (sm.get() == nullptr) {
        LOG(INFO) << "Cannot find service manager";
    } else {
        sp<IBinder> binder = sm->getService(String16("vibrator_manager"));
        if (binder.get() == nullptr) {
            LOG(INFO) << "Cannot find vibrator_manager";
        } else {
            // package_mgr = interface_cast<content::pm::IPackageManagerNative>(binder);
        }
    }

    // sm->addService(String16(SurfaceFlinger::getServiceName()), flinger, false,
    // IServiceManager::DUMP_FLAG_PRIORITY_CRITICAL | IServiceManager::DUMP_FLAG_PROTO);

    return 0;
}