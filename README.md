# Esports Tournament Management (Multi Linked List)

Tugas Besar Mata Kuliah Struktur Data — Implementasi **Multi Linked List (Model List to List)** menggunakan C++ untuk mengelola data turnamen esports dan daftar pertandingannya.

## Rancangan Struktur Data
* **Parent List (`Turnamen`)**: Menyimpan data turnamen (`id`, `nama`, `game`, `prizePool`) beserta pointer `childHead` menuju daftar pertandingan dan `next` menuju turnamen berikutnya.
* **Child List (`Pertandingan`)**: Menyimpan data pertandingan (`id`, `timA`, `timB`, `skorA`, `skorB`, `status`) beserta pointer `next` menuju pertandingan berikutnya dalam turnamen yang sama.

```text
[ListTurnamen.head]
       │
       ▼
+--------------------+      +--------------------+
| Parent: Turnamen 1 | ---> | Parent: Turnamen 2 | ---> nullptr
| (childHead)        |      | (childHead)        |
+--------------------+      +--------------------+
       │                           │
       ▼                           ▼
+--------------------+      +--------------------+
| Child: Match 101   |      | Child: Match 201   | ---> nullptr
+--------------------+      +--------------------+
       │
       ▼
+--------------------+
| Child: Match 102   | ---> nullptr
+--------------------+
