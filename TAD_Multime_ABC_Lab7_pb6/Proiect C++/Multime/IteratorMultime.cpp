#include "IteratorMultime.h"
#include "Multime.h"


IteratorMultime::IteratorMultime(const Multime& m) : multime(m), itABC(m.graf.iterator()){
	/* de adaugat */
}


void IteratorMultime::prim() {
	/* de adaugat */
	itABC.prim();
}


void IteratorMultime::urmator() {
	/* de adaugat */
	itABC.urmator();
}


TElem IteratorMultime::element() const {
	/* de adaugat */
	return itABC.element();
}

bool IteratorMultime::valid() const {
	/* de adaugat */
	return itABC.valid();
}
