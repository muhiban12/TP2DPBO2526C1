public class Media {
    private String idMedia;
    private String judul;
    private int tahunRilis;

    public Media() {
        this.idMedia = "";
        this.judul = "";
        this.tahunRilis = 0;
    }

    public Media(String idMedia, String judul, int tahunRilis) {
        this.idMedia = idMedia;
        this.judul = judul;
        this.tahunRilis = tahunRilis;
    }

    public String getIdMedia() { return idMedia; }
    public void setIdMedia(String idMedia) { this.idMedia = idMedia; }

    public String getJudul() { return judul; }
    public void setJudul(String judul) { this.judul = judul; }

    public int getTahunRilis() { return tahunRilis; }
    public void setTahunRilis(int tahunRilis) { this.tahunRilis = tahunRilis; }
}