//
// Created by camel on 3/24/2025.
//

#ifndef MULTIMEORDONATA_ITERATOR_H
#define MULTIMEORDONATA_ITERATOR_H


#include "Multime.h"

template<typename T>
class Iterator {
private:
    const Multime<T>& multime;
    int position;

public:
    explicit Iterator(const Multime<T>& m);

    void first();
    void next();
    bool valid() const;
    T current() const;
};



#include "Iterator.tpp"

#endif //MULTIMEORDONATA_ITERATOR_H
