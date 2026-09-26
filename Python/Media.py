class Media:
    def __init__(self, idMedia="", judul="", tahunRilis=0):
        self._idMedia = idMedia
        self._judul = judul
        self._tahunRilis = tahunRilis

    def getIdMedia(self): return self._idMedia
    def setIdMedia(self, idMedia): self._idMedia = idMedia

    def getJudul(self): return self._judul
    def setJudul(self, judul): self._judul = judul

    def getTahunRilis(self): return self._tahunRilis
    def setTahunRilis(self, tahunRilis): self._tahunRilis = tahunRilis