#include <iostream>
using namespace std;

/*
Analisis Kompleksitas:

Baris penting:
- Inisialisasi min → 1 kali
- Perulangan → (n-1) kali
- Perbandingan → (n-1) kali
- Update min → 0 (best) / (n-1) (worst)

Tmin(n) = 2n  → O(n)
Tmax(n) = 3n  → O(n)

Kesimpulan:
Best case dan worst case sama-sama O(n)
karena tetap memeriksa semua elemen.
*/

int FindMin(int A[], int n, int &indexMin) {
    int min = A[0];
    indexMin = 0;

    for(int i = 1; i < n; i++) {
        if(A[i] < min) {
            min = A[i];
            indexMin = i;
        }
    }
    return min;
}

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int indexMin;

    int minimum = FindMin(A, 8, indexMin);

    cout << "Nilai minimum : " << minimum << endl;
    cout << "Indeks minimum : " << indexMin << endl;

    return 0;
}