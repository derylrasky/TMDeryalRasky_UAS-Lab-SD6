#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int interpolationSearch(vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {

        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + ((double)(high - low) /
                  (arr[high] - arr[low])) * (x - arr[low]);

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

int main() {
    int n;
    cout << "Masukkan jumlah kursi tersedia: ";
    cin >> n;

    vector<int> kursi(n);
    cout << "Masukkan nomor kursi tersedia (urut):\n";
    for(int i = 0; i < n; i++) {
        cin >> kursi[i];
    }

    int cari;
    cout << "Masukkan nomor kursi yang dicari: ";
    cin >> cari;

    int index = interpolationSearch(kursi, cari);

    cout << "\nMencari Kursi No: " << cari << endl;

    if (index != -1) {
        cout << "Status : TERSEDIA\n";
        cout << "Detail : Ditemukan pada index [" << index << "]\n";
    } 
    else {
        cout << "Status : TIDAK TERSEDIA\n";

        int terdekat = kursi[0];
        for (int i = 1; i < kursi.size(); i++) {
            if (abs(kursi[i] - cari) < abs(terdekat - cari))
                terdekat = kursi[i];
        }

        cout << "Opsi : Kursi terdekat yang tersedia adalah No. " << terdekat << endl;
    }

    return 0;
}