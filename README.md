# 一、相关资料准备
1. [android.so 路径列表](https://blog.csdn.net/gangjindianzi/article/details/124181036)
> libbinder.so  路径如下：frameworks/native/libs/binder

2. lib_ndk 参考路径：frameworks/native/libs/binder/ndk/Android.bp

```makefile
cc_library {
    name: "libbinder_ndk",
    vendor_available: true,

    export_include_dirs: [
        "include_ndk",
        "include_apex",
    ],

    cflags: [
        "-Wall",
        "-Wextra",
        "-Werror",
    ],

    srcs: [
        "ibinder.cpp",
        "ibinder_jni.cpp",
        "parcel.cpp",
        "process.cpp",
        "status.cpp",
        "service_manager.cpp",
    ],

    shared_libs: [
        "libandroid_runtime_lazy",
        "libbase",
        "libbinder",
        "libutils",
    ],

    header_libs: [
        "jni_headers",
    ],
    export_header_lib_headers: [
        "jni_headers",
    ],

    version_script: "libbinder_ndk.map.txt",
    stubs: {
        symbol_file: "libbinder_ndk.map.txt",
        versions: ["29"],
    },
}

```
从这里可以看出libbinder_ndk.so --依赖于---> libbinder.so 。

3. lib_ndk 对应的samples中的 makefile:  [iface.h](frameworks/native/libs/binder/ndk/test/Android.bp)

```bp
cc_library_static {
    name: "test_libbinder_ndk_library",
    defaults: ["test_libbinder_ndk_defaults"],
    export_include_dirs: ["include"],
    shared_libs: ["libbinder_ndk"],
    export_shared_lib_headers: ["libbinder_ndk"],
    srcs: ["iface.cpp"],
}
```
4. 参考 [iface.cpp](frameworks/native/libs/binder/ndk/test/iface.cpp)

5. 然后想办法传递parcel对象


# 相关链接信息
1.[Android Binder 底层实现原理](https://blog.csdn.net/ykun089/article/details/133985363)
2.[Android Developer 官网](https://developer.android.com/ndk/reference/group/ndk-binder)
3.[HAL: 将HIDL 接口改造为Stable AIDL](https://blog.csdn.net/weixin_60253080/article/details/127810200)
4.[vnd binder和binder共存问题](https://juejin.cn/post/7368308963127394304#heading-8)
5.[Android native进程间通信实例-binder篇](https://cloud.tencent.com/developer/article/1504415)
6.[binder的两种C语言实现方式](https://blog.csdn.net/u010160644/article/details/125278190)

## 方式二 通过binder去获取 值IPC State
1. [libhwbinder](/system/libhwbinder)系统binder库 real实现
2. [libbinder](frameworks/native/libs/binder/Android.bp)

## 方式三 通过binder service_manager去获取
/frameworks/native/cmds/servicemanager/bctest.c
servicemanager



# 相关头文件
../../rk3568_android12_SDK/frameworks/native/include/binder/IServiceManager.h
../../rk3568_android12_SDK/frameworks/native/libs/binder/include/binder/IServiceManager.h
../../rk3568_android12_SDK/frameworks/native/include/binder/IInterface.h
../../rk3568_android12_SDK/frameworks/native/libs/binder/include/binder/IInterface.h
../../rk3568_android12_SDK/system/core/libutils/include/utils/VectorImpl.h
 ../../rk3568_android12_SDK/system/logging/liblog/include/log/log_id.h
 ../../rk3568_android12_SDK/system/logging/liblog/include/log/log.h
 /system/core/libsystem/include/system/graphics.h

 out/target/product/rk3568_s/system/lib/libbinder.so
 out/target/product/rk3568_s/system/lib/libutils.so
  out/target/product/rk3568_s/system/lib/libcutils.so
 out/target/product/rk3568_s/system/lib/liblog.so

 > scp beancurd@121.37.117.214:/home/beancurd/rk3568_android_sdk/rk3568_android12_SDK/out/target/product/rk3568_s/system/lib/liblog.so -P 65068 .

../../rk3568_android12_SDK/prebuilts/clang/host/linux-x86/clang-r416183b1/bin/clang++ -o vibrator_main.o -I include/ vibrator_main.cpp  -std=c++17 -lc++_shared