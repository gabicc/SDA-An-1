//
// Created by gabi on 6/1/26.
//

#include "IteratorABC.h"

void IteratorABC::prim() {
    /* de adaugat */
    current = arbore.rad;
    if (current != NULL) {
        while (current->st != NULL) {
            parinti.push(current);
            current = current->st;
        }
    }
}


void IteratorABC::urmator() {
    /* de adaugat */
    if (!this->valid()) {
        throw IteratorException("Invalid ABC position for the next element");
    }
    if (current->dr != NULL) {
        current = current->dr;

    }
    else if (!parinti.empty()) {
        Nod* parinte = parinti.top();
    }
}


TComparabil IteratorABC::element() const {
    /* de adaugat */
    return current->val;
}

bool IteratorABC::valid() const {
    /* de adaugat */
    return current != NULL;
}