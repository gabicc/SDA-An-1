//
// Created by gabi on 5/31/26.
//

#ifndef LSI_TD_LI_ITERATORLSI_H
#define LSI_TD_LI_ITERATORLSI_H

using namespace std;

#include "LSI.h"

class IteratorException: public exception {
private:
    string errorMsg;
public:
    IteratorException(string errorMessage): errorMsg{errorMessage} {};
    const char* what() const noexcept override {
        return errorMsg.c_str();
    }
};

class IteratorLSI
{
    friend class LSI;
private:

    //constructorul primeste o referinta catre Container
    //iteratorul va referi primul element din container
    IteratorLSI(LSI* m);

    //contine o referinta catre containerul pe care il itereaza
    LSI* lista;
    /* aici e reprezentarea  specifica a iteratorului */
    Nod* current;

public:

    //reseteaza pozitia iteratorului la inceputul containerului
    void prim();

    //muta iteratorul in container
    // arunca exceptie daca iteratorul nu e valid
    void urmator();

    //verifica daca iteratorul e valid (indica un element al containerului)
    bool valid() const;

    //returneaza valoarea elementului din container referit de iterator
    //arunca exceptie daca iteratorul nu e valid
    TElem element() const;

    IteratorLSI& operator=(const IteratorLSI& other) {
        this->lista = other.lista;
        this->current = other.current;
        return *this;
    }
};


#endif //LSI_TD_LI_ITERATORLSI_H
