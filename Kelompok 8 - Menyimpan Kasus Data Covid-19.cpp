#include <iostream>
#include <queue>
using namespace std;

void tampilkanMenu();
void tambahKasus(queue<int>& kasus, int arr[], int& counter);
void tampilkanKasus(queue<int> kasus);
int hitungTotalKasus(queue<int> kasus, int arr[], int& counter);

int main()
{
    queue<int> kasus;
    int arr[100] = {0};
    int counter = 0;

    tampilkanMenu();

    int pilihan;
    do {
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahKasus(kasus, arr, counter);
                break;
            case 2:
                tampilkanKasus(kasus);
                break;
            case 3:
                cout << "Total kasus Covid: " << hitungTotalKasus(kasus, arr, counter) << endl;
                break;
            case 4:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }

    } while (pilihan != 4);

    return 0;
}

void tampilkanMenu() {
    cout << "=== Informasi Covid ===" << endl;
    cout << "1. Tambah kasus" << endl;
    cout << "2. Tampilkan kasus" << endl;
    cout << "3. Hitung total kasus" << endl;
    cout << "4. Keluar" << endl;
}

void tambahKasus(queue<int>& kasus, int arr[], int& counter) {
    if (counter == 100) {
        cout << "Tidak dapat menambahkan kasus, batas maksimal sudah tercapai!" << endl;
        return;
    }

    int tambah;
    cout << "Masukkan jumlah kasus yang ingin ditambahkan: ";
    cin >> tambah;

    kasus.push(tambah);
    arr[counter] = tambah;
    counter++;

    cout << "Kasus berhasil ditambahkan!" << endl;
}

void tampilkanKasus(queue<int> kasus) {
    if (kasus.empty()) {
        cout << "Tidak ada kasus Covid yang tercatat." << endl;
        return;
    }

    cout << "Kasus Covid: ";
    while (!kasus.empty()) {
        cout << kasus.front() << " ";
        kasus.pop();
    }
    cout << endl;
}

int hitungTotalKasus(queue<int> kasus, int arr[], int& counter) {
    int total = 0;
    for (int i = 0; i < counter; i++) {
        total += arr[i];
    }

    return total;
}
