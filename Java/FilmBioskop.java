public class FilmBioskop extends Film {
    private int hargaTiket;
    private String studio;
    private String ratingUsia;

    public FilmBioskop() {
        super();
        this.hargaTiket = 0;
        this.studio = "";
        this.ratingUsia = "";
    }

    public FilmBioskop(String idMedia, String judul, int tahunRilis, String genre, int durasiMenit, String sutradara, int hargaTiket, String studio, String ratingUsia) {
        super(idMedia, judul, tahunRilis, genre, durasiMenit, sutradara);
        this.hargaTiket = hargaTiket;
        this.studio = studio;
        this.ratingUsia = ratingUsia;
    }

    public int getHargaTiket() { return hargaTiket; }
    public void setHargaTiket(int hargaTiket) { this.hargaTiket = hargaTiket; }

    public String getStudio() { return studio; }
    public void setStudio(String studio) { this.studio = studio; }

    public String getRatingUsia() { return ratingUsia; }
    public void setRatingUsia(String ratingUsia) { this.ratingUsia = ratingUsia; }
}