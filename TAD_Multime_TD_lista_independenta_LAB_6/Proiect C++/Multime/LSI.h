//
// Created by gabi on 5/31/26.
//
#include <iostream>

#ifndef MULTIME_TD_LI_LSI_H
#define MULTIME_TD_LI_LSI_H

typedef int TElem;

class Nod {
    friend class IteratorLSI;
private:
    friend class LSI;
    TElem val;
    Nod* next;
public:
    Nod(TElem val, Nod* next = NULL) : val(val), next(next) {};

};

class IteratorLSI;

class LSI {
    friend class IteratorLSI;
private:
    Nod* head;
    int size;
public:
    LSI() {
        head = NULL;
        size = 0;
    };
    ~LSI();
    int getSize() const {
        return this->size;
    }
    bool add(TElem elem) {
        Nod* currNod = this->head;
        while (currNod != NULL) {
            if (currNod->val == elem) {
                return false;
            }
            currNod = currNod->next;
        }
        Nod* newNode = new Nod(elem, this->head);
        this->head = newNode;
        size++;
        return true;
    }
    bool remove(TElem elem) {
        Nod* currNod =this->head;
        Nod* prev = NULL;
        while (currNod != NULL) {
            if (currNod->val == elem) {
                size--;
                if (currNod == this->head) {
                    this->head = currNod->next;
                    delete currNod;
                    return true;
                }
                else {
                    prev->next = currNod->next;
                    delete currNod;
                    return true;
                }
            }
            prev = currNod;
            currNod = currNod->next;
        }
        return false;
    }
    bool find(TElem elem) {
        Nod* currNod = this->head;
        while (currNod != NULL) {
            if (currNod->val == elem) {
                return true;
            }
            currNod= currNod->next;
        }
        return false;
    }
    IteratorLSI iterator();

};


#endif //MULTIME_TD_LI_LSI_H
