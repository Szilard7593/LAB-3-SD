
#include "Tranzactie.h"
#include <utility>
//
  //Copie existenta datorita faptului pentru ca daca suma era mai mare ca suma bancnotelor, in timpul verificarii le dadea remove
//
void Tranzactie::calculSuma(Colection<int>& bancnote) {
    Colection<int> temp = bancnote; //Fcem o copie
    Colection<int> tempTransaction; //Macar de data asta nu fura bancnotele la greu daca suma de retragere este mai mare ca suma bancnotelor disponibile

    int sumaRamasa = this->suma;
    bool valid = true;

    while (sumaRamasa && valid) {
        int el = -1;
        int difMin = sumaRamasa;

        for (int i = 0; i < temp.getNrElements(); i++) {
            int val = temp.getAt(i).valoare;
            int freq = temp.getAt(i).frecventa;

            if (freq > 0 && sumaRamasa - val >= 0 && sumaRamasa - val < difMin) {
                difMin = sumaRamasa - val;
                el = val;
            }
        }
        if (el == -1)
            valid = false;
        else {
            temp.remove(el);
            sumaRamasa -= el;
            tempTransaction.add(el);
        }
    }

    tranzactieValida = sumaRamasa == 0;

    if (tranzactieValida) {
        bancnote = temp;
        colection = tempTransaction;  //Salveaza tranzactia daca totul este in regula
    }
}


Tranzactie::Tranzactie() {
    id = 0;
    suma = 0;
    tranzactieValida = false;
}

Tranzactie::Tranzactie(const Tranzactie &t){
    id = t.id;
    data = t.data;
    suma = t.suma;
    tranzactieValida = t.tranzactieValida;
    colection = t.colection;
}

Tranzactie::Tranzactie(int id, int suma, std::string data, Colection<int>& bancnote) {
    this->id = id;
    this->suma = suma;
    calculSuma(bancnote);
    this->data = std::move(data);
}


int Tranzactie::getId() const {
    return id;
}

int Tranzactie::getSuma() const {
    return suma;
}

bool Tranzactie::getTranzactieValida() const {
    return tranzactieValida;
}

std::string Tranzactie::getData() {
    return data;
}

Colection<int>& Tranzactie::getColection() {
    return this->colection;
}

std::ostream & operator<<(std::ostream &os, const Tranzactie &t) {
    if (t.tranzactieValida)
        os << "Tranzactie in data de "<< t.data<< ",in valoare de:" << t.suma << " \n"<< t.colection;
    else
        os << "Tranzactia in valoare de " << t.suma << " nu se poate realiza\n";
    return os;
}


