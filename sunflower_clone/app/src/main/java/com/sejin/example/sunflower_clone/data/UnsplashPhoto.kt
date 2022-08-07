import com.sejin.example.sunflower_clone.data.UnsplashPhotoUrls
import com.squareup.moshi.Json

data class UnsplashPhoto(@Json(name = "urls") val urls: UnsplashPhotoUrls)