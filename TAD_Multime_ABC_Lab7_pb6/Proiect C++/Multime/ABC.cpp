//
// Created by gabi on 6/1/26.
//

#include "IteratorABC.h"

#include "ABC.h"

bool ABC::adaugaRec(TComparabil e, Nod* nod) {
    if (e < nod->val) {
        if (nod->st != NULL) {
            return adaugaRec(e, nod->st);
        }
        else {
            nod->st = new Nod(e);
            size++;
            return true;
        }
    }
    else if (e == nod->val) {
        return false;
    }
    else {
        if (nod->dr != NULL) {
            return adaugaRec(e, nod->dr);
        }
        else {
            nod->dr = new Nod(e);
            size++;
            return true;
        }
    }
}

bool ABC::adauga(TComparabil e) {
    if (rad == NULL) {
        rad = new Nod(e);
        size++;
        return true;
    }
    return adaugaRec(e, rad);
}

bool ABC::stergeRec(TComparabil e, Nod* nod, Nod* parinte) {
    if (nod->val >e) {
        return stergeRec(e, nod->st, nod);
    }
    else if (nod->val < e) {
        return stergeRec(e, nod->dr, nod);
    }
    else {// nod->val == e
        size--;
        if (nod->st == NULL && nod->dr == NULL) {
            if (parinte->st == nod)
                parinte->st = NULL;
            else
                parinte->dr = NULL;
        }
        else if (nod->st != NULL && nod->dr == NULL) {
            if (parinte->st == nod)
                parinte->st = nod->st;
            else {
                parinte->dr = nod->st;
            }
        }
        else if (nod->st == NULL && nod->dr != NULL) {
            if (parinte->st == nod)
                parinte->st = nod->dr;
            else {
                parinte->dr = nod->dr;
            }
        }
        else {
            if (parinte->st == nod)
                parinte->st = nod->st;
            else
                parinte->dr = nod->st;
            Nod* currentNode = nod->st;
            while (currentNode->dr != NULL)
                currentNode = currentNode->dr;
            currentNode->dr = nod->dr;
        }
        delete nod;
        return true;
    }
}

//sterge un element din multime
//returneaza adevarat daca elementul a existat si a fost sters
bool ABC::sterge(TComparabil e) {
    if (rad == NULL)
        return false;
    if (rad->val == e) {
        if (rad->st == NULL && rad->dr == NULL) {
            delete rad;
            rad = NULL;
        }
        else if (rad->st != NULL && rad->dr == NULL) {
            Nod* newRoot = rad->st;
            delete rad;
            rad = newRoot;
        }
        else if (rad->st == NULL && rad->dr != NULL) {
            Nod* newRoot = rad->dr;
            delete rad;
            rad = newRoot;
        }
        else {
            Nod* left = rad->st;
            Nod* right = rad->dr;
            delete rad;
            rad = left;
            Nod* curent = left;
            while (curent->dr != NULL) {
                curent = curent->dr;
            }
            curent->dr = right;
        }
        return true;
    }
    else if (rad->val > e) {
        return stergeRec(e, rad->st, rad);
    }
    else {
        return stergeRec(e, rad->dr, rad);
    }
}

bool ABC::cautaRec(TComparabil e, Nod* nod) const {
    if (e < nod->val) {
        if (nod->st != NULL) {
            return cautaRec(e, nod->st);
        }
        else {
            return false;
        }
    }
    else if (e == nod->val) {
        return true;
    }
    else {
        if (nod->dr != NULL) {
            return cautaRec(e, nod->dr);
        }
        else {
            return  false;
        }
    }
}

//verifica daca un element se afla in multime
bool ABC::cauta(TComparabil elem) const {
    if (rad == NULL)
        return false;
    return cautaRec(elem, rad);
}


//intoarce numarul de elemente din multime;
int ABC::dim() const {
    return this->size;
}

//verifica daca multimea e vida;
bool ABC::vida() const {
    return this->rad == NULL;
}

//returneaza un iterator pe multime
//IteratorABC iterator() const;

void ABC::destructorRec(Nod* nod) {
    Nod* left = nod->st;
    Nod* right = nod->dr;
    delete nod;
    if (left != NULL)
        destructorRec(left);
    if (right != NULL)
        destructorRec(right);
}

// destructorul multimii
ABC::~ABC() {
    if (rad != NULL) {
        destructorRec(rad);
    }
}

IteratorABC ABC::iterator() const {
    return IteratorABC(*this);
}

void ABC::printRec(Nod* nod) const {
    if (nod != NULL) {
        printRec(nod->st);
        cout << nod->val << " ";
        printRec(nod->dr);
    }
}
