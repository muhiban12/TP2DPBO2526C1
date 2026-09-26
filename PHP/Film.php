<?php
require_once "Media.php";

class Film extends Media {
    private $genre;
    private $durasiMenit;
    private $sutradara;

    public function __construct($idMedia="", $judul="", $tahunRilis=0, $genre="", $durasiMenit=0, $sutradara="") {
        parent::__construct($idMedia, $judul, $tahunRilis);
        $this->genre = $genre;
        $this->durasiMenit = $durasiMenit;
        $this->sutradara = $sutradara;
    }

    public function getGenre() { return $this->genre; }
    public function setGenre($genre) { $this->genre = $genre; }

    public function getDurasiMenit() { return $this->durasiMenit; }
    public function setDurasiMenit($durasiMenit) { $this->durasiMenit = $durasiMenit; }

    public function getSutradara() { return $this->sutradara; }
    public function setSutradara($sutradara) { $this->sutradara = $sutradara; }
}
?>