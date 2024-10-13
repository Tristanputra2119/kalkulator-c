#include <stdio.h>

// Deklarasi fungsi yang akan digunakan
void menu(); // Tampilkan menu utama
int tambah(int a, int b); // Operasi penjumlahan
int kurang(int a, int b); // Operasi pengurangan
int kali(int a, int b); // Operasi perkalian
int bagi(int a, int b); // Operasi pembagian
int faktorial(int n); // Menghitung faktorial
void deretAritmatika(int suku_awal, int beda, int jumlah_suku); // Menghitung deret aritmatika
void konversiSuhu(); // Konversi suhu
void luasBangunDatar(); // Menghitung luas bangun datar
void skalaPeta(); // Menghitung skala pada peta
void clrscr() {
    printf("\e[1;1H\e[2J"); // untuk clear screen setelah user selesai melakukan perhitungan
}


// Fungsi untuk validasi input
int inputAngka() {
    int angka;
    while (scanf("%d", &angka) != 1) { // Cek apakah input adalah integer
        printf("Error: Masukkan angka yang valid!\n");
        while (getchar() != '\n'); // Kosongkan buffer input
        printf("Masukkan lagi: ");
    }
    return angka;
}

// Kode utama dan fungsi lainnya tetap sama...

int main() {
    int pilihan, last_pilihan = -1, a, b, hasil, suku_awal, beda, jumlah_suku;

    // Loop untuk menampilkan menu utama hingga pengguna memilih keluar
    do {
        if (last_pilihan == -1) { // Jika tidak ada operasi yang tersimpan
            menu(); // Tampilkan menu utama
            printf("Pilih operasi (1-9, 0 untuk keluar): ");
            pilihan = inputAngka();
            last_pilihan = pilihan; // Simpan pilihan terakhir
        } else {
            pilihan = last_pilihan; // Gunakan pilihan terakhir untuk "Ulang"
        }

        // Jika pilihan memerlukan dua input, minta masukan dari pengguna
        if (pilihan >= 1 && pilihan <= 4) {
            printf("Masukkan bilangan pertama: ");
            a = inputAngka();
            printf("Masukkan bilangan kedua: ");
            b = inputAngka();
        }

        // Jika pembagian dengan nol, tampilkan pesan error
        if (pilihan == 4 && b == 0) {
            printf("Error: Pembagi tidak boleh nol.\n");
            last_pilihan = -1;
            continue;
        }

        // Lakukan operasi sesuai pilihan
        switch (pilihan) {
            case 1:
                hasil = tambah(a, b);
                printf("Rumus: %d + %d\n", a, b);
                printf("Hasil: %d + %d = %d\n", a, b, hasil);
                break;
            case 2:
                hasil = kurang(a, b);
                printf("Rumus: %d - %d\n", a, b);
                printf("Hasil: %d - %d = %d\n", a, b, hasil);
                break;
            case 3:
                hasil = kali(a, b);
                printf("Rumus: %d * %d\n", a, b);
                printf("Hasil: %d * %d = %d\n", a, b, hasil);
                break;
            case 4:
                hasil = bagi(a, b);
                printf("Rumus: %d / %d\n", a, b);
                printf("Hasil: %d / %d = %d\n", a, b, hasil);
                break;
            case 5:
                printf("Masukkan bilangan: ");
                a = inputAngka();
                if (a < 0) {
                    printf("Error: Faktorial tidak terdefinisi untuk angka negatif.\n");
                    break;
                }
                if (a == 0) { // ## tambahan
                    printf("Rumus: 0! = 1\n"); // ## tambahan
                    break; // ## tambahan
                } // ## tambahan
                printf("Rumus: %d! = ", a);
                for (int i = a; i > 1; i--) {
                    printf("%d * ", i); // Menampilkan angka dan simbol *
                }
                printf("1 = ");
                hasil = faktorial(a);
                // printf("%d!\n", hasil); // ## sebelumnya
                printf("%d\n", hasil);
                break;
            case 6:
                printf("Masukkan suku atau angka awal: ");
                suku_awal = inputAngka();
                printf("Masukkan beda antar suku: ");
                beda = inputAngka();
                printf("Masukkan jumlah suku dalam deret: ");
                jumlah_suku = inputAngka();
                printf("Rumus Deret Aritmatika: Un = U1 + (n - 1) * b\n");
                printf("U1 = %d, b = %d, n = %d\n", suku_awal, beda, jumlah_suku);
                deretAritmatika(suku_awal, beda, jumlah_suku);
                break;
            case 7:
                konversiSuhu();
                break;
            case 8:
                luasBangunDatar();
                break;
            case 9:
                skalaPeta();
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                last_pilihan = -1;
        }

        // Tanyakan apakah ingin mengulang atau kembali ke menu
        if (pilihan != 0) {
            char choice;
            printf("Apakah Anda ingin (U)lang atau (K)embali ke menu? ");
            while (getchar() != '\n'); // Kosongkan buffer input
            scanf("%c", &choice);
            if (choice == 'U' || choice == 'u') {
                continue; // Ulangi operasi yang sama
            } else if (choice == 'K' || choice == 'k') {
                last_pilihan = -1; // Reset ke menu utama
                clrscr(); // Clear screen
            } else {
                printf("Pilihan tidak valid. Kembali ke menu utama.\n");
                last_pilihan = -1;
                clrscr();
            }
        }

    } while (pilihan != 0);

    return 0;
}

// Fungsi untuk menampilkan menu utama dengan border tabel
void menu() {
    printf("\n+-----------------------------------------+\n");
    // printf("|            KALKULATOR C SEDERHANA       |\n"); // ## sebelumnya
    printf("|          KALKULATOR C SEDERHANA         |\n");
    printf("+-----------------------------------------+\n");
    printf("| 1. Tambah                               |\n");
    printf("| 2. Kurang                               |\n");
    printf("| 3. Kali                                 |\n");
    printf("| 4. Bagi                                 |\n");
    printf("| 5. Faktorial                            |\n");
    printf("| 6. Deret Aritmatika                     |\n");
    printf("| 7. Konversi Suhu                        |\n");
    printf("| 8. Luas Bangun Datar                    |\n");
    printf("| 9. Skala Peta                           |\n");
    printf("| 0. Keluar                               |\n");
    printf("+-----------------------------------------+\n");
}

// Fungsi operasi dasar
int tambah(int a, int b) {
    return a + b;
}

int kurang(int a, int b) {
    return a - b;
}

int kali(int a, int b) {
    return a * b;
}

int bagi(int a, int b) {
    if (b != 0)
        return a / b;
    else {
        printf("Error: Pembagi tidak boleh nol.\n");
        return 0;
    }
}

// Fungsi untuk menghitung faktorial secara rekursif
int faktorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * faktorial(n - 1);
}

// Fungsi untuk menampilkan deret aritmatika
void deretAritmatika(int suku_awal, int beda, int jumlah_suku) {
    printf("Deret Bilangan Aritmatika: ");
    for (int i = 0; i < jumlah_suku; i++) {
        printf("%d ", suku_awal + i * beda);
    }
    printf("\n");
}

// Fungsi untuk konversi suhu
void konversiSuhu() {
    int pilihan;
    float suhu, hasil;

    printf("\n+----------------------------+\n");
    // printf("|      KONVERSI SUHU           |\n"); // ## sebelumnya
    printf("|      KONVERSI SUHU          |\n");
    printf("+----------------------------+\n");
    printf("Pilih Konversi Suhu:\n");
    printf("1. Celsius ke Fahrenheit\n");
    printf("2. Fahrenheit ke Celsius\n");
    printf("Masukkan pilihan: ");
    pilihan = inputAngka();

    if (pilihan == 1) {
        printf("Masukkan suhu dalam Celsius: ");
        scanf("%f", &suhu);
        hasil = (suhu * 9 / 5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n", suhu, hasil);
    } else if (pilihan == 2) {
        printf("Masukkan suhu dalam Fahrenheit: ");
        scanf("%f", &suhu);
        hasil = (suhu - 32) * 5 / 9;
        printf("%.2f Fahrenheit = %.2f Celsius\n", suhu, hasil);
    } else {
        printf("Pilihan tidak valid!\n");
    }
}

// Fungsi untuk menghitung luas bangun datar
void luasBangunDatar() {
    int pilihan;
    float panjang, lebar, alas, tinggi, jari_jari, hasil;

    printf("\n+----------------------------+\n");
    printf("|     LUAS BANGUN DATAR       |\n");
    printf("+----------------------------+\n");
    printf("Pilih Bangun Datar:\n");
    printf("1. Persegi Panjang\n");
    printf("2. Segitiga\n");
    printf("3. Lingkaran\n");
    printf("Masukkan pilihan: ");
    pilihan = inputAngka();

    if (pilihan == 1) {
        printf("Masukkan panjang: ");
        scanf("%f", &panjang);
        printf("Masukkan lebar: ");
        scanf("%f", &lebar);
        hasil = panjang * lebar;
        printf("Luas Persegi Panjang: %.2f\n", hasil);
    } else if (pilihan == 2) {
        printf("Masukkan alas: ");
        scanf("%f", &alas);
        printf("Masukkan tinggi: ");
        scanf("%f", &tinggi);
        hasil = (alas * tinggi) / 2;
        printf("Luas Segitiga: %.2f\n", hasil);
    } else if (pilihan == 3) {
        printf("Masukkan jari-jari: ");
        scanf("%f", &jari_jari);
        hasil = 3.14 * jari_jari * jari_jari;
        printf("Luas Lingkaran: %.2f\n", hasil);
    } else {
        printf("Pilihan tidak valid!\n");
    }
}

// Fungsi untuk menghitung skala pada peta
void skalaPeta() {
    float jarakPeta, jarakSebenarnya, skala;

    printf("\n+----------------------------+\n");
    printf("|       SKALA PADA PETA       |\n");
    printf("+----------------------------+\n");
    printf("Masukkan jarak pada peta (cm): ");
    scanf("%f", &jarakPeta);
    printf("Masukkan jarak sebenarnya (km): ");
    scanf("%f", &jarakSebenarnya);

    skala = jarakPeta / (jarakSebenarnya * 100000);
    printf("Skala Peta: 1:%.0f\n", 1 / skala);
}
