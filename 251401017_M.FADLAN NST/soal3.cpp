#include <iostream>
#include <string>
using namespace std;

int main() {
    string kode;
    cout << "Masukkan kode transaksi (8 digit): ";
    cin >> kode;

    // ambil bagian kode
    string hariKode = kode.substr(0,2);   // 2 digit pertama untuk jenis hari
    string loyalKode = kode.substr(2,2);  // 2 digit berikut untuk jenis pelanggan
    int belanja = stoi(kode.substr(4,4)) * 100000; // 4 digit terakhir untuk jumlah belanja (kelipatan 100 ribu)

    string hari, loyal;
    int poinPerUnit = 0;

    // tentukan jenis hari
    if (hariKode=="01") hari="Hari Kerja";
    else if (hariKode=="02") hari="Akhir Pekan";
    else if (hariKode=="03") hari="Hari Libur Nasional";

    // tentukan jenis pelanggan
    if (loyalKode=="01") loyal="Biasa";
    else if (loyalKode=="02") loyal="Silver";
    else if (loyalKode=="03") loyal="Gold";

    // tentukan poin per Rp100.000 sesuai tabel
    if (hari=="Hari Kerja") {
        if (loyal=="Biasa") poinPerUnit=1;
        else if (loyal=="Silver") poinPerUnit=2;
        else poinPerUnit=3;
    } else if (hari=="Akhir Pekan") {
        if (loyal=="Biasa") poinPerUnit=2;
        else if (loyal=="Silver") poinPerUnit=3;
        else poinPerUnit=5;
    } else { // Hari Libur Nasional
        if (loyal=="Biasa") poinPerUnit=3;
        else if (loyal=="Silver") poinPerUnit=5;
        else poinPerUnit=7;
    }

    // hitung total poin
    int totalPoin = (belanja/100000) * poinPerUnit;

    // tampilkan hasil
    cout << "Jenis Hari: " << hari << endl;
    cout << "Jenis Pelanggan: " << loyal << endl;
    cout << "Jumlah Belanja: Rp " << belanja << endl;
    cout << "Total Poin: " << totalPoin << endl;

    return 0;
}

/*
Catatan logika program:
- Input kode transaksi (8 digit).
- 2 digit pertama untuk jenis hari (kerja/akhir pekan/libur nasional).
- 2 digit berikut untuk jenis pelanggan (biasa/silver/gold).
- 4 digit terakhir untuk jumlah belanja (dikalikan Rp100.000).
- Tentukan poin per Rp100.000 sesuai tabel.
  */
- Hitung total poin = (jumlah belanja / 100.000) * poin per unit.
- tampilkan hasil lengkap.
