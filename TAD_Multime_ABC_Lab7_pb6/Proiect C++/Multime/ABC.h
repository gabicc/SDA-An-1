//
// Created by gabi on 6/1/26.
//

#ifndef MULTIME_TD_LI_ABC_H
#define MULTIME_TD_LI_ABC_H

typedef int TComparabil;

#include <iostream>

class IteratorABC;

class Nod {
    friend class ABC;
    friend class IteratorABC;
private:
    TComparabil val;
    Nod* st;
    Nod* dr;
public:
    Nod(TComparabil val, Nod* st = NULL, Nod* dr = NULL): val{val}, st{st}, dr{dr} {

    }
};

class ABC {
    friend class IteratorABC;
private:
    Nod* rad;
    bool adaugaRec(TComparabil e, Nod* nod);
    bool cautaRec(TComparabil e, Nod* nod) const;
    void destructorRec(Nod* nod);
    bool stergeRec(TComparabil e, Nod* nod, Nod* parinte);
    size_t size;
    void printRec(Nod* nod) const;
public:
    ABC(): size{0}, rad{NULL} {
    }
    //adauga un element in multime
    //returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
    bool adauga(TComparabil e);

    //sterge un element din multime
    //returneaza adevarat daca elementul a existat si a fost sters
    bool sterge(TComparabil e);

    //verifica daca un element se afla in multime
    bool cauta(TComparabil elem) const;


    //intoarce numarul de elemente din multime;
    int dim() const;

    //verifica daca multimea e vida;
    bool vida() const;

    //returneaza un iterator pe multime
    //IteratorABC iterator() const;

    // destructorul multimii
    ~ABC();

    IteratorABC iterator() const;

    void print() const {
        printRec(rad);
    }
};


#endif //MULTIME_TD_LI_ABC_H
