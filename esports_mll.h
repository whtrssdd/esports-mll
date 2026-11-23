#ifndef ESPORTS_MLL_H
#define ESPORTS_MLL_H

#include <string>
using namespace std;

// ---------------------------------------------------------------------
// ADT Multi Linked List (List to List)
// ---------------------------------------------------------------------

// Child: elemen Pertandingan
struct Pertandingan {
    int id;             // kunci child (unik di dalam satu turnamen)
    string timA;
    string timB;
    int skorA;
    int skorB;
    string status;      // Dijadwalkan / Berlangsung / Selesai
    Pertandingan* next; // pointer ke child berikutnya
};

// Parent: elemen Turnamen
struct Turnamen {
    int id;                  // kunci parent (unik)
    string nama;
    string game;
    long long prizePool;
    Pertandingan* childHead; // pointer penghubung ke daftar child
    Turnamen* next;          // pointer ke parent berikutnya
};

// List utama (Parent List)
struct ListTurnamen {
    Turnamen* head;
};

// ---------------------------------------------------------------------
// Deklarasi Operasi Pembuatan Elemen
// ---------------------------------------------------------------------
Turnamen* createParent(int id, const string& nama, const string& game, long long prizePool);
Pertandingan* createChild(int id, const string& timA, const string& timB,
                          int skorA, int skorB, const string& status);

// ---------------------------------------------------------------------
// Deklarasi Operasi Parent List
// ---------------------------------------------------------------------
Turnamen* findParent(const ListTurnamen& L, int id);
Turnamen* findParentByNama(const ListTurnamen& L, const string& nama);
bool insertParent(ListTurnamen& L, Turnamen* p);
void deleteAllChildren(Pertandingan* head);
bool deleteParent(ListTurnamen& L, int id);
void printParent(const ListTurnamen& L);
int countParents(const ListTurnamen& L);

// ---------------------------------------------------------------------
// Deklarasi Operasi Child List
// ---------------------------------------------------------------------
Pertandingan* findChild(const Turnamen* parent, int childId);
bool insertChild(Turnamen* parent, Pertandingan* c);
bool deleteChild(Turnamen* parent, int childId);
bool updateSkor(Turnamen* parent, int childId, int skorA, int skorB, const string& status);
int countChildren(const Turnamen* parent);
void printChildLine(const Pertandingan* c);
void printChild(const Turnamen* parent);
void findChildByTim(const ListTurnamen& L, const string& tim);

// ---------------------------------------------------------------------
// Deklarasi Traversal Keseluruhan MLL
// ---------------------------------------------------------------------
void printAll(const ListTurnamen& L);

#endif // ESPORTS_MLL_H
