#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    system("cls");
    string kode;
    int jamKeluar;
    cout << "Masukkan kode parkir digital (10 digit): ";
    cin >> kode;
    cout << "Masukkan jam keluar (format HHMM): ";
    cin >> jamKeluar;

    // tentukan jenis kendaraan dari 2 digit pertama
    string jenis;
    int tarifAwal, tarifLanjut;
    string jenisKode = kode.substr(0,2);
    if (jenisKode == "10") { jenis = "Mobil"; tarifAwal=5000; tarifLanjut=3000; }
    else if (jenisKode == "20") { jenis = "Motor"; tarifAwal=3000; tarifLanjut=2000; }
    else if (jenisKode == "30") { jenis = "Bus"; tarifAwal=10000; tarifLanjut=7000; }

    // ambil jam dan menit masuk dari digit ke-3 sampai ke-6
    int jamMasuk = stoi(kode.substr(2,2));
    int menitMasuk = stoi(kode.substr(4,2));
    // ambil lokasi parkir dari digit ke-7 sampai ke-10
    int lokasi = stoi(kode.substr(6,4));

    // pisahkan jam keluar jadi jam dan menit
    int jamKeluarH = jamKeluar/100;
    int menitKeluar = jamKeluar%100;

    // hitung durasi dalam menit lalu ubah ke jam (dibulatkan ke atas)
    int durasi = (jamKeluarH*60+menitKeluar) - (jamMasuk*60+menitMasuk);
    int jamTotal = (durasi+59)/60; // pembulatan ke atas

    // hitung biaya: jam pertama tarif awal, sisanya tarif lanjut
    int biaya = tarifAwal + (jamTotal>1 ? (jamTotal-1)*tarifLanjut : 0);

    // tampilkan ringkasan
    cout << "--- Ringkasan Parkir ---\n";
    cout << "Jenis kendaraan: " << jenis << endl;
    cout << "Waktu masuk: " << jamMasuk << ":" << menitMasuk << endl;
    cout << "Waktu keluar: " << jamKeluarH << ":" << menitKeluar << endl;
    cout << "Durasi parkir: " << jamTotal << " jam" << endl;
    cout << "Lokasi parkir: " << lokasi << endl;
    cout << "Total biaya: Rp " << biaya << endl;

    return 0;
}

/*
Catatan logika program:
- Input kode parkir (10 digit) dan jam keluar.
- 2 digit pertama untuk jenis kendaraan (Mobil/Motor/Bus).
- 4 digit berikut untuk jam dan menit masuk.
- 4 digit terakhir untuk lokasi parkir.
- Hitung durasi parkir dari jam masuk sampai jam keluar.
- Biaya: jam pertama tarif awal, jam berikutnya tarif lanjut.
- Cetak ringkasan sesuai format.
  */
