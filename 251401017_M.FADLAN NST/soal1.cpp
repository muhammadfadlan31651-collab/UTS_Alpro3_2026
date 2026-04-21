#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;

int main() {
    system("cls"); 
    string nomor;
    cout << "Masukkan nomor kartu digital: ";
    cin >> nomor;

    string tipe;
    if (nomor.size() == 14 && nomor.substr(0,2) == "65") tipe = "NUSANTARA";
    else if (nomor.size() == 16 && (nomor.substr(0,2) == "77" || nomor.substr(0,2) == "78")) tipe = "GARUDA";
    else if (nomor.size() == 15 && nomor.substr(0,2) == "91") tipe = "MERDEKA";
    else tipe = "Tidak diketahui";

    cout << "Tipe kartu: " << tipe << endl;

    int total = 0;
    bool kalikan = false; // penanda apakah digit dikali 2 atau tidak
    for (int i = nomor.size()-1; i >= 0; i--) {
        int digit = nomor[i] - '0';
        if (kalikan) {
            digit *= 2;
            if (digit > 9) digit = (digit/10) + (digit%10); // pecah jadi jumlah digit
        }
        total += digit;
        kalikan = !kalikan; // selang-seling
    }

    if (total % 10 == 0) cout << "Nomor kartu VALID." << endl;
    else cout << "Nomor kartu TIDAK VALID." << endl;

    return 0;
}

/*
Langkah program:
1. Ambil input nomor kartu.
2. Tentukan jenis kartu dari panjang digit + angka awal (prefix).
3. Lakukan pengecekan dengan pola Luhn yang dimodifikasi:
   - Mulai dari digit kedua dari belakang, kalikan selang-seling dengan 2.
   - Kalau hasil > 9, pecah jadi jumlah digit.
   - Tambahkan semua hasil dengan digit lain.
4. Jika total kelipatan 10 = kartu valid, kalau tidak = kartu tidak valid.
*/     
