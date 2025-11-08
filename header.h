#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct elmqueue *address;

struct infotype {
    string nama;
    int usia;
    string pekerjaan;
    bool prioritas;
    int nomorAntrean;
};

struct Queue{
    address head;
    address tail;
};

struct elmqueue{
    infotype info;
    address next;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
address allocate(string nama, int usia, string pekerjaan, int nomorAntrean);
address Front(Queue Q);
address Back(Queue Q);
void enqueue(Queue &Q, address p);
void dequeue(Queue &Q, address p);
int Size(Queue Q);
void printPatient(address p);
void serveQueue(Queue &Q);
void reassignQueue(Queue &Q);
void emergencyHandle(Queue &Q, int nomorAntrian);


#endif // HEADER_H_INCLUDED
