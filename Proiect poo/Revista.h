#ifndef REVISTA_H
#define REVISTA_H

#include <string>
#include <iostream>
using namespace std;

class Revista {
protected: 
    int id;
    string titlu;
    double pretBaza;

public:
    static int contorReviste; 

    Revista(int id, string titlu, double pret);
    virtual ~Revista(); 


    virtual void afiseazaDetalii() const = 0;
    virtual string getTip() const = 0;


    int getId() const { return id; }
    string getTitlu() const { return titlu; }
    double getPret() const { return pretBaza; }


    friend ostream& operator<<(ostream& os, const Revista& r);
};

class RevistaFizica : public Revista {
private:
    double costTransport;
public:
    RevistaFizica(int id, string titlu, double pret, double transport);
    void afiseazaDetalii() const override;
    string getTip() const override;
};

class RevistaDigitala : public Revista {
private:
    string linkDownload;
public:
    RevistaDigitala(int id, string titlu, double pret, string link);
    void afiseazaDetalii() const override;
    string getTip() const override;
};

#endif
