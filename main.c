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

// Fungsi untuk membersihkan layar
void clrscr() {
    printf("\033[H\033[J");
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

int main() {
    int pilihan, a, b, hasil, suku_awal, beda, jumlah_suku;
    int pilihan_sebelumnya = -1; // Menyimpan pilihan sebelumnya

    // Loop untuk menampilkan menu utama hingga pengguna memilih keluar
    do {
        if (pilihan_sebelumnya != -1) {
            pilihan = pilihan_sebelumnya;
        } else {
            menu(); // Tampilkan menu utama
            printf("Pilih operasi (1-9, 0 untuk keluar): ");
            pilihan = inputAngka();
        }

        if (pilihan >= 1 && pilihan <= 5) {
            printf("Masukkan bilangan pertama: ");
            a = inputAngka();
            printf("Masukkan bilangan kedua: ");
            b = inputAngka();
        }

        switch (pilihan) {
            case 1: // Tambah
                hasil = tambah(a, b);
                printf("Rumus: %d + %d\n", a, b);
                printf("Hasil: %d + %d = %d\n", a, b, hasil);
                break;
            case 2: // Kurang
                hasil = kurang(a, b);
                printf("Rumus: %d - %d\n", a, b);
                printf("Hasil: %d - %d = %d\n", a, b, hasil);
                break;
            case 3: // Kali
                hasil = kali(a, b);
                printf("Rumus: %d * %d\n", a, b);
                printf("Hasil: %d * %d = %d\n", a, b, hasil);
                break;
            case 4: // Bagi
                if (b != 0) {
                    hasil = bagi(a, b);
                    printf("Rumus: %d / %d\n", a, b);
                    printf("Hasil: %d / %d = %d\n", a, b, hasil);
                }
                break;
            case 5: // Faktorial
                printf("Masukkan bilangan: ");
                a = inputAngka();
                printf("Rumus: %d! = %d * (%d-1) * ... * 1\n", a, a);
                hasil = faktorial(a);
                printf("Hasil Faktorial: %d! = %d\n", a, hasil);
                break;
            case 6: // Deret Aritmatika
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
            case 7: // Konversi Suhu
                konversiSuhu();
                break;
            case 8: // Luas Bangun Datar
                luasBangunDatar();
                break;
            case 9: // Skala Peta
                skalaPeta();
                break;
            case 0: // Keluar program
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }

        //kondisi jika user ingin memilih pilihan yang sama.
        if (pilihan != 0) {
            char choice;
            printf("Apakah Anda ingin (U)lang atau (K)embali ke menu? ");
            while (getchar() != '\n'); // Kosongkan buffer input
            scanf("%c", &choice);
            if (choice == 'U' || choice == 'u') {
                pilihan_sebelumnya = pilihan;
            } else if (choice == 'K' || choice == 'k') {
                pilihan_sebelumnya = -1;
                clrscr(); // Clear screen
            } else {
                printf("Pilihan tidak valid. Kembali ke menu utama.\n");
                pilihan_sebelumnya = -1;
                clrscr();
            }
        }
    } while (pilihan != 0);

    return 0;
}

// Fungsi untuk menampilkan menu utama
// Fungsi untuk menampilkan menu utama dengan border tabel lebih besar
void menu() {
    printf("\n+--------------------------------------------------------+\n");
    printf("|                      KALKULATOR C SEDERHANA             |\n");
    printf("+--------------------------------------------------------+\n");
    printf("|  1. Tambah                                              |\n");
    printf("|  2. Kurang                                              |\n");
    printf("|  3. Kali                                                |\n");
    printf("|  4. Bagi                                                |\n");
    printf("|  5. Faktorial                                           |\n");
    printf("|  6. Deret Aritmatika                                    |\n");
    printf("|  7. Konversi Suhu                                       |\n");
    printf("|  8. Luas Bangun Datar                                   |\n");
    printf("|  9. Skala Peta                                          |\n");
    printf("|  0. Keluar                                              |\n");
    printf("+--------------------------------------------------------+\n");
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
    printf("|      KONVERSI SUHU        |\n");
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
    float panjang, lebar, jari_jari, hasil;

    printf("\n+-----------------------------+\n");
    printf("|     LUAS BANGUN DATAR      |\n");
    printf("+-----------------------------+\n");
    printf("Pilih Bangun Datar:\n");
    printf("1. Persegi Panjang\n");
    printf("2. Lingkaran\n");
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
        printf("Masukkan jari-jari lingkaran: ");
        scanf("%f", &jari_jari);
        hasil = 3.14159 * jari_jari * jari_jari;
        printf("Luas Lingkaran: %.2f\n", hasil);
    } else {
        printf("Pilihan tidak valid!\n");
    }
}

// Fungsi untuk menghitung skala pada peta
void skalaPeta() {
    float jarak_peta, jarak_sebenarnya, skala;

    printf("\n+-----------------------------+\n");
    printf("|         SKALA PETA         |\n");
    printf("+-----------------------------+\n");
    printf("Masukkan jarak pada peta (cm): ");
    scanf("%f", &jarak_peta);
    printf("Masukkan jarak sebenarnya (km): ");
    scanf("%f", &jarak_sebenarnya);

    skala = jarak_peta / (jarak_sebenarnya * 100000);
    printf("Skala peta: 1 : %.0f\n", 1 / skala);
}
