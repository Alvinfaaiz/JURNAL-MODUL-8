#include "header.h"
#include <iostream>

using namespace std;

void createQueue(Queue &Q){
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(Queue Q){
    return (Q.head == nullptr) && (Q.tail == nullptr);
}

address allocate(string nama, int usia, string pekerjaan, int nomorAntrean){
    address p;
    infotype x;

    p = new elmqueue;
    x.nama = nama;
    x.usia = usia;
    x.pekerjaan = pekerjaan;
    x.prioritas = (usia >= 60) || pekerjaan == "tenaga_kesehatan";
    x.nomorAntrean = nomorAntrean;
    p->info = x;
    p->next = nullptr;

    return p;
}

address Front(Queue Q){
    return Q.head;
}

address Back(Queue Q){
    return Q.tail;
}

void enqueue(Queue &Q, address p){
    address temp;
    bool inputPasienBukanPrioritas;
    bool semuaPasienPrioritas;
    bool tidakAdaPasienPrioritas;

    if(!isEmpty(Q)){
    inputPasienBukanPrioritas =! p->info.prioritas;
    semuaPasienPrioritas = Q.tail->info.prioritas;
    tidakAdaPasienPrioritas =! Q.head->info.prioritas;
    }

    if (isEmpty(Q)){
        Q.head = p;
        Q.tail = p;
    }else if(inputPasienBukanPrioritas || semuaPasienPrioritas){
        Q.tail->next = p;
        Q.tail = p;
    }else if(tidakAdaPasienPrioritas){
        p->next = Q.head;
        Q.head = p;
    }else{
        temp = Q.head;

        while(temp->next != nullptr && temp->next->info.prioritas){
            temp = temp->next;
        }

        p->next = temp->next;
        temp->next = p;
    }
}

void dequeue(Queue &Q, address p){
    if(!isEmpty(Q)){
        p = Q.head;
        Q.head = p->next;

        if(Q.head == nullptr){
            Q.tail = nullptr;
        }
    }else{
        p = nullptr;
    }
}

int Size(Queue Q){
    int Count;
    address p;

    Count = 0;
    p = Q.head;

    while(p != nullptr){
        Count = Count + 1;
        p = p->next;
    }

    return Count;
}

void printPatient(address p){
        if (p != nullptr) {
            cout << "Nama: " << p->info.nama << endl;
            cout << "Usia: " << p->info.usia << endl;
            cout << "Pekerjaan: " << p->info.pekerjaan << endl;
            cout << "Prioritas: " << p->info.prioritas<< endl;
            cout << "Nomor Antrian: " << p->info.nomorAntrean << endl;
            cout << "Vaksinasi berhasil." << endl;
    }
}

void serveQueue(Queue &Q){
    int count = 0;
    address p;

    while (!isEmpty(Q) && count < 5) {
        p = Q.head;
        printPatient(p);
        cout << "Vaksinasi berhasil." << endl << endl;
        cout << "-----------------------------" << endl;
        dequeue(Q, p);
        count++;
    }

    if (count == 0)
        cout << "Tidak ada warga dalam antrean." << endl;
}

void reassignQueue(Queue &Q){
    address p = Q.head;
    while (p != nullptr) {
        if (!p->info.prioritas) {
            p->info.prioritas = true;
        }
        p = p->next;
    }
    cout << "data prioritas pasien telah di update." << endl;
}

void emergencyHandle(Queue &Q, int nomorAntrean) {
    if (isEmpty(Q)) return;

    address prev = nullptr;
    address curr = Q.head;


    while (curr != nullptr && curr->info.nomorAntrean != nomorAntrean) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Nomor antrean " << nomorAntrean << " tidak ditemukan." << endl;
        return;
    }

    curr->info.prioritas = true;

    if (curr == Q.head) return;

    if (curr == Q.tail) {
        Q.tail = prev;
    }
    if (prev != nullptr) {
        prev->next = curr->next;
    }

    curr->next = Q.head;
    Q.head = curr;

    cout << "Pasien dengan nomor antrean " <<endl;
}


