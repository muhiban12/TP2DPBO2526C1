#ifndef FILMBIOSKOP_CPP
#define FILMBIOSKOP_CPP

#include "Film.cpp"

// Derived Class (Tingkat 3) - Inherits Film
class FilmBioskop : public Film {
private:
    int hargaTiket;
    string studio;
    string ratingUsia;

public:
    FilmBioskop() : Film() {
        this->hargaTiket = 0;
        this->studio = "";
        this->ratingUsia = "";
    }

    FilmBioskop(string idMedia, string judul, int tahunRilis, string genre, int durasiMenit, string sutradara, int hargaTiket, string studio, string ratingUsia)
        : Film(idMedia, judul, tahunRilis, genre, durasiMenit, sutradara) {
        this->hargaTiket = hargaTiket;
        this->studio = studio;
        this->ratingUsia = ratingUsia;
    }

    int getHargaTiket() const { return hargaTiket; }
    void setHargaTiket(int hargaTiket) { this->hargaTiket = hargaTiket; }

    string getStudio() const { return studio; }
    void setStudio(string studio) { this->studio = studio; }

    string getRatingUsia() const { return ratingUsia; }
    void setRatingUsia(string ratingUsia) { this->ratingUsia = ratingUsia; }

    ~FilmBioskop() {}
};

#endif