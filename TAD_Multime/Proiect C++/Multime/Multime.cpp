#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>

Multime::Multime() {
	/* de adaugat */
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}


bool Multime::adauga(TElem elem) {
	Nod* curent = this->head;
	while (curent != NULL) {
		if (curent->val == elem)
			return false;
		curent = curent->next;
	}
	Nod* nou = new Nod(elem, NULL, this->tail);
	if (this->tail == NULL)
		this->head = nou;
	else {
		this->tail->next = nou;
	}
	this->tail = nou;
	this->size++;
	return true;
}


bool Multime::sterge(TElem elem) {
	Nod* curent = head;
	while (curent != NULL) {
		if (curent->val == elem) {
			if (curent == head) {
				this->head = curent->next;
				if (this->head != NULL)
					this->head->prev = NULL;
				else {
					this->tail = NULL;
				}
			}
			else if (curent == tail){
				this->tail = curent->prev;
				this->tail->next = NULL;
			}
			else {
				curent->prev->next = curent->next;
				curent->next->prev = curent->prev;
			}
			delete curent;
			this->size--;
			return true;
		}
		curent = curent->next;
	}
	return false;
}


bool Multime::cauta(TElem elem) const {
	Nod* curent = head;
	while (curent != NULL) {
		if (curent->val == elem)
			return true;
		curent = curent->next;
	}
	return false;
}


int Multime::dim() const {
	/*int cont = 0;
	Nod* curent = head;
	while (curent != NULL) {
		cont++;
		curent = curent->next;
	}
	return cont;*/
	return this->size;
}

bool Multime::vida() const {
	/*Nod* curent = head;
	if (curent == NULL)
		return true;
	return false;*/
	return this->size == 0;
}


Multime::~Multime() {
	Nod* curent = head;
	while (curent != NULL) {
		Nod* next = curent->next;
		delete curent;
		curent = next;
	}
}

IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}
