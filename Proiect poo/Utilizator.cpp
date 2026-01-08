#include "Utilizator.h"

Utilizator::Utilizator(int id, string nume) : id(id), nume(nume) {}

int Utilizator::getId() const { return id; }
string Utilizator::getNume() const { return nume; }

void Utilizator::afiseazaInfo() const {
    cout << "ID: " << id << " - " << nume << endl;
}