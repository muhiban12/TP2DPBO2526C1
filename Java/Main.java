import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void cetakTabel(ArrayList<FilmBioskop> listFilm) {
        String hId = "ID", hJudul = "Judul", hTahun = "Tahun", hGenre = "Genre";
        String hDurasi = "Durasi", hSutradara = "Sutradara", hHarga = "Harga Tiket";
        String hStudio = "Studio", hRating = "Rating";

        // 1. Hitung lebar maksimal tiap kolom secara dinamis
        int wId = hId.length();
        int wJudul = hJudul.length();
        int wTahun = hTahun.length();
        int wGenre = hGenre.length();
        int wDurasi = hDurasi.length();
        int wSutradara = hSutradara.length();
        int wHarga = hHarga.length();
        int wStudio = hStudio.length();
        int wRating = hRating.length();

        for (FilmBioskop film : listFilm) {
            wId = Math.max(wId, film.getIdMedia().length());
            wJudul = Math.max(wJudul, film.getJudul().length());
            wTahun = Math.max(wTahun, String.valueOf(film.getTahunRilis()).length());
            wGenre = Math.max(wGenre, film.getGenre().length());
            wDurasi = Math.max(wDurasi, (film.getDurasiMenit() + " m").length());
            wSutradara = Math.max(wSutradara, film.getSutradara().length());
            wHarga = Math.max(wHarga, ("Rp" + film.getHargaTiket()).length());
            wStudio = Math.max(wStudio, film.getStudio().length());
            wRating = Math.max(wRating, film.getRatingUsia().length());
        }

        // 2. Buat garis pembatas dinamis
        int totalWidth = wId + wJudul + wTahun + wGenre + wDurasi + wSutradara + wHarga + wStudio + wRating + 28;
        String line = "=".repeat(totalWidth);

        // 3. Buat format string dinamis
        String format = "| %-" + wId + "s | %-" + wJudul + "s | %-" + wTahun + "s | %-" + wGenre + "s | %-" + wDurasi + "s | %-" + wSutradara + "s | %-" + wHarga + "s | %-" + wStudio + "s | %-" + wRating + "s |\n";

        // 4. Cetak Header
        System.out.println("\n" + line);
        System.out.printf(format, hId, hJudul, hTahun, hGenre, hDurasi, hSutradara, hHarga, hStudio, hRating);
        System.out.println(line);

        // 5. Cetak Baris Data
        for (FilmBioskop film : listFilm) {
            System.out.printf(format,
                    film.getIdMedia(),
                    film.getJudul(),
                    film.getTahunRilis(),
                    film.getGenre(),
                    film.getDurasiMenit() + " m",
                    film.getSutradara(),
                    "Rp" + film.getHargaTiket(),
                    film.getStudio(),
                    film.getRatingUsia());
        }
        System.out.println(line);
    }

    public static void main(String[] args) {
        ArrayList<FilmBioskop> listFilm = new ArrayList<>();

        // 5 Data Awal
        listFilm.add(new FilmBioskop("M001", "Interstellar", 2014, "Sci-Fi", 169, "Christopher Nolan", 50000, "Studio 1", "SU"));
        listFilm.add(new FilmBioskop("M002", "Inception", 2010, "Action", 148, "Christopher Nolan", 45000, "Studio 2", "13+"));
        listFilm.add(new FilmBioskop("M003", "The Dark Knight", 2008, "Action", 152, "Christopher Nolan", 50000, "Studio 1", "17+"));
        listFilm.add(new FilmBioskop("M004", "Spirited Away", 2001, "Animation", 125, "Hayao Miyazaki", 40000, "Studio 3", "SU"));
        listFilm.add(new FilmBioskop("M005", "Parasite", 2019, "Thriller", 132, "Bong Joon-ho", 45000, "Studio 2", "17+"));

        System.out.println("--- DATA AWAL FILM BIOSKOP ---");
        cetakTabel(listFilm);

        // Input 1 Data Baru
        Scanner sc = new Scanner(System.in);
        System.out.println("\n--- MASUKKAN DATA FILM BARU ---");
        System.out.print("ID Media     : "); String id = sc.nextLine();
        System.out.print("Judul Film   : "); String judul = sc.nextLine();
        System.out.print("Tahun Rilis  : "); int tahun = Integer.parseInt(sc.nextLine());
        System.out.print("Genre        : "); String genre = sc.nextLine();
        System.out.print("Durasi (min) : "); int durasi = Integer.parseInt(sc.nextLine());
        System.out.print("Sutradara    : "); String sutradara = sc.nextLine();
        System.out.print("Harga Tiket  : "); int harga = Integer.parseInt(sc.nextLine());
        System.out.print("Studio       : "); String studio = sc.nextLine();
        System.out.print("Rating Usia  : "); String rating = sc.nextLine();

        listFilm.add(new FilmBioskop(id, judul, tahun, genre, durasi, sutradara, harga, studio, rating));

        System.out.println("\n--- DATA GABUNGAN SETELAH PENAMBAHAN ---");
        cetakTabel(listFilm);
        sc.close();
    }
}