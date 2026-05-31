//
// Created by gabi on 5/31/26.
//

#include "LSI.h"

#include "IteratorLSI.h"

LSI::~LSI() {
    Nod* currNod = this->head;
    while (currNod != NULL) {
        Nod* nextNode = currNod->next;
        delete currNod;
        currNod = nextNode;
    }
}

IteratorLSI LSI::iterator(){
    return IteratorLSI(this);
}