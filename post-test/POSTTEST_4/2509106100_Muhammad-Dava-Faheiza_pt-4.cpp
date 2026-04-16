#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int MAX = 100;

struct Kereta {
    int noKereta;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

struct Tiket {
    string namaPenumpang;
    string namaKereta;
    string asal;
    string tujuan;
    Tiket* next;
};

void swapPointer(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(Kereta *arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta.\n";
        return;
    }

    cout << "\n================= JADWAL KERETA =================\n";
    cout << left << setw(12) << "No Kereta"
         << setw(20) << "Nama"
         << setw(15) << "Asal"
         << setw(15) << "Tujuan"
         << setw(10) << "Harga" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(12) << arr[i].noKereta
             << setw(20) << arr[i].nama
             << setw(15) << arr[i].asal
             << setw(15) << arr[i].tujuan
             << "Rp" << arr[i].harga << endl;
    }
}

void tambah(Kereta *arr, int &n) {
    if (n == MAX) {
        cout << "Data penuh!\n";
        return;
    }

    cout << "\nTambah Data Kereta\n";
    cout << "No Kereta : ";
    cin >> arr[n].noKereta;
    cin.ignore();

    cout << "Nama      : ";
    getline(cin, arr[n].nama);

    cout << "Asal      : ";
    getline(cin, arr[n].asal);

    cout << "Tujuan    : ";
    getline(cin, arr[n].tujuan);

    cout << "Harga     : ";
    cin >> arr[n].harga;

    n++;
    cout << "Data berhasil ditambahkan.\n";
}

void linearSearch(Kereta *arr, int n, string asal, string tujuan) {
    bool ketemu = false;

    for (int i = 0; i < n; i++) {
        if (arr[i].asal == asal && arr[i].tujuan == tujuan) {
            cout << "Ditemukan: " << arr[i].nama << endl;
            ketemu = true;
        }
    }

    if (!ketemu)
        cout << "Data tidak ditemukan!\n";
}

void sortNoKereta(Kereta *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j].noKereta < arr[i].noKereta) {
                swapPointer(&arr[i], &arr[j]);
            }
        }
    }
}

int jumpSearch(Kereta *arr, int n, int key) {
    if (n == 0) return -1;

    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1].noKereta < key) {
        prev = step;
        step += sqrt(n);

        if (prev >= n)
            return -1;
    }

    for (int i = prev; i < min(step, n); i++) {
        if (arr[i].noKereta == key)
            return i;
    }

    return -1;
}

void selectionSort(Kereta *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j].harga < arr[minIdx].harga) {
                minIdx = j;
            }
        }

        swapPointer(&arr[i], &arr[minIdx]);
    }
}

void enqueue(Tiket* &front, Tiket* &rear, string nama, Kereta *kereta) {
    Tiket* baru = new Tiket;
    baru->namaPenumpang = nama;
    baru->namaKereta = kereta->nama;
    baru->asal = kereta->asal;
    baru->tujuan = kereta->tujuan;
    baru->next = NULL;

    if (rear == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "Berhasil masuk antrian.\n";
}

void push(Tiket* &top, Tiket* dataTiket) {
    Tiket* baru = new Tiket;
    *baru = *dataTiket;
    baru->next = top;
    top = baru;
}

void dequeue(Tiket* &front, Tiket* &rear, Tiket* &top) {
    if (front == NULL) {
        cout << "Antrian kosong! (Underflow)\n";
        return;
    }

    Tiket* hapus = front;

    cout << "\nMemproses tiket:\n";
    cout << "Nama   : " << hapus->namaPenumpang << endl;
    cout << "Kereta : " << hapus->namaKereta << endl;
    cout << "Rute   : " << hapus->asal << " -> " << hapus->tujuan << endl;

    push(top, hapus);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete hapus;

    cout << "Tiket berhasil diproses dan masuk riwayat.\n";
}

void pop(Tiket* &top) {
    if (top == NULL) {
        cout << "Riwayat kosong! (Underflow)\n";
        return;
    }

    Tiket* hapus = top;

    cout << "Menghapus riwayat: " << hapus->namaPenumpang << endl;

    top = top->next;
    delete hapus;
}

void peekQueue(Tiket* front) {
    if (front == NULL) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "Antrian terdepan: " << front->namaPenumpang << endl;
}

void peekStack(Tiket* top) {
    if (top == NULL) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Transaksi terakhir: " << top->namaPenumpang << endl;
}

void tampilQueue(Tiket* front) {
    if (front == NULL) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\n===== ANTRIAN =====\n";
    int no = 1;

    while (front != NULL) {
        cout << no++ << ". "
             << front->namaPenumpang << " | "
             << front->namaKereta << " | "
             << front->asal << " -> "
             << front->tujuan << endl;

        front = front->next;
    }
}

void tampilRiwayat(Tiket* top) {
    if (top == NULL) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "\n===== RIWAYAT =====\n";
    int no = 1;

    while (top != NULL) {
        cout << no++ << ". "
             << top->namaPenumpang << " | "
             << top->namaKereta << " | "
             << top->asal << " -> "
             << top->tujuan << endl;

        top = top->next;
    }
}

int main() {
    Kereta data[MAX];
    int n = 0;

    Tiket* front = NULL;
    Tiket* rear = NULL;
    Tiket* top = NULL;

    int pilih;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Jadwal Kereta\n";
        cout << "2. Tambah Data\n";
        cout << "3. Cari Asal & Tujuan\n";
        cout << "4. Cari No Kereta\n";
        cout << "5. Urutkan Harga\n";
        cout << "6. Beli Tiket\n";
        cout << "7. Proses Tiket\n";
        cout << "8.melihat antrian paling depan\n";
        cout << "9. Tampil Antrian\n";
        cout << "10. Tampil Riwayat\n";
        cout << "11. Hapus Riwayat\n";
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
            cout << "Asal   : ";
            getline(cin, asal);
            cout << "Tujuan : ";
            getline(cin, tujuan);
            linearSearch(data, n, asal, tujuan);
        }
        else if (pilih == 4) {
            int key;
            cout << "No Kereta: ";
            cin >> key;

            sortNoKereta(data, n);
            int hasil = jumpSearch(data, n, key);

            if (hasil != -1)
                cout << "Ditemukan: " << data[hasil].nama << endl;
            else
                cout << "Tidak ditemukan!\n";
        }
        else if (pilih == 5) {
            selectionSort(data, n);
            cout << "Berhasil diurutkan berdasarkan harga.\n";
        }
        else if (pilih == 6) {
            string nama;
            int nomor;

            cin.ignore();
            cout << "Nama Penumpang : ";
            getline(cin, nama);

            cout << "No Kereta      : ";
            cin >> nomor;

            sortNoKereta(data, n);
            int idx = jumpSearch(data, n, nomor);

            if (idx != -1)
                enqueue(front, rear, nama, &data[idx]);
            else
                cout << "Kereta tidak ditemukan!\n";
        }
        else if (pilih == 7) {
            dequeue(front, rear, top);
        }
        else if (pilih == 8) {
            peekQueue(front);
            peekStack(top);
        }
        else if (pilih == 9) {
            tampilQueue(front);
        }
        else if (pilih == 10) {
            tampilRiwayat(top);
        }
        else if (pilih == 11) {
            pop(top);
        }

    } while (pilih != 0);

    return 0;
}