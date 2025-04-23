
#ifndef TRANZACTIE_H
#define TRANZACTIE_H
#include <ostream>

#include "Colection.tpp"

class Tranzactie {
    int id, suma;
    bool tranzactieValida{};
    Colection<int> colection;
    std::string data;

    void calculSuma(Colection<int>& bancnote);
    public:
    Tranzactie();
    Tranzactie(const Tranzactie& t);
    Tranzactie(int id, int suma, std::string data, Colection<int>& bancnote);

    int getId() const;
    int getSuma() const;
    bool getTranzactieValida() const;
    std::string getData();
    Colection<int>& getColection();

    friend std::ostream& operator<<(std::ostream& os, const Tranzactie& t);
};



#endif //TRANZACTIE_H
