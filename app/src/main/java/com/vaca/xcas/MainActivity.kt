package com.vaca.xcas

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.vaca.xcas.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {
    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = stringFromJNI("1+integrate(x*sin(x),x)")
    }

    external fun stringFromJNI(operation:String): String

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("vaca-lib")
        }
    }
}