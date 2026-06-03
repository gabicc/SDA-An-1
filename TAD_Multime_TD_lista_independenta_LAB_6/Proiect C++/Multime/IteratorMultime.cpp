#include "IteratorMultime.h"
#include "Multime.h"


IteratorMultime::IteratorMultime(const Multime& m) : multime(m), poz(0), curentIteratorLSI(m.elements[0].iterator()){
	prim();
	/* de adaugat */
}


void IteratorMultime::prim() {
	/* de adaugat */
	int i = 0;
	int gasit = 0;
	while (i < multime.m && gasit == 0) {
		if (multime.elements[i].getSize() > 0) {
			poz = i;
			curentIteratorLSI = multime.elements[i].iterator();
			gasit = 1;
		}
		i++;
	}
}


void IteratorMultime::urmator() {
	/* de adaugat */
	if (curentIteratorLSI.valid()) {
		curentIteratorLSI.urmator();
		if (!curentIteratorLSI.valid()) {
			int gasit = 0;
			int i = poz + 1;
			while (gasit == 0 && i < multime.m){
				if (multime.elements[i].getSize() > 0) {
					curentIteratorLSI = multime.elements[i].iterator();
					poz = i;
					gasit = 1;
				}
				i++;
			}
		}
	}
}


TElem IteratorMultime::element() const {
	return curentIteratorLSI.element();
}

bool IteratorMultime::valid() const {
	/* de adaugat */
	if (curentIteratorLSI.valid()) {
		return true;
	}
	return false;
}