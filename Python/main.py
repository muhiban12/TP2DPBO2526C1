from FilmBioskop import FilmBioskop

def cetak_tabel(list_film):
    headers = ["ID", "Judul", "Tahun", "Genre", "Durasi", "Sutradara", "Harga Tiket", "Studio", "Rating"]

    # 1. Hitung lebar maksimal tiap kolom secara dinamis berdasarkan data terpanjang
    w_id = max(len(headers[0]), max((len(f.getIdMedia()) for f in list_film), default=0))
    w_judul = max(len(headers[1]), max((len(f.getJudul()) for f in list_film), default=0))
    w_tahun = max(len(headers[2]), max((len(str(f.getTahunRilis())) for f in list_film), default=0))
    w_genre = max(len(headers[3]), max((len(f.getGenre()) for f in list_film), default=0))
    w_durasi = max(len(headers[4]), max((len(f"{f.getDurasiMenit()} m") for f in list_film), default=0))
    w_sutradara = max(len(headers[5]), max((len(f.getSutradara()) for f in list_film), default=0))
    w_harga = max(len(headers[6]), max((len(f"Rp{f.getHargaTiket()}") for f in list_film), default=0))
    w_studio = max(len(headers[7]), max((len(f.getStudio()) for f in list_film), default=0))
    w_rating = max(len(headers[8]), max((len(f.getRatingUsia()) for f in list_film), default=0))

    # 2. Buat garis pembatas dinamis menyesuaikan total lebar kolom
    total_width = w_id + w_judul + w_tahun + w_genre + w_durasi + w_sutradara + w_harga + w_studio + w_rating + 28
    line = "=" * total_width

    # 3. Cetak Header
    print("\n" + line)
    print(f"| {headers[0]:<{w_id}} | {headers[1]:<{w_judul}} | {headers[2]:<{w_tahun}} | {headers[3]:<{w_genre}} | {headers[4]:<{w_durasi}} | {headers[5]:<{w_sutradara}} | {headers[6]:<{w_harga}} | {headers[7]:<{w_studio}} | {headers[8]:<{w_rating}} |")
    print(line)

    # 4. Cetak Baris Data
    for f in list_film:
        durasi_str = f"{f.getDurasiMenit()} m"
        harga_str = f"Rp{f.getHargaTiket()}"
        print(f"| {f.getIdMedia():<{w_id}} | {f.getJudul():<{w_judul}} | {str(f.getTahunRilis()):<{w_tahun}} | {f.getGenre():<{w_genre}} | {durasi_str:<{w_durasi}} | {f.getSutradara():<{w_sutradara}} | {harga_str:<{w_harga}} | {f.getStudio():<{w_studio}} | {f.getRatingUsia():<{w_rating}} |")
    print(line)

def main():
    list_film = [
        FilmBioskop("M001", "Interstellar", 2014, "Sci-Fi", 169, "Christopher Nolan", 50000, "Studio 1", "SU"),
        FilmBioskop("M002", "Inception", 2010, "Action", 148, "Christopher Nolan", 45000, "Studio 2", "13+"),
        FilmBioskop("M003", "The Dark Knight", 2008, "Action", 152, "Christopher Nolan", 50000, "Studio 1", "17+"),
        FilmBioskop("M004", "Spirited Away", 2001, "Animation", 125, "Hayao Miyazaki", 40000, "Studio 3", "SU"),
        FilmBioskop("M005", "Parasite", 2019, "Thriller", 132, "Bong Joon-ho", 45000, "Studio 2", "17+")
    ]

    print("--- DATA AWAL FILM BIOSKOP ---")
    cetak_tabel(list_film)

    print("\n--- MASUKKAN DATA FILM BARU ---")
    id_m = input("ID Media     : ")
    judul = input("Judul Film   : ")
    tahun = int(input("Tahun Rilis  : "))
    genre = input("Genre        : ")
    durasi = int(input("Durasi (min) : "))
    sutradara = input("Sutradara    : ")
    harga = int(input("Harga Tiket  : "))
    studio = input("Studio       : ")
    rating = input("Rating Usia  : ")

    list_film.append(FilmBioskop(id_m, judul, tahun, genre, durasi, sutradara, harga, studio, rating))

    print("\n--- DATA GABUNGAN SETELAH PENAMBAHAN ---")
    cetak_tabel(list_film)

if __name__ == "__main__":
    main()