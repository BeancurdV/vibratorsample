package com.beancurdv.vibrator_sample

import android.os.Build
import android.os.Bundle
import android.os.Vibrator
import android.os.VibratorManager
import androidx.appcompat.app.AppCompatActivity
import com.beancurdv.vibrator_sample.databinding.ActivityMainBinding


class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = stringFromJNI()
        binding.sampleText.setOnClickListener {
            // android 12 分界线
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) {
                val manager = getSystemService(VIBRATOR_MANAGER_SERVICE) as VibratorManager
                binding.sampleText.text = manager.vibratorIds.toString()
                manager.getVibrator(manager.vibratorIds[0]).vibrate(1000)
            } else {
                // android 11 分界线
                val manager = getSystemService(VIBRATOR_SERVICE) as Vibrator
                TODO("VERSION.SDK_INT < S")
                // 获取 Vibrator 实例

                // 检查设备是否支持振动
                if (manager != null && manager.hasVibrator()) {
                    // 使设备振动 500 毫秒
                    manager.vibrate(500)
                } else {
                    // 设备不支持振动或 Vibrator 实例为空
                    // 可以在这里处理不支持振动的情况
                }
            }
        }
    }

    /**
     * A native method that is implemented by the 'vibrator_sample' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'vibrator_sample' library on application startup.
        init {
            System.loadLibrary("vibrator_sample")
        }
    }
}