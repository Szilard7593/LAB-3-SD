#ifndef COLLECTION_COLECTION_H
#define COLLECTION_COLECTION_H

#include <iostream>

template<typename T>
struct Entry {
    T valoare;
    int frecventa;
};

template<typename T>
class Colection {
private:
    Entry<T>* elements;
    int nrElements;
    int maxCapacity;

    void resize();
    int findPosition(const T& valoare) const;

public:
    Colection();
    Colection(const Colection& c);
    Colection& operator=(const Colection& c);
    ~Colection();
    void add(const T& valoare);
    bool remove(const T& valoare);
    bool search(const T& valoare) const;
    int size() const;
    int nrOcurencies(const T& valoare) const;
    Entry<T> getAt(int position) const;
    int getNrElements() const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Colection<U>& t);
};

// --- Implementations ---

template<typename T>
Colection<T>::Colection() {
    maxCapacity = 10;
    nrElements = 0;
    elements = new Entry<T>[maxCapacity];
}

template<typename T>
Colection<T>::Colection(const Colection<T>& c) {
    maxCapacity = c.maxCapacity;
    nrElements = c.nrElements;
    elements = new Entry<T>[maxCapacity];
    for (int i = 0; i < nrElements; i++) {
        elements[i] = c.elements[i];
    }
}

template<typename T>
Colection<T>& Colection<T>::operator=(const Colection<T>& c) {
    if (this == &c) return *this;

    delete[] elements;

    maxCapacity = c.maxCapacity;
    nrElements = c.nrElements;
    elements = new Entry<T>[maxCapacity];
    for (int i = 0; i < nrElements; i++) {
        elements[i] = c.elements[i];
    }

    return *this;
}

template<typename T>
Colection<T>::~Colection() {
    delete[] elements;
}

template<typename T>
void Colection<T>::resize() {
    maxCapacity *= 2;
    auto* temp = new Entry<T>[maxCapacity];
    for (int i = 0; i < nrElements; i++)
        temp[i] = elements[i];
    delete[] elements;
    elements = temp;
}

template<typename T>
int Colection<T>::findPosition(const T& valoare) const {
    for (int i = 0; i < nrElements; i++) {
        if (elements[i].valoare == valoare)
            return i;
    }
    return -1;
}

template<typename T>
void Colection<T>::add(const T& valoare) {
    int pos = findPosition(valoare);
    if (pos != -1) {
        ++elements[pos].frecventa;
    } else {
        if (nrElements == maxCapacity)
            resize();
        elements[nrElements].valoare = valoare;
        elements[nrElements].frecventa = 1;
        nrElements++;
    }
}

template<typename T>
bool Colection<T>::remove(const T& valoare) {
    int pos = findPosition(valoare);
    if (pos == -1)
        return false;

    if (elements[pos].frecventa > 1) {
        --elements[pos].frecventa;
    } else {
        for (int i = pos; i < nrElements - 1; ++i)
            elements[i] = elements[i + 1];
        nrElements--;
    }
    return true;
}

template<typename T>
bool Colection<T>::search(const T& valoare) const {
    return findPosition(valoare) != -1;
}

template<typename T>
int Colection<T>::size() const {
    int total = 0;
    for (int i = 0; i < nrElements; i++)
        total += elements[i].frecventa;
    return total;
}

template<typename T>
int Colection<T>::nrOcurencies(const T& valoare) const {
    int pos = findPosition(valoare);
    return (pos != -1) ? elements[pos].frecventa : 0;
}

template<typename T>
Entry<T> Colection<T>::getAt(int position) const {
    if (position >= 0 && position < nrElements)
        return elements[position];
    else {
        std::cerr << "Pozitie invalida!\n";
        return Entry<T>{}; // default value
    }
}

template<typename T>
int Colection<T>::getNrElements() const {
    return nrElements;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Colection<T>& t) {
    for (int i = 0; i < t.nrElements; i++) {
        os << t.elements[i].frecventa << "*" << t.elements[i].valoare;
        if (i < t.nrElements - 1)
            os << " + ";
    }
    return os;
}

#endif // COLLECTION_COLECTION_H
