#ifndef FILM_CPP
#define FILM_CPP

#include "Media.cpp"

// Intermediary Class (Tingkat 2) - Inherits Media
class Film : public Media {
private:
    string genre;
    int durasiMenit;
    string sutradara;

public:
    Film() : Media() {
        this->genre = "";
        this->durasiMenit = 0;
        this->sutradara = "";
    }

    Film(string idMedia, string judul, int tahunRilis, string genre, int durasiMenit, string sutradara)
        : Media(idMedia, judul, tahunRilis) {
        this->genre = genre;
        this->durasiMenit = durasiMenit;
        this->sutradara = sutradara;
    }

    string getGenre() const { return genre; }
    void setGenre(string genre) { this->genre = genre; }

    int getDurasiMenit() const { return durasiMenit; }
    void setDurasiMenit(int durasiMenit) { this->durasiMenit = durasiMenit; }

    string getSutradara() const { return sutradara; }
    void setSutradara(string sutradara) { this->sutradara = sutradara; }

    ~Film() {}
};

#endif