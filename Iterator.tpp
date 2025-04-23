#pragma once
#include "Iterator.h"

template<typename T>
Iterator<T>::Iterator(const Multime<T>& m) : multime(m), position(0) {}

template<typename T>
void Iterator<T>::first() {
    position = 0;
}

template<typename T>
void Iterator<T>::next() {
    if (!valid()) {
        return;
    }
    position++;
}

template<typename T>
bool Iterator<T>::valid() const {
    return position >= 0 && position < multime.size();
}

template<typename T>
T Iterator<T>::current() const {
    if (!valid()) {
        return T(); // element default
    }
    return multime.getElem(position);
}