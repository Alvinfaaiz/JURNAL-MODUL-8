#include <iostream>

#include "header.h"
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);
    address p;
    infotype x;
    int nomor, n, i, jml;
    string nama, pekerjaan;
    int usia, nomorAntrean;

    cout << "masukkan banyak pasien yang ingin di input: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string nama, pekerjaan;
        int usia, nomorAntrean;

        cout << "\npasien ke-" << i << endl;

        cout << "nama: ";
        cin >> nama;

        cout << "usia: ";
        cin >> usia;

        cout << "pekerjaan: ";
        cin >> pekerjaan;

        cout << "nomor antrean: ";
        cin >> nomorAntrean;

        p = allocate(nama, usia, pekerjaan, nomorAntrean);
        enqueue(Q, p);
    }
    cout << endl;
    cout << "\nbanyak pasien dalam antrean: " << Size(Q) << endl;
    cout << endl;

    serveQueue(Q);
    cout << endl;
    cout << endl;

    cout << "\nmasukkan nomor antrean yang ingin di prioritaskan: ";
    cin >> nomor;
    emergencyHandle(Q, nomor);
    serveQueue(Q);

    cout << endl;
    cout << endl;


    reassignQueue(Q);
    serveQueue(Q);

    return 0;
}
