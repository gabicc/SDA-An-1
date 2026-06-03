//
// Created by gabi on 5/31/26.
//

#include "IteratorLSI.h"


IteratorLSI::IteratorLSI(LSI* lsi): lista{lsi} {
    /* de adaugat */
    current = this->lista->head;
}


void IteratorLSI::prim() {
    /* de adaugat */
    //Nod* currNod = this->lista->head;
    current = this->lista->head;
}


void IteratorLSI::urmator() {
    /* de adaugat */
    if (!this->valid()) {
        throw IteratorException("Invalid LSI position for the next element");
    }
    current = current->next;
}


TElem IteratorLSI::element() const {
    /* de adaugat */
    if (!this->valid()) {
        throw IteratorException("Invalid LSi element");
    }
    return current->val;
}

bool IteratorLSI::valid() const {
    /* de adaugat */
    return current != NULL;
}
