#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>

Multime::Multime() {
	/* de adaugat */
	m = 16;
	elements = new LSI[m];
}

int Multime::hashCode(TElem e) const{
	return abs(e) %m;
}

bool Multime::adauga(TElem elem) {
	/* de adaugat */
	int hCElem = hashCode(elem);
	return elements[hCElem].add(elem);
}


bool Multime::sterge(TElem elem) {
	/* de adaugat */
	int hCElem = hashCode(elem);
	return elements[hCElem].remove(elem);
}


bool Multime::cauta(TElem elem) const {
	/* de adaugat */
	int hCElem = hashCode(elem);
	return elements[hCElem].find(elem);
}


int Multime::dim() const {
	/* de adaugat */
	int size_total  = 0;
	for (int i = 0; i < m; i++) {
		size_total += elements[i].getSize();
	}
	return size_total;
}

bool Multime::vida() const {
	/* de adaugat */
	return this->dim() == 0;
}


Multime::~Multime() {
	/* de adaugat */
	delete[] elements;
}



IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

