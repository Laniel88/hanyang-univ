package com.sejin.example.sunflower_clone

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.navigation.fragment.findNavController
import com.sejin.example.sunflower_clone.databinding.FragmentGardenBinding

class GardenFragment : Fragment() {

    private lateinit var binding: FragmentGardenBinding

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        binding = FragmentGardenBinding.inflate(inflater, container, false)
        return binding.root
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        binding.btnGardenToDetail.setOnClickListener {
            navigateToPlant()
        }
    }

    private fun navigateToPlant() {
//        val direction =
//            HomeViewPagerFragmentDirections.actionHomeViewPagerFragmentToPlantDetailFragment()
//        findNavController().navigate(direction)
    }
}