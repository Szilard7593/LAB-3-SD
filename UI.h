#ifndef UI_H
#define UI_H
#include <string>
#include "Colection.tpp"
#include "Multime.h"
#include "Tranzactie.h"

using namespace std;
class UI {
    string options[10] = {"Afisare bancnote", "Retragere suma", "Afisare tranzactii"};
    Colection<int> bancnote;
    Multime<Tranzactie> tranzactii;
    int nrTranzactii = 0;
    void printOptions();
    void initBancnote();
    void printBancnote();
    void retragereSuma();
    void afisareTranzactii();
    static int citireSuma();
    static std::string citireData();
    static bool cmp(Tranzactie &t1, Tranzactie &t2);
public:
    UI();
    void runConsole();
};
#endif //UI_H
