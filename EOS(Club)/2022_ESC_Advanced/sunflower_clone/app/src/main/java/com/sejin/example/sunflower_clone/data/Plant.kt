package com.sejin.example.sunflower_clone.data

import java.util.*
import java.util.Calendar.DAY_OF_YEAR

data class Plant(
    val plantId: String,
    val name: String,
    val description: String,
    val growZoneNumber: Int,
    val wateringInterval: Int = 7, // how often the plant should be waterd, in days
    val imageUrl: String = ""
) {
    fun shouldBeWatered(since: Calendar, lastWateringDate: Calendar) =
        since > lastWateringDate.apply { add(DAY_OF_YEAR, wateringInterval) }
    override fun toString() = name
}
