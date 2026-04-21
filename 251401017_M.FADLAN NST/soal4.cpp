#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S;
    cout << "Masukkan jumlah babak: ";
    cin >> N;
    cout << "Masukkan hasil tiap babak (string): ";
    cin >> S;

    int poinA = 0, poinB = 0;
    int streakA = 0, streakB = 0; // untuk cek kemenangan beruntun

    for (char c : S) {
        if (c == 'A') {
            poinA += 3;
            streakA++; streakB = 0;
            if (streakA == 3) { // bonus jika menang 3 kali berturut-turut
                poinA += 2;
                streakA = 0;
            }
        } else if (c == 'B') {
            poinB += 3;
            streakB++; streakA = 0;
            if (streakB == 3) {
                poinB += 2;
                streakB = 0;
            }
        } else if (c == 'C') {
            poinA++; poinB++; // seri, masing-masing dapat 1 poin
            streakA = 0; streakB = 0;
        }
    }

    cout << "Poin A: " << poinA << endl;
    cout << "Poin B: " << poinB << endl;
    if (poinA > poinB) cout << "Pemenangnya adalah pemain A" << endl;
    else if (poinB > poinA) cout << "Pemenangnya adalah pemain B" << endl;
    else cout << "Hasil pertandingan Seri!" << endl;

    return 0;
}

/*
Catatan logika program:
- Input jumlah babak (N) dan string hasil tiap babak (S).
- Setiap karakter S:
  'A' → pemain A menang → +3 poin.
  'B' → pemain B menang → +3 poin.
  'C' → seri → masing-masing +1 poin.
- Jika ada pemain menang 3 kali berturut-turut → bonus +2 poin.
- Setelah semua babak selesai, tampilkan poin A dan B.
- kemudian dikatakan pemenang berdasarkan poin akhir.
*/
