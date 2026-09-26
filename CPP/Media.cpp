#ifndef MEDIA_CPP
#define MEDIA_CPP

#include <iostream>
#include <string>

using namespace std;

// Base Class (Tingkat 1)
class Media {
private:
    string idMedia;
    string judul;
    int tahunRilis;

public:
    Media() {
        this->idMedia = "";
        this->judul = "";
        this->tahunRilis = 0;
    }

    Media(string idMedia, string judul, int tahunRilis) {
        this->idMedia = idMedia;
        this->judul = judul;
        this->tahunRilis = tahunRilis;
    }

    string getIdMedia() const { return idMedia; }
    void setIdMedia(string idMedia) { this->idMedia = idMedia; }

    string getJudul() const { return judul; }
    void setJudul(string judul) { this->judul = judul; }

    int getTahunRilis() const { return tahunRilis; }
    void setTahunRilis(int tahunRilis) { this->tahunRilis = tahunRilis; }

    ~Media() {}
};

#endif