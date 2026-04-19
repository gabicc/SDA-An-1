#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;

#define ALPHA 0.8
#define BETA 0.8

Colectie::Colectie() {
	/* de adaugat */
	this->total = 0;
	this->capacity = INITIAL_CAPACITY;
	this->size = 0;
	this->values = new Frecventa[this->capacity];
}

void Colectie::resize(int capacity) {
	Frecventa* newElem = new Frecventa[capacity];
	for (int i = 0; i < min(this->size, this->capacity); i++) {
		newElem[i] = this->values[i];
	}
	delete[] this->values;
	this->values = newElem;
	this->capacity = capacity;
}

void Colectie::adauga(TElem elem) {
	/* de adaugat */

	this->total++;
	for (int i = 0; i < this->size; i++) {
		if (this->values[i].elem == elem) {
			this->values[i].frecv++;
			return;
		}
		// if (elem != this->values[i].elem) {
		// 	continue;
		// }
		// this->values[i].frecv++;
		// return;
	}
	if (this->size >= this->capacity) {
		this->resize(this->capacity * 2);
	}
	this->values[this->size].elem = elem;
	this->values[this->size].frecv = 1;
	this->size++;
}


bool Colectie::sterge(TElem elem) {
	/* de adaugat */
	//return false;
	int i;
	for (i = 0; i < this->size; i++) {
		if (this->values[i].elem == elem) {
			break;
		}
	}
	if (i >= this->size) {
		return false;
	}
	for (int j = i; j < this->size; j++) {
		this->values[j] = this->values[j + 1];
	}
	this->size--;
	if (this->size < BETA * this->capacity) {
		this->resize(capacity / 2);
	}
}


bool Colectie::cauta(TElem elem) const {
	/* de adaugat */
	//return false;
	for (int i = 0; i < this->size; i++) {
		if (this->values[i].elem == elem) {
			return true;
		}
	}
	return false;
}

int Colectie::nrAparitii(TElem elem) const {
	/* de adaugat */
	//return 0;
	int cont = 0;
	for (int i = 0; i < this->size; i++) {
		if (this->values[i].elem == elem) {
			cont++;
		}
	}
	return cont;
}


int Colectie::dim() const {
	/* de adaugat */
	//return 0;
	/*int sum = 0;

	return this->size;
	*/
	return this->total;
}


bool Colectie::vida() const {
	/* de adaugat */
	//return true;
	if (this->size == 0)
		return true;
	return false;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	/* de adaugat */
	/*for (int i = 0 ; i< this->size; i++) {
		delete[] this->values[i];
	}
	*/
	delete[] this->values;
	this->values = nullptr;
}


