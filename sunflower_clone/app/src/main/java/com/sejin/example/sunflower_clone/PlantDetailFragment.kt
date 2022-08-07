package com.sejin.example.sunflower_clone

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.navigation.fragment.findNavController
import androidx.navigation.fragment.navArgs
import coil.load
import com.sejin.example.sunflower_clone.data.Plant
import com.sejin.example.sunflower_clone.data.dummyDatabase
import com.sejin.example.sunflower_clone.databinding.FragmentPlantDetailBinding

class PlantDetailFragment : Fragment() {

    val args: PlantDetailFragmentArgs by navArgs()
    lateinit var binding: FragmentPlantDetailBinding
    lateinit var plant : Plant

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        binding = FragmentPlantDetailBinding.inflate(inflater, container, false)

        return binding.root
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        val id = args.id
        plant = dummyDatabase.getPlantById(id)
        binding.detailImage.load(plant.imageUrl)
        binding.btnDetailToGallery.setOnClickListener { navigateToGallery() }

    }

    private fun navigateToGallery() {
        val direction =
            PlantDetailFragmentDirections.actionPlantDetailFragmentToGalleryFragment(name = plant.name)
        findNavController().navigate(direction)
    }
}