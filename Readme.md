# Tugas Praktikum 2 (TP2) DPBO - Sistem Manajemen Film Bioskop

## JANJI
Saya Muhiban Fadlan Nursaid dengan NIM 2400382 mengerjakan Tugas Praktikum 2 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

---

## Deskripsi Program
Program ini merupakan **Sistem Manajemen Data Film Bioskop** berbasis Pemrograman Berorientasi Objek (OOP) yang berfokus pada penerapan konsep **Multilevel Inheritance (Pewarisan Berantai)** 3 Tingkat.

Penerapan rantai pewarisan pada program ini:
1. **Base Class (Tingkat 1):** `Media` - Mengelola informasi media dasar (`idMedia`, `judul`, `tahunRilis`).
2. **Intermediary Class (Tingkat 2):** `Film` (mewarisi `Media`) - Mengelola detail spesifik film (`genre`, `durasiMenit`, `sutradara`).
3. **Derived Class (Tingkat 3):** `FilmBioskop` (mewarisi `Film`) - Mengelola atribut operasional bioskop (`hargaTiket`, `studio`, `ratingUsia`, serta `fotoProduk` khusus pada versi PHP).

Program diimplementasikan secara konsisten di 4 bahasa pemrograman:
* **C++ (CLI)** - Menggunakan `std::vector` dan perhitungan lebar kolom otomatis dengan `std::max`[cite: 5].
* **Java (CLI)** - Menggunakan `ArrayList` dan formatting `System.out.printf` dinamis[cite: 5].
* **Python (CLI)** - Menggunakan *list of objects* dan kalkulasi *string formatting* dinamis[cite: 5].
* **PHP (Web Form)** - Menggunakan tabel HTML responsif dengan *styling* poster seragam dan penanganan *session* `$_SESSION`[cite: 5].

---

## Desain & Hirarki Kelas (Multilevel Inheritance)

```text
       ┌─────────────────────────┐
       │          Media          │  (Base Class)
       │ ----------------------- │
       │ - idMedia: string       │
       │ - judul: string         │
       │ - tahunRilis: int       │
       └────────────┬────────────┘
                    │
                    ▼
       ┌─────────────────────────┐
       │          Film           │  (Intermediary Class)
       │ ----------------------- │
       │ - genre: string         │
       │ - durasiMenit: int      │
       │ - sutradara: string     │
       └────────────┬────────────┘
                    │
                    ▼
       ┌─────────────────────────┐
       │       FilmBioskop       │  (Derived Class)
       │ ----------------------- │
       │ - hargaTiket: int       │
       │ - studio: string        │
       │ - ratingUsia: string    │
       │ - fotoProduk: string*   │ (*Khusus PHP)
       └─────────────────────────┘




Alur Program (System Flow)

[ Start Program ]
        │
        ▼
[ Inisialisasi 5 Data Awal ] ──► (Membuat 5 Objek FilmBioskop ke List/Vector/Session)
        │
        ▼
[ Cetak Tabel Data Awal ] ──► (Kalkulasi Lebar Kolom Dinamis & Tampilkan Tabel)
        │
        ▼
[ Input Data Baru ] ───────► (Membaca masukan dari User / Redirection file.txt)
        │
        ▼
[ Instansiasi & Simpan ] ────► (Membuat Objek FilmBioskop ke-6 & Append ke List)
        │
        ▼
[ Cetak Tabel Gabungan ] ──► (Kalkulasi Ulang Lebar Kolom & Tampilkan Hasil Akhir)
        │
        ▼
[ End Program ]



Struktur Repositori

TP2/
├── CPP/
│   ├── Media.cpp
│   ├── Film.cpp
│   ├── FilmBioskop.cpp
│   ├── main.cpp
│   └── file.txt
├── Java/
│   ├── Media.java
│   ├── Film.java
│   ├── FilmBioskop.java
│   ├── Main.java
│   └── file.txt
├── Python/
│   ├── Media.py
│   ├── Film.py
│   ├── FilmBioskop.py
│   ├── main.py
│   └── file.txt
├── PHP/
│   ├── images/
│   │   ├── interstellar.jpg
│   │   ├── inception.jpg
│   │   ├── dark_knight.jpg
│   │   ├── spirited_away.jpg
│   │   └── parasite.jpg
│   ├── Media.php
│   ├── Film.php
│   ├── FilmBioskop.php
│   └── index.php
├── Dokumentasi/
│   ├── CPP/
│   │   └── dokum_CPP.png
│   ├── Java/
│   │   └── dokum_Java.png
│   ├── Python/
│   │   └── dokum_Python.png
│   └── PHP/
│       └── dokum_php.png
└── Readme.md


*Note : untuk dokumentasi bahasa CPP, Java, dan Python, pada tahap eksekusinya saya menggunakan 
( [bahasa] < file.txt) sehingga tidak terlihat input secara manual dikarenakan efisiensi waktu. namun secara fungsi inpuntnya sudah jalan. jika akang teteh berkenan, silahkan bisa mencoba input manual untuk menguji apakah sudah dapat menerima input atau tidak. Terima kasih :D