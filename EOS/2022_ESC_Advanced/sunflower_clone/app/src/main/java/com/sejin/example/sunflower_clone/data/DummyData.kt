package com.sejin.example.sunflower_clone.data

private val apple = Plant(
    plantId = "1",
    name = "apple",
    description = "apple desc",
    growZoneNumber = 1,
    wateringInterval = 7,
    imageUrl = "https://upload.wikimedia.org/wikipedia/commons/5/55/Apple_orchard_in_Tasmania.jpg"
)

private val beet = Plant(
    plantId = "2",
    name = "beet ",
    description = "desc",
    growZoneNumber = 2,
    wateringInterval = 7,
    imageUrl = "https://upload.wikimedia.org/wikipedia/commons/2/29/Beetroot_jm26647.jpg"
)
private val cilantro = Plant(
    plantId = "3",
    name = "cilan",
    description = "desc",
    growZoneNumber = 3,
    wateringInterval = 7,
    imageUrl = "https://upload.wikimedia.org/wikipedia/commons/5/51/A_scene_of_Coriander_leaves.JPG"
)
private val tomato = Plant(
    plantId = "4",
    name = "tomato",
    description = "desc",
    growZoneNumber = 4,
    wateringInterval = 7,
    imageUrl = "https://upload.wikimedia.org/wikipedia/commons/1/17/Cherry_tomatoes_red_and_green_2009_16x9.jpg"
)
private val avocado = Plant(
    plantId = "5",
    name = "avocado",
    description = "",
    growZoneNumber = 5,
    wateringInterval = 7,
    imageUrl = "https://upload.wikimedia.org/wikipedia/commons/e/e4/Branch_and_fruit_of_the_Maluma_avocado_cultivar.jpg"
)
private val pear = Plant(
    plantId = "6",
    name = "pear",
    description = "",
    growZoneNumber = 6,
    wateringInterval = 7,
    imageUrl = "https://upload.wikimedia.org/wikipedia/commons/1/13/More_pears.jpg"

)
private val eggPlant = Plant(
    plantId = "7",
    name = "eggPlant",
    description = "",
    growZoneNumber = 7,
    wateringInterval = 7,
    imageUrl = "https://upload.wikimedia.org/wikipedia/commons/e/e5/Eggplant_display.JPG"

)
private val grape = Plant(
    plantId = "8",
    name = "grape",
    description = "",
    growZoneNumber = 8,
    wateringInterval = 7,
    imageUrl = "https://upload.wikimedia.org/wikipedia/commons/0/03/Grape_Plant_and_grapes9.jpg"

)
private val mango = Plant(
    plantId = "9",
    name = "mango",
    description = "desc",
    growZoneNumber = 9,
    wateringInterval = 7,
    imageUrl = "https://upload.wikimedia.org/wikipedia/commons/6/67/Mangos_criollos_y_pera.JPG"

)
private val orange = Plant(
    plantId = "10",
    name = "orange",
    description = "desc",
    growZoneNumber = 10,
    wateringInterval = 7,
    imageUrl = "https://upload.wikimedia.org/wikipedia/commons/2/22/Apfelsinenbaum--Orange_tree.jpg"

)

val plantsList = arrayListOf<Plant>()
    .apply {
        add(apple)
        add(beet)
        add(cilantro)
        add(avocado)
        add(pear)
        add(eggPlant)
        add(grape)
        add(mango)
        add(orange)
        add(tomato)
    }

object dummyDatabase {
    fun getPlantById(id: String): Plant {
        for (plant in plantsList) {
            if (plant.plantId == id)
                return plant
        }
        throw IllegalStateException()
    }
}
