package com.sejin.example.sunflower_clone

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.navigation.fragment.findNavController
import com.sejin.example.sunflower_clone.adapters.PlantAdapter
import com.sejin.example.sunflower_clone.data.plantsList
import com.sejin.example.sunflower_clone.databinding.FragmentPlantingListBinding

class PlantListFragment : Fragment() {

    lateinit var binding: FragmentPlantingListBinding

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        binding = FragmentPlantingListBinding.inflate(inflater, container, false)
        val adapter = PlantAdapter()
        adapter.submitList(plantsList)
        binding.plantList.adapter = adapter
        return binding.root
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
    }

}