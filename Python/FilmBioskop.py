from Film import Film

class FilmBioskop(Film):
    def __init__(self, idMedia="", judul="", tahunRilis=0, genre="", durasiMenit=0, sutradara="", hargaTiket=0, studio="", ratingUsia=""):
        super().__init__(idMedia, judul, tahunRilis, genre, durasiMenit, sutradara)
        self._hargaTiket = hargaTiket
        self._studio = studio
        self._ratingUsia = ratingUsia

    def getHargaTiket(self): return self._hargaTiket
    def setHargaTiket(self, hargaTiket): self._hargaTiket = hargaTiket

    def getStudio(self): return self._studio
    def setStudio(self, studio): self._studio = studio

    def getRatingUsia(self): return self._ratingUsia
    def setRatingUsia(self, ratingUsia): self._ratingUsia = ratingUsia