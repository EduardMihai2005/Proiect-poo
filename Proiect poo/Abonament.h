#ifndef ABONAMENT_H
#define ABONAMENT_H

#include "Revista.h"
#include "Utilizator.h"

class Abonament {
private:
    Utilizator* user;
    Revista* revista;
    int luniRamase;
public:
    Abonament(Utilizator* u, Revista* r, int durata);
    bool esteActiv() const;
    void scadeLuna();
    void afiseazaStatus() const;
};

#endif
