//
// Created by gabi on 6/1/26.
//

#ifndef MULTIME_TD_LI_ITERATORABC_H
#define MULTIME_TD_LI_ITERATORABC_H

#include "ABC.h"
#include <stack>

using namespace std;

class IteratorException: public exception {
private:
    string errorMsg;
public:
    IteratorException(string errorMessage): errorMsg{errorMessage} {};
    const char* what() const noexcept override {
        return errorMsg.c_str();
    }
};

class IteratorABC {
public:
    const ABC& arbore; // inordine = st, rad, dr
    Nod* current;
    stack<Nod*> parinti;
public:
    IteratorABC(const ABC& arb): arbore{arb}, current{arbore.rad} {};

    //reseteaza pozitia iteratorului la inceputul containerului
    void prim();

    //muta iteratorul in container
    // arunca exceptie daca iteratorul nu e valid
    void urmator();

    //verifica daca iteratorul e valid (indica un element al containerului)
    bool valid() const;

    //returneaza valoarea elementului din container referit de iterator
    //arunca exceptie daca iteratorul nu e valid
    TComparabil element() const;
};


#endif //MULTIME_TD_LI_ITERATORABC_H
