#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* start = arr;
    int* end = arr + n - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void tampil(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << "Nilai: " << *(arr + i)
             << " | Alamat: " << (arr + i) << endl;
    }
    cout << endl;
}

int main() {
    int A[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array Sebelum Dibalik:\n";
    tampil(A, 7);

    reverseArray(A, 7);

    cout << "Array Sesudah Dibalik:\n";
    tampil(A, 7);

    return 0;
}