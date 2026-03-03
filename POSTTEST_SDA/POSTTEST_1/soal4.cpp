#include <iostream>
using namespace std;

void tukar(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int x = 5, y = 10;

    cout << "Sebelum: x=" << x << " y=" << y << endl;
    tukar(x, y);
    cout << "Sesudah: x=" << x << " y=" << y << endl;

    return 0;
}