#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

struct Kereta {
    int noKereta;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

void swapPointer(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(Kereta *arr, int n) {
    cout << "\n================= JADWAL KERETA =================\n";

    cout << left << setw(12) << "No Kereta"
         << setw(20) << "Nama"
         << setw(15) << "Asal"
         << setw(15) << "Tujuan"
         << setw(10) << "Harga" << endl;

    cout << "---------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(12) << (arr + i)->noKereta
             << setw(20) << (arr + i)->nama
             << setw(15) << (arr + i)->asal
             << setw(15) << (arr + i)->tujuan
             << "Rp" << (arr + i)->harga << endl;
    }

    cout << "===============================================================\n";
}

void tambah(Kereta *arr, int &n) {
    cout << "\nTambah Data Kereta\n";
    cout << "No Kereta : "; cin >> arr[n].noKereta;
    cin.ignore();
    cout << "Nama      : "; getline(cin, arr[n].nama);
    cout << "Asal      : "; getline(cin, arr[n].asal);
    cout << "Tujuan    : "; getline(cin, arr[n].tujuan);
    cout << "Harga     : "; cin >> arr[n].harga;
    n++;
}


void linearSearch(Kereta *arr, int n, string asal, string tujuan) {
    bool ketemu = false;

    cout << "\nProses Linear Search:\n";
    for (int i = 0; i < n; i++) {
        cout << "Cek data ke-" << i+1 << endl;

        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "Ditemukan: " << (arr + i)->nama << endl;
            ketemu = true;
        }
    }

    if (!ketemu) cout << "Data tidak ditemukan!\n";
}

void sortNoKereta(Kereta *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if ((arr + j)->noKereta < (arr + i)->noKereta) {
                swapPointer((arr + i), (arr + j));
            }
        }
    }
}

int jumpSearch(Kereta *arr, int n, int key) {
    int step = sqrt(n);
    int prev = 0;

    while ((arr + min(step, n) - 1)->noKereta < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    for (int i = prev; i < min(step, n); i++) {
        if ((arr + i)->noKereta == key)
            return i;
    }

    return -1;
}

void merge(Kereta *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Kereta L[50], R[50];

    for (int i = 0; i < n1; i++)
        L[i] = *(arr + l + i);
    for (int j = 0; j < n2; j++)
        R[j] = *(arr + m + 1 + j);

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].nama < R[j].nama) {
            *(arr + k) = L[i];
            i++;
        } else {
            *(arr + k) = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        *(arr + k) = L[i];
        i++; k++;
    }

    while (j < n2) {
        *(arr + k) = R[j];
        j++; k++;
    }
}

void mergeSort(Kereta *arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void selectionSort(Kereta *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if ((arr + j)->harga < (arr + minIdx)->harga) {
                minIdx = j;
            }
        }
        swapPointer((arr + i), (arr + minIdx));
    }
}


int main() {
    Kereta data[100] = {  
    };

    int n = 0;
    int pilih;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Jadwal Kereta\n";
        cout << "2. Tambah Data\n";
        cout << "3. Cari asal & tujuan\n";
        cout << "4. Cari No Kereta\n";
        cout << "5. Urutkan Nama\n";
        cout << "6. Urutkan Harga\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            tampil(data, n);
        }
        else if (pilih == 2) {
            tambah(data, n);
        }
        else if (pilih == 3) {
            string asal, tujuan;
            cin.ignore();
            cout << "Asal   : "; getline(cin, asal);
            cout << "Tujuan : "; getline(cin, tujuan);
            linearSearch(data, n, asal, tujuan);
        }
        else if (pilih == 4) {
            int key;
            cout << "Masukkan No Kereta: ";
            cin >> key;

            sortNoKereta(data, n); 

            int hasil = jumpSearch(data, n, key);
            if (hasil != -1)
                cout << "Ditemukan: " << (data + hasil)->nama << endl;
            else
                cout << "Tidak ditemukan!\n";
        }
        else if (pilih == 5) {
            mergeSort(data, 0, n-1);
            cout << "Berhasil diurutkan berdasarkan nama!\n";
        }
        else if (pilih == 6) {
            selectionSort(data, n);
            cout << "Berhasil diurutkan berdasarkan harga!\n";
        }

    } while (pilih != 0);

    return 0;
}