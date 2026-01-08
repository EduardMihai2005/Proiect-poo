#include "Revista.h"

int Revista::contorReviste = 0;

Revista::Revista(int id, string titlu, double pret)
    : id(id), titlu(titlu), pretBaza(pret) {
    contorReviste++;
}

Revista::~Revista() {
    contorReviste--;
}


ostream& operator<<(ostream& os, const Revista& r) {
    os << "ID: " << r.id << " | " << r.titlu << " (" << r.pretBaza << " RON)";
    return os;
}


RevistaFizica::RevistaFizica(int id, string titlu, double pret, double transport)
    : Revista(id, titlu, pret), costTransport(transport) {
}

void RevistaFizica::afiseazaDetalii() const {
    cout << "[FIZIC] " << titlu << " | Pret: " << pretBaza
        << " + Transport: " << costTransport << endl;
}
string RevistaFizica::getTip() const { return "Fizic"; }


RevistaDigitala::RevistaDigitala(int id, string titlu, double pret, string link)
    : Revista(id, titlu, pret), linkDownload(link) {
}

void RevistaDigitala::afiseazaDetalii() const {
    cout << "[DIGITAL] " << titlu << " | Pret: " << pretBaza
        << " | Link: " << linkDownload << endl;
}
string RevistaDigitala::getTip() const { return "Digital"; }