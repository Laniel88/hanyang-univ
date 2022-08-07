package com.sejin.example.sunflower_clone.adapters

import com.sejin.example.sunflower_clone.BuildConfig
import com.sejin.example.sunflower_clone.data.UnsplashSearchResponse
import com.squareup.moshi.Moshi
import com.squareup.moshi.kotlin.reflect.KotlinJsonAdapterFactory
import okhttp3.OkHttpClient
import retrofit2.Call
import retrofit2.Response
import retrofit2.Retrofit
import retrofit2.converter.moshi.MoshiConverterFactory
import retrofit2.http.GET
import retrofit2.http.Query

//https://unsplash.com/documentation#search-photos

private const val BASE_URL = "https://api.unsplash.com/"

private val moshi = Moshi.Builder()
    .add(KotlinJsonAdapterFactory())
    .build()

private val retrofit = Retrofit.Builder()
    .addConverterFactory(MoshiConverterFactory.create(moshi))
    .baseUrl(BASE_URL)
    .build()

interface UnsplashService {
    @GET("search/photos")
    fun searchPhotos(
        @Query("query") query: String,
        @Query("page") page: Int,
        @Query("per_page") perPage: Int,
        @Query("client_id") clientId: String = BuildConfig.UNSPLASH_ACCESS_KEY
    ): Call<UnsplashSearchResponse>

    @GET("search/photos")
    suspend fun searchPhotosCouroutine(
        @Query("query") query: String,
        @Query("page") page: Int,
        @Query("per_page") perPage: Int,
        @Query("client_id") clientId: String = BuildConfig.UNSPLASH_ACCESS_KEY
    ): UnsplashSearchResponse
}

object UnsplashApi {
    val retrofitService: UnsplashService by lazy { retrofit.create(UnsplashService::class.java) }
}