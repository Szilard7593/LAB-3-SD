
#ifndef MULTIMEORDONATA_MULTIME_H
#define MULTIMEORDONATA_MULTIME_H


template<typename T>
using Comparator = bool (*)(T&, T&);  //pointer la functie

template<typename T>
class Multime {
private:
    T* elems;
    int capacitate;
    int noElems;

    Comparator<T> cmp;  // folosește aliasul de tip

    void resize();
    int search( T& e) ;

public:
    explicit Multime(Comparator<T> cmpFunc);
    ~Multime();

    void add( T& e);
    int remove( T& e);
    bool ifExist( T& e) ;
    int size() const;
    T getElem(int poz) ;
};

#include "Multime.tpp"

#endif //MULTIMEORDONATA_MULTIME_H
