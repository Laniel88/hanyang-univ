package com.sejin.example.sunflower_clone

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.databinding.DataBindingUtil
import com.google.android.material.tabs.TabLayoutMediator
import com.sejin.example.sunflower_clone.adapters.MY_GARDEN_PAGE_INDEX
import com.sejin.example.sunflower_clone.adapters.PLANT_LIST_PAGE_INDEX
import com.sejin.example.sunflower_clone.adapters.SunflowerPagerAdapter
import com.sejin.example.sunflower_clone.databinding.FragmentHomeViewPagerBinding

class HomeViewPagerFragment : Fragment() {

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        val binding = FragmentHomeViewPagerBinding.inflate(inflater, container, false)
        val tabLayout = binding.tabs
        val viewpager = binding.viewPager

        viewpager.adapter = SunflowerPagerAdapter(this)
        TabLayoutMediator(tabLayout, viewpager) { tab, position ->
            tab.setIcon(getTabIcon(position))
        }.attach()

        return binding.root
    }

    private fun getTabIcon(position: Int): Int {
        return when (position) {
            MY_GARDEN_PAGE_INDEX -> R.drawable.garden_tab_selector
            PLANT_LIST_PAGE_INDEX -> R.drawable.plant_list_tab_selector
            else -> throw IndexOutOfBoundsException()
        }
    }

    private fun getTabTitle(position: Int): String? {
        return when (position) {
            MY_GARDEN_PAGE_INDEX -> getString(R.string.my_garden_title)
            PLANT_LIST_PAGE_INDEX -> getString(R.string.plant_list_title)
            else -> null
        }
    }
}