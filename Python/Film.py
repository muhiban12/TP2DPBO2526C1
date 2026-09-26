from Media import Media

class Film(Media):
    def __init__(self, idMedia="", judul="", tahunRilis=0, genre="", durasiMenit=0, sutradara=""):
        super().__init__(idMedia, judul, tahunRilis)
        self._genre = genre
        self._durasiMenit = durasiMenit
        self._sutradara = sutradara

    def getGenre(self): return self._genre
    def setGenre(self, genre): self._genre = genre

    def getDurasiMenit(self): return self._durasiMenit
    def setDurasiMenit(self, durasiMenit): self._durasiMenit = durasiMenit

    def getSutradara(self): return self._sutradara
    def setSutradara(self, sutradara): self._sutradara = sutradara