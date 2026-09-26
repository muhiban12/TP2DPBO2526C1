<?php
class Media {
    private $idMedia;
    private $judul;
    private $tahunRilis;

    public function __construct($idMedia="", $judul="", $tahunRilis=0) {
        $this->idMedia = $idMedia;
        $this->judul = $judul;
        $this->tahunRilis = $tahunRilis;
    }

    public function getIdMedia() { return $this->idMedia; }
    public function setIdMedia($idMedia) { $this->idMedia = $idMedia; }

    public function getJudul() { return $this->judul; }
    public function setJudul($judul) { $this->judul = $judul; }

    public function getTahunRilis() { return $this->tahunRilis; }
    public function setTahunRilis($tahunRilis) { $this->tahunRilis = $tahunRilis; }
}
?>