#include "Manager.h"
#include <iostream>
#include <fstream> 

using namespace std;

ManagerAplicatie::ManagerAplicatie() {
    incarcaDateDinFisier();
}

ManagerAplicatie::~ManagerAplicatie() {
    for (auto r : listaReviste) delete r;
    for (auto u : listaUtilizatori) delete u;
    for (auto a : listaAbonamente) delete a;
}

void ManagerAplicatie::incarcaDateDinFisier() {

    ifstream fRev("reviste.txt");
    if (fRev.is_open()) {
        int tip;
        double pret, extra;
        string titlu, link;

        while (fRev >> tip >> pret) {
            int id = listaReviste.size() + 1;
            if (tip == 1) { 
                fRev >> extra;
                getline(fRev >> ws, titlu); 
                listaReviste.push_back(new RevistaFizica(id, titlu, pret, extra));
            }
            else { 
                fRev >> link;
                getline(fRev >> ws, titlu);
                listaReviste.push_back(new RevistaDigitala(id, titlu, pret, link));
            }
        }
        fRev.close();
        cout << "[SISTEM] Reviste incarcate din fisier.\n";
    }
    else {
        cout << "[EROARE] Fisierul reviste.txt lipseste! Se vor folosi date goale.\n";
    }

  
    ifstream fUser("utilizatori.txt");
    if (fUser.is_open()) {
        string nume;
        while (getline(fUser, nume)) {
            if (!nume.empty()) {
                int id = listaUtilizatori.size() + 1;
                listaUtilizatori.push_back(new Utilizator(id, nume));
            }
        }
        fUser.close();
        cout << "[SISTEM] Utilizatori incarcati din fisier.\n";
    }
    else {
        cout << "[EROARE] Fisierul utilizatori.txt lipseste!\n";
    }
}

void ManagerAplicatie::afiseazaMeniu() const {
    cout << "\n=== SISTEM GESTIUNE ABONAMENTE ===\n";
    cout << "1. Adauga Revista (Manual)\n";
    cout << "2. Adauga Utilizator (Manual)\n";
    cout << "3. Creaza Abonament\n";
    cout << "4. Afiseaza Abonamente Active\n";
    cout << "5. Simuleaza Trecerea Timpului\n";
    cout << "6. Afiseaza Reviste & Useri\n";
    cout << "0. Iesire\n";
    cout << "Optiune: ";
}

void ManagerAplicatie::start() {
    int optiune;
    do {
        afiseazaMeniu();
        cin >> optiune;
        switch (optiune) {
        case 1: adaugaRevista(); break;
        case 2: adaugaUtilizator(); break;
        case 3: creazaAbonament(); break;
        case 4: afiseazaAbonamente(); break;
        case 5: simulareTimp(); break;
        case 6: afiseazaReviste(); afiseazaUtilizatori(); break;
        case 0: cout << "La revedere!\n"; break;
        default: cout << "Optiune gresita!\n";
        }
    } while (optiune != 0);
}

void ManagerAplicatie::adaugaRevista() {
    int tip;
    cout << "Tip (1-Fizic, 2-Digital): "; cin >> tip;
    string titlu, link;
    double pret, extra;
    int id = listaReviste.size() + 1;

    cout << "Titlu: "; cin.ignore(); getline(cin, titlu);
    cout << "Pret: "; cin >> pret;

    if (tip == 1) {
        cout << "Transport: "; cin >> extra;
        listaReviste.push_back(new RevistaFizica(id, titlu, pret, extra));
    }
    else {
        cout << "Link: "; cin >> link;
        listaReviste.push_back(new RevistaDigitala(id, titlu, pret, link));
    }
    cout << "Revista adaugata! Total: " << Revista::contorReviste << endl;
}

void ManagerAplicatie::adaugaUtilizator() {
    string nume;
    cout << "Nume: "; cin.ignore(); getline(cin, nume);
    int id = listaUtilizatori.size() + 1;
    listaUtilizatori.push_back(new Utilizator(id, nume));
    cout << "Utilizator adaugat.\n";
}

void ManagerAplicatie::creazaAbonament() {
    afiseazaUtilizatori();
    int uid; cout << "ID Utilizator: "; cin >> uid;

    afiseazaReviste();
    int rid; cout << "ID Revista: "; cin >> rid;

   
    Utilizator* u = cautaDupaId(listaUtilizatori, uid);
    Revista* r = cautaDupaId(listaReviste, rid);

    if (u && r) {
        int luni;
        cout << "Durata (luni): "; cin >> luni;
        listaAbonamente.push_back(new Abonament(u, r, luni));
        cout << "Abonament creat cu succes!\n";
    }
    else {
        cout << "ID invalid!\n";
    }
}

void ManagerAplicatie::afiseazaReviste() {
    cout << "\n--- LISTA REVISTE ---\n";
    for (auto r : listaReviste) cout << *r << endl; 
}

void ManagerAplicatie::afiseazaUtilizatori() {
    cout << "\n--- LISTA UTILIZATORI ---\n";
    for (auto u : listaUtilizatori) u->afiseazaInfo();
}

void ManagerAplicatie::afiseazaAbonamente() {
    cout << "\n--- ABONAMENTE ACTIVE ---\n";
    for (auto a : listaAbonamente) {
        if (a->esteActiv()) a->afiseazaStatus();
    }
}

void ManagerAplicatie::simulareTimp() {
    cout << "\n... A trecut o luna ...\n";
    for (auto a : listaAbonamente) a->scadeLuna();
}