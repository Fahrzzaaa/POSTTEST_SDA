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
};

void swapPointer(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(Kereta *arr, int n) {
    cout << "\n=== JADWAL KERETA ===\n";
    for (int i = 0; i < n; i++) {
        cout << (arr+i)->nama << " | "
             << (arr+i)->asal << " -> "
             << (arr+i)->tujuan << endl;
    }
}

void tambah(Kereta *arr, int &n) {
    cout << "No Kereta : "; cin >> arr[n].noKereta;
    cin.ignore();
    cout << "Nama      : "; getline(cin, arr[n].nama);
    cout << "Asal      : "; getline(cin, arr[n].asal);
    cout << "Tujuan    : "; getline(cin, arr[n].tujuan);
    cout << "Harga     : "; cin >> arr[n].harga;
    n++;
}

void enqueue(Tiket *queue, int &rear, string nama, string kereta, string asal, string tujuan) {
    if (rear == MAX-1) {
        cout << "Queue penuh!\n";
        return;
    }

    rear++;
    (queue+rear)->namaPenumpang = nama;
    (queue+rear)->namaKereta = kereta;
    (queue+rear)->asal = asal;
    (queue+rear)->tujuan = tujuan;

    cout << "Masuk antrian.\n";
}

void dequeue(Tiket *queue, int &front, int &rear, Tiket *stack, int &top) {
    if (front > rear) {
        cout << "Antrian kosong!\n";
        return;
    }

    Tiket temp = *(queue+front);

    cout << "Diproses: " << temp.namaPenumpang
         << " | " << temp.asal << " -> " << temp.tujuan << endl;

    if (top < MAX-1) {
        top++;
        *(stack+top) = temp;
    }

    for (int i = front; i < rear; i++) {
        *(queue+i) = *(queue+i+1);
    }

    rear--;
}

void tampilQueue(Tiket *queue, int front, int rear) {
    if (front > rear) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\n=== ANTRIAN ===\n";
    for (int i = front; i <= rear; i++) {
        cout << (queue+i)->namaPenumpang
             << " | " << (queue+i)->asal
             << " -> " << (queue+i)->tujuan << endl;
    }
}

void peekQueue(Tiket *queue, int front, int rear) {
    if (front > rear) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "Terdepan: " << (queue+front)->namaPenumpang << endl;
}

void push(Tiket *stack, int &top, Tiket data) {
    if (top == MAX-1) {
        cout << "Stack penuh!\n";
        return;
    }

    top++;
    *(stack+top) = data;
}

void pop(Tiket *stack, int &top) {
    if (top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Dihapus: " << (stack+top)->namaPenumpang << endl;
    top--;
}

void tampilStack(Tiket *stack, int top) {
    if (top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "\n=== RIWAYAT ===\n";
    for (int i = top; i >= 0; i--) {
        cout << (stack+i)->namaPenumpang
             << " | " << (stack+i)->asal
             << " -> " << (stack+i)->tujuan << endl;
    }
}

void peekStack(Tiket *stack, int top) {
    if (top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Terakhir: " << (stack+top)->namaPenumpang << endl;
}

int main() {
    Kereta data[100];
    Tiket queue[MAX];
    Tiket stack[MAX];

    int n = 0;
    int front = 0, rear = -1;
    int top = -1;

    int pilih;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Tambah Kereta\n";
        cout << "2. Tampil Kereta\n";
        cout << "3. menambahkan tiket\n";
        cout << "4. menghapus data tiket paling depan\n";
        cout << "5. Tampil Antrian\n";
        cout << "6. Tampil Riwayat\n";
        cout << "7. riwayat transaksi\n";
        cout << "8. melihat data penumpang paling depan\n";
        cout << "9. melihat data paling atas\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            tambah(data, n);
        }
        else if (pilih == 2) {
            tampil(data, n);
        }
        else if (pilih == 3) {
            string nama, asal, tujuan, kereta;

            cout << "Nama Penumpang: "; getline(cin, nama);
            cout << "Nama Kereta   : "; getline(cin, kereta);
            cout << "Asal          : "; getline(cin, asal);
            cout << "Tujuan        : "; getline(cin, tujuan);

            enqueue(queue, rear, nama, kereta, asal, tujuan);
        }
        else if (pilih == 4) {
            dequeue(queue, front, rear, stack, top);
        }
        else if (pilih == 5) {
            tampilQueue(queue, front, rear);
        }
        else if (pilih == 6) {
            tampilStack(stack, top);
        }
        else if (pilih == 7) {
            pop(stack, top);
        }
        else if (pilih == 8) {
            peekQueue(queue, front, rear);
        }
        else if (pilih == 9) {
            peekStack(stack, top);
        }

    } while (pilih != 0);

    return 0;
}