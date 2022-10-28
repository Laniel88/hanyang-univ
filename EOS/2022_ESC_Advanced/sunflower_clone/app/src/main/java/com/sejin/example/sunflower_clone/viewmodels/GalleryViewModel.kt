import android.util.Log
import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.sejin.example.sunflower_clone.adapters.UnsplashApi
import com.sejin.example.sunflower_clone.data.UnsplashSearchResponse
import kotlinx.coroutines.launch
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response

class GalleryViewModel : ViewModel() {

    private val _photos = MutableLiveData<List<UnsplashPhoto>>()

    val photos: LiveData<List<UnsplashPhoto>> = _photos

//    init {
//        getPhotos()
//    }

    fun getPhotos(query: String) {
        viewModelScope.launch {
            val res = UnsplashApi.retrofitService.searchPhotosCouroutine(query,1,10)
            _photos.value = res.results.toList()
        }

//        val call = UnsplashApi.retrofitService.searchPhotos(
//            "apple",
//            10,
//            10
//        )
//        val callback = object : Callback<UnsplashSearchResponse> {
//            override fun onResponse(
//                call: Call<UnsplashSearchResponse>,
//                response: Response<UnsplashSearchResponse>
//            ) {
//                Log.i("TTAAGG", "onResponse: ${response.body()}")
//                _photos.value = response.body()?.results?.toMutableList()!!
//            }
//
//            override fun onFailure(call: Call<UnsplashSearchResponse>, t: Throwable) {
//                Log.i("TTAAGG", "onFailure: ${t.message}")
//            }
//        }
//
//        call.enqueue(callback)
    }

    init {
    }
}