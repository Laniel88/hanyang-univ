package com.sejin.example.sunflower_clone.adapters

import UnsplashPhoto
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.navigation.findNavController
import androidx.recyclerview.widget.DiffUtil
import androidx.recyclerview.widget.ListAdapter
import androidx.recyclerview.widget.RecyclerView
import coil.load
import com.sejin.example.sunflower_clone.HomeViewPagerFragmentDirections
import com.sejin.example.sunflower_clone.data.Plant
import com.sejin.example.sunflower_clone.databinding.ListItemPhotoBinding
import com.sejin.example.sunflower_clone.databinding.ListItemPlantBinding

class PhotoAdapter : ListAdapter<UnsplashPhoto, RecyclerView.ViewHolder>(PhotoDiffCallback()) {

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): RecyclerView.ViewHolder {
        return PlantViewHolder(
            ListItemPhotoBinding.inflate(
                LayoutInflater.from(parent.context),
                parent,
                false
            )
        )
    }

    override fun onBindViewHolder(holder: RecyclerView.ViewHolder, position: Int) {
        val url = getItem(position)
        (holder as PlantViewHolder).bind(url)
    }

    class PlantViewHolder(private val binding: ListItemPhotoBinding) :
        RecyclerView.ViewHolder(binding.root) {
        fun bind(photo: UnsplashPhoto) {
            binding.plantItemImage.load(photo.urls.small)
        }
    }
}

private class PhotoDiffCallback : DiffUtil.ItemCallback<UnsplashPhoto>() {
    override fun areItemsTheSame(oldItem: UnsplashPhoto, newItem: UnsplashPhoto): Boolean {
        return oldItem == newItem
    }

    override fun areContentsTheSame(oldItem: UnsplashPhoto, newItem: UnsplashPhoto): Boolean {
        return oldItem == newItem
    }
}