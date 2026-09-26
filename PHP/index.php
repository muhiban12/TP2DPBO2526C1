<?php
require_once "FilmBioskop.php";
session_start();

// Reset data jika diperlukan (akses index.php?reset=1)
if (isset($_GET['reset'])) {
    unset($_SESSION['listFilm']);
    header("Location: index.php");
    exit();
}

// Inisialisasi 5 Data Awal dengan Path Gambar Poster Lokal
if (!isset($_SESSION['listFilm']) || !is_array($_SESSION['listFilm'])) {
    $_SESSION['listFilm'] = [
        new FilmBioskop("M001", "Interstellar", 2014, "Sci-Fi", 169, "Christopher Nolan", 50000, "Studio 1", "SU", "images/interstellar.jpg"),
        new FilmBioskop("M002", "Inception", 2010, "Action", 148, "Christopher Nolan", 45000, "Studio 2", "13+", "images/inception.jpg"),
        new FilmBioskop("M003", "The Dark Knight", 2008, "Action", 152, "Christopher Nolan", 50000, "Studio 1", "17+", "images/dark_knight.jpg"),
        new FilmBioskop("M004", "Spirited Away", 2001, "Animation", 125, "Hayao Miyazaki", 40000, "Studio 3", "SU", "images/spirited_away.jpg"),
        new FilmBioskop("M005", "Parasite", 2019, "Thriller", 132, "Bong Joon-ho", 45000, "Studio 2", "17+", "images/parasite.jpg")
    ];
}

// Tambah Data Baru
if (isset($_POST['tambah'])) {
    $_SESSION['listFilm'][] = new FilmBioskop(
        $_POST['idMedia'],
        $_POST['judul'],
        (int)$_POST['tahunRilis'],
        $_POST['genre'],
        (int)$_POST['durasiMenit'],
        $_POST['sutradara'],
        (int)$_POST['hargaTiket'],
        $_POST['studio'],
        $_POST['ratingUsia'],
        $_POST['fotoProduk']
    );
    header("Location: index.php");
    exit();
}
?>
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <title>TP2 DPBO - Sistem Manajemen Film Bioskop</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        table { border-collapse: collapse; width: 100%; margin-top: 15px; }
        th, td { border: 1px solid #333; padding: 10px; text-align: left; vertical-align: middle; }
        th { background-color: #f2f2f2; }
        
        /* CSS Khusus agar SEMUA poster film berukuran presisi & seragam */
        .poster-img {
            width: 80px;
            height: 110px;
            object-fit: cover; /* Memastikan gambar ter-crop rapi tanpa gepeng/distorsi */
            border-radius: 4px;
            display: block;
        }
    </style>
</head>
<body>
    <h2>Daftar Film Bioskop</h2>
    <p><a href="index.php?reset=1">Reset Data Ke Default (Sesuaikan Gambar)</a></p>

    <!-- TABEL TAMPILAN DATA -->
    <table>
        <tr>
            <th>Poster</th>
            <th>ID Media</th>
            <th>Judul</th>
            <th>Tahun Rilis</th>
            <th>Genre</th>
            <th>Durasi</th>
            <th>Sutradara</th>
            <th>Harga Tiket</th>
            <th>Studio</th>
            <th>Rating Usia</th>
        </tr>
        <?php foreach ($_SESSION['listFilm'] as $film): ?>
        <tr>
            <td>
                <img src="<?php echo htmlspecialchars($film->getFotoProduk()); ?>" 
                     alt="Poster <?php echo htmlspecialchars($film->getJudul()); ?>" 
                     class="poster-img">
            </td>
            <td><?php echo htmlspecialchars($film->getIdMedia()); ?></td>
            <td><?php echo htmlspecialchars($film->getJudul()); ?></td>
            <td><?php echo htmlspecialchars($film->getTahunRilis()); ?></td>
            <td><?php echo htmlspecialchars($film->getGenre()); ?></td>
            <td><?php echo htmlspecialchars($film->getDurasiMenit()); ?> min</td>
            <td><?php echo htmlspecialchars($film->getSutradara()); ?></td>
            <td>Rp <?php echo number_format($film->getHargaTiket()); ?></td>
            <td><?php echo htmlspecialchars($film->getStudio()); ?></td>
            <td><?php echo htmlspecialchars($film->getRatingUsia()); ?></td>
        </tr>
        <?php endforeach; ?>
    </table>

    <!-- FORM TAMBAH DATA -->
    <h3>Tambah Data Film Baru</h3>
    <form method="post" action="index.php">
        <label>ID Media:</label><br><input type="text" name="idMedia" required><br><br>
        <label>Judul Film:</label><br><input type="text" name="judul" required><br><br>
        <label>Tahun Rilis:</label><br><input type="number" name="tahunRilis" required><br><br>
        <label>Genre:</label><br><input type="text" name="genre" required><br><br>
        <label>Durasi (Menit):</label><br><input type="number" name="durasiMenit" required><br><br>
        <label>Sutradara:</label><br><input type="text" name="sutradara" required><br><br>
        <label>Harga Tiket:</label><br><input type="number" name="hargaTiket" required><br><br>
        <label>Studio:</label><br><input type="text" name="studio" required><br><br>
        <label>Rating Usia:</label><br><input type="text" name="ratingUsia" required><br><br>
        <label>Path Gambar Poster (contoh: images/poster_baru.jpg):</label><br><input type="text" name="fotoProduk" required><br><br>
        <button type="submit" name="tambah">Tambah Film</button>
    </form>
</body>
</html>