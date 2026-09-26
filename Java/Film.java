public class Film extends Media {
    private String genre;
    private int durasiMenit;
    private String sutradara;

    public Film() {
        super();
        this.genre = "";
        this.durasiMenit = 0;
        this.sutradara = "";
    }

    public Film(String idMedia, String judul, int tahunRilis, String genre, int durasiMenit, String sutradara) {
        super(idMedia, judul, tahunRilis);
        this.genre = genre;
        this.durasiMenit = durasiMenit;
        this.sutradara = sutradara;
    }

    public String getGenre() { return genre; }
    public void setGenre(String genre) { this.genre = genre; }

    public int getDurasiMenit() { return durasiMenit; }
    public void setDurasiMenit(int durasiMenit) { this.durasiMenit = durasiMenit; }

    public String getSutradara() { return sutradara; }
    public void setSutradara(String sutradara) { this.sutradara = sutradara; }
}