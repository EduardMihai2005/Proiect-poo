#include "Abonament.h"

Abonament::Abonament(Utilizator* u, Revista* r, int durata)
    : user(u), revista(r), luniRamase(durata) {
}

bool Abonament::esteActiv() const {
    return luniRamase > 0;
}

void Abonament::scadeLuna() {
    if (luniRamase > 0) luniRamase--;
}

void Abonament::afiseazaStatus() const {
    cout << "Abonat: " << user->getNume()
        << " -> " << revista->getTitlu()
        << " (" << luniRamase << " luni)";

    if (luniRamase == 1) cout << " [EXPIRA CURAND!]";
    cout << endl;
}