
#include "UI.h"
#include <fstream>
#include <iostream>

void UI::printOptions() {
    for (int i = 0; i < 3; ++i) {
        cout << i+1 << ". " << options[i] << '\n';
    }
}

void UI::initBancnote() {
    ifstream in(R"(C:\Users\szila\SD\Lab3SD[1]\Lab3SD\Bancnote.in)");
    int frecv;
    int val;
    if (!in) {
        cerr << "Error opening file " << __FILE__ << '\n';
    }
    while (in >> frecv >> val) {
        for (int i = 0; i < frecv; ++i)
            bancnote.add(val);
    }
    in.close();
}

void UI::printBancnote() {
    cout << bancnote;
}

int UI::citireSuma() {
    int suma;
    cout << "Suma: ";
    cin >> suma;
    return suma;
}

std::string UI::citireData() {
    std::string s;
    cout << "Data: ";
    cin >> s;
    return s;
}

bool UI::cmp(Tranzactie& t1, Tranzactie& t2) {
    return t1.getData() < t2.getData() ||
          (t1.getData() == t2.getData() && t1.getSuma() < t2.getSuma()) ||
          (t1.getSuma() == t2.getSuma() && t1.getColection().size() < t2.getColection().size());
}

void UI::retragereSuma() {
    int suma = citireSuma();
    std::string s = citireData();
    Tranzactie t(nrTranzactii++, suma, s, bancnote);
    tranzactii.add(t);
    cout << t;
}

void UI::afisareTranzactii() {
    for (int i = 0; i < nrTranzactii; ++i) {
        cout << tranzactii.getElem(i);
        if (i < nrTranzactii - 1)
            cout << '\n';
    }
}

UI::UI(): tranzactii(&UI::cmp) {
    initBancnote();
}

void UI::runConsole() {
    while (true) {
        printOptions();

        int option;
        cout << "Option: ";
        cin >> option;
        switch (option) {
            case 1:
                printBancnote();
                break;
            case 2:
                retragereSuma();
                break;
            case 3:
                afisareTranzactii();
                break;
            default:
                cout << "Optiune invalida";
        }
        cout << "\n\n";
    }
}
