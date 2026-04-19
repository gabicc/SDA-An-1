#include "IteratorColectie.h"

#include <exception>

#include "Colectie.h"
#include <iostream>

using namespace std;

IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	this->index = 0;
	this->poz_freq = 0;
}

void IteratorColectie::prim() {
	this->index = 0;
	this->poz_freq = 0;
}


void IteratorColectie::urmator() {
	if (this->valid()) {
		if (this->poz_freq == this->col.values[this->index].frecv - 1) {
			this->index++;
			this->poz_freq = 0;
		}
		else
			this->poz_freq++;
	}
	else {
		throw IteratorException("Invalid position for the next element");
	}
}


bool IteratorColectie::valid() const {
	if (this->index >= this->col.size || this->poz_freq >= this->col.values[this->index].frecv)
		return false;
	return true;
}



TElem IteratorColectie::element() const {
	if (this->valid())
		return this->col.values[this->index].elem;
	throw IteratorException("Invalid position to return");
}
