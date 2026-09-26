<?php
require_once "Film.php";

// Class Derived dengan atribut tambahan khusus PHP (fotoProduk)
class FilmBioskop extends Film {
    private $hargaTiket;
    private $studio;
    private $ratingUsia;
    private $fotoProduk; // Khusus PHP

    public function __construct($idMedia="", $judul="", $tahunRilis=0, $genre="", $durasiMenit=0, $sutradara="", $hargaTiket=0, $studio="", $ratingUsia="", $fotoProduk="") {
        parent::__construct($idMedia, $judul, $tahunRilis, $genre, $durasiMenit, $sutradara);
        $this->hargaTiket = $hargaTiket;
        $this->studio = $studio;
        $this->ratingUsia = $ratingUsia;
        $this->fotoProduk = $fotoProduk;
    }

    public function getHargaTiket() { return $this->hargaTiket; }
    public function setHargaTiket($hargaTiket) { $this->hargaTiket = $hargaTiket; }

    public function getStudio() { return $this->studio; }
    public function setStudio($studio) { $this->studio = $studio; }

    public function getRatingUsia() { return $this->ratingUsia; }
    public function setRatingUsia($ratingUsia) { $this->ratingUsia = $ratingUsia; }

    public function getFotoProduk() { return $this->fotoProduk; }
    public function setFotoProduk($fotoProduk) { $this->fotoProduk = $fotoProduk; }
}
?>