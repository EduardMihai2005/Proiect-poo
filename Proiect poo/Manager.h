#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <fstream> 
#include "Revista.h"
#include "Utilizator.h"
#include "Abonament.h"

class ManagerAplicatie {
private:
    vector<Revista*> listaReviste;
    vector<Utilizator*> listaUtilizatori;
    vector<Abonament*> listaAbonamente;

    void afiseazaMeniu() const;
    void incarcaDateDinFisier(); 

public:
    ManagerAplicatie();
    ~ManagerAplicatie();

    void start(); 

    void adaugaRevista();
    void adaugaUtilizator();
    void creazaAbonament();

    void afiseazaReviste();
    void afiseazaUtilizatori();
    void afiseazaAbonamente();
    void simulareTimp();


    template <typename T>
    T* cautaDupaId(const vector<T*>& lista, int idCautat) {
        for (auto elem : lista) {
            if (elem->getId() == idCautat) {
                return elem;
            }
        }
        return nullptr;
    }
};

#endif
