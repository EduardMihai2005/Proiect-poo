#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>
#include <iostream>
using namespace std;

class Utilizator {
private: 
    int id;
    string nume;
public:
    Utilizator(int id, string nume);
    int getId() const;
    string getNume() const;
    void afiseazaInfo() const;
};

#endif
