package com.sejin.example.sunflower_clone

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.databinding.DataBindingUtil
import com.sejin.example.sunflower_clone.databinding.ActivityGardenBinding

class GardenActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        DataBindingUtil.setContentView<ActivityGardenBinding>(this, R.layout.activity_garden)
    }
}