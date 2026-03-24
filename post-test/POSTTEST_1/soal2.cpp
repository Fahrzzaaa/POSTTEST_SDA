#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama, nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[5];

    for(int i = 0; i < 5; i++) {
        cout << "Nama : "; cin >> ws; getline(cin, mhs[i].nama);
        cout << "NIM  : "; cin >> mhs[i].nim;
        cout << "IPK  : "; cin >> mhs[i].ipk;
    }

    int max = 0;
    for(int i = 1; i < 5; i++)
        if(mhs[i].ipk > mhs[max].ipk)
            max = i;

    cout << "\nIPK Tertinggi:\n";
    cout << "Nama : " << mhs[max].nama << endl;
    cout << "NIM  : " << mhs[max].nim << endl;
    cout << "IPK  : " << mhs[max].ipk << endl;

    return 0;
}