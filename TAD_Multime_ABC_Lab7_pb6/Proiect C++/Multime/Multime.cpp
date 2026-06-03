#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>

Multime::Multime() {
	/* de adaugat */
}


bool Multime::adauga(TElem elem) {
	/* de adaugat */
	return graf.adauga(elem);
}


bool Multime::sterge(TElem elem) {
	/* de adaugat */
	return graf.sterge(elem);
}


bool Multime::cauta(TElem elem) const {
	/* de adaugat */
	return graf.cauta(elem);
}


int Multime::dim() const {
	/* de adaugat */
	return graf.dim();
}

bool Multime::vida() const {
	/* de adaugat */
	return graf.vida();
}


Multime::~Multime() {
	/* de adaugat */
}



IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

