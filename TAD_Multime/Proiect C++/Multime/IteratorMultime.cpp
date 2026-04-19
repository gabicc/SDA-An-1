#include "IteratorMultime.h"
#include "Multime.h"


IteratorMultime::IteratorMultime(const Multime& m) : multime(m){
	this->curent = this->multime.head;
}


void IteratorMultime::prim() {
	this->curent = this->multime.head;
}


void IteratorMultime::urmator() {
	if (this->valid()) {
		curent = curent->next;
	}
	else {
		throw IteratorException("Invalid position for the next element");
	}
}

bool IteratorMultime::valid() const {
	if (curent == NULL)
		return false;
	return true;
}

TElem IteratorMultime::element() const {
	if (this->valid())
		return curent->val;
	throw IteratorException("Invalid position to return");
}