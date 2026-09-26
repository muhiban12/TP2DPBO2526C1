#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include "FilmBioskop.cpp"

using namespace std;

void cetakTabel(const vector<FilmBioskop>& listFilm) {
    string hId = "ID", hJudul = "Judul", hTahun = "Tahun", hGenre = "Genre";
    string hDurasi = "Durasi", hSutradara = "Sutradara", hHarga = "Harga Tiket";
    string hStudio = "Studio", hRating = "Rating";

    // 1. Cari lebar maksimal tiap kolom secara dinamis
    size_t wId = hId.length();
    size_t wJudul = hJudul.length();
    size_t wTahun = hTahun.length();
    size_t wGenre = hGenre.length();
    size_t wDurasi = hDurasi.length();
    size_t wSutradara = hSutradara.length();
    size_t wHarga = hHarga.length();
    size_t wStudio = hStudio.length();
    size_t wRating = hRating.length();

    for (const auto& film : listFilm) {
        wId = max(wId, film.getIdMedia().length());
        wJudul = max(wJudul, film.getJudul().length());
        wTahun = max(wTahun, to_string(film.getTahunRilis()).length());
        wGenre = max(wGenre, film.getGenre().length());
        wDurasi = max(wDurasi, (to_string(film.getDurasiMenit()) + " m").length());
        wSutradara = max(wSutradara, film.getSutradara().length());
        wHarga = max(wHarga, ("Rp" + to_string(film.getHargaTiket())).length());
        wStudio = max(wStudio, film.getStudio().length());
        wRating = max(wRating, film.getRatingUsia().length());
    }

    // 2. Buat garis pembatas dinamis
    size_t totalWidth = wId + wJudul + wTahun + wGenre + wDurasi + wSutradara + wHarga + wStudio + wRating + 28;
    string line(totalWidth, '=');

    // 3. Cetak Header
    cout << "\n" << line << "\n";
    cout << "| " << setw(wId) << left << hId
         << " | " << setw(wJudul) << left << hJudul
         << " | " << setw(wTahun) << left << hTahun
         << " | " << setw(wGenre) << left << hGenre
         << " | " << setw(wDurasi) << left << hDurasi
         << " | " << setw(wSutradara) << left << hSutradara
         << " | " << setw(wHarga) << left << hHarga
         << " | " << setw(wStudio) << left << hStudio
         << " | " << setw(wRating) << left << hRating << " |\n";
    cout << line << "\n";

    // 4. Cetak Data
    for (const auto& film : listFilm) {
        cout << "| " << setw(wId) << left << film.getIdMedia()
             << " | " << setw(wJudul) << left << film.getJudul()
             << " | " << setw(wTahun) << left << film.getTahunRilis()
             << " | " << setw(wGenre) << left << film.getGenre()
             << " | " << setw(wDurasi) << left << (to_string(film.getDurasiMenit()) + " m")
             << " | " << setw(wSutradara) << left << film.getSutradara()
             << " | " << setw(wHarga) << left << ("Rp" + to_string(film.getHargaTiket()))
             << " | " << setw(wStudio) << left << film.getStudio()
             << " | " << setw(wRating) << left << film.getRatingUsia() << " |\n";
    }
    cout << line << "\n";
}

int main() {
    vector<FilmBioskop> listFilm;

    // 5 Data Awal
    listFilm.push_back(FilmBioskop("M001", "Interstellar", 2014, "Sci-Fi", 169, "Christopher Nolan", 50000, "Studio 1", "SU"));
    listFilm.push_back(FilmBioskop("M002", "Inception", 2010, "Action", 148, "Christopher Nolan", 45000, "Studio 2", "13+"));
    listFilm.push_back(FilmBioskop("M003", "The Dark Knight", 2008, "Action", 152, "Christopher Nolan", 50000, "Studio 1", "17+"));
    listFilm.push_back(FilmBioskop("M004", "Spirited Away", 2001, "Animation", 125, "Hayao Miyazaki", 40000, "Studio 3", "SU"));
    listFilm.push_back(FilmBioskop("M005", "Parasite", 2019, "Thriller", 132, "Bong Joon-ho", 45000, "Studio 2", "17+"));

    cout << "--- DATA AWAL FILM BIOSKOP ---";
    cetakTabel(listFilm);

    // Input 1 Data Baru
    cout << "\n--- MASUKKAN DATA FILM BARU ---\n";
    string id, judul, genre, sutradara, studio, rating;
    int tahun, durasi, harga;

    cout << "ID Media     : "; cin >> id;
    cin.ignore();
    cout << "Judul Film   : "; getline(cin, judul);
    cout << "Tahun Rilis  : "; cin >> tahun;
    cin.ignore();
    cout << "Genre        : "; getline(cin, genre);
    cout << "Durasi (min) : "; cin >> durasi;
    cin.ignore();
    cout << "Sutradara    : "; getline(cin, sutradara);
    cout << "Harga Tiket  : "; cin >> harga;
    cin.ignore();
    cout << "Studio       : "; getline(cin, studio);
    cout << "Rating Usia  : "; cin >> rating;

    listFilm.push_back(FilmBioskop(id, judul, tahun, genre, durasi, sutradara, harga, studio, rating));

    cout << "\n--- DATA GABUNGAN SETELAH PENAMBAHAN ---";
    cetakTabel(listFilm);

    return 0;
}