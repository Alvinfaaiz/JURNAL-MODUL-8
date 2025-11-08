#include <iostream>
#include <string>
#include "header.h"
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    int n;
    cout << "Masukkan banyak pasien yang ingin diinput: ";
    cin >> n;
    cin.ignore(); // bersihkan buffer newline

    for (int i = 1; i <= n; i++) {
        cout << "\nPasien ke-" << i << endl;

        string nama, pekerjaan;
        int usia, nomorAntrean;

        cout << "Nama: ";
        cin >> nama;
        cout << "Usia: ";
        cin >> usia;

        cout << "Pekerjaan: ";
        cin >> pekerjaan;

        cout << "Nomor antrean: ";
        cin >> nomorAntrean;

        // alokasi dan masukkan ke antrian
        address p = allocate(nama, usia, pekerjaan, nomorAntrean);
        enqueue(Q, p);
    }
    cout << "banyak pasien dalam antrean: " << Size(Q) << endl;

    cout << "\n=== HASIL INPUT ANTRIAN ===" << endl;
    cout << "Banyak pasien dalam antrean: " << Size(Q) << endl;

    cout << "\n=== PROSES VAKSINASI (SERVE QUEUE) ===" << endl;
    serveQueue(Q);

    // Setelah sebagian pasien divaksin, antrean berkurang
    cout << "\nSisa pasien dalam antrean: " << Size(Q) << endl;

    // Emergency handle
    int nomorPrioritas;
    cout << "\nMasukkan nomor antrean yang ingin diprioritaskan: ";
    cin >> nomorPrioritas;
    emergencyHandle(Q, nomorPrioritas);

    cout << "\n=== PROSES VAKSINASI SESUDAH EMERGENCY HANDLE ===" << endl;
    serveQueue(Q);

    // Reassign seluruh pasien jadi prioritas
    cout << "\n=== UPDATE SEMUA PASIEN JADI PRIORITAS ===" << endl;
    reassignQueue(Q);
    cout << "Data prioritas pasien telah diupdate.\n";

    cout << "\n=== PROSES VAKSINASI SESUDAH UPDATE PRIORITAS ===" << endl;
    serveQueue(Q);

    cout << "\nSisa pasien dalam antrean: " << Size(Q) << endl;
    cout << "\n=== SEMUA PROSES SELESAI ===" << endl;

    return 0;
}
