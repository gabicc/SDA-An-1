#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	/* de adaugat */
	this->poz = 0;
	this->aparitii = 0;
}

void IteratorColectie::prim() {
	/* de adaugat */
}


void IteratorColectie::urmator() {
	/* de adaugat */
}


bool IteratorColectie::valid() const {
	/* de adaugat */
	return this->poz < this->col.size;
}



TElem IteratorColectie::element() const {
	/* de adaugat */
	return -1;
}
