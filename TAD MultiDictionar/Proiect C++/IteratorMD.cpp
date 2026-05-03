#include "IteratorMD.h"
#include "MD.h"

using namespace std;

IteratorMD::IteratorMD(const MD& _md):
	md(_md),
	itChei(md.multidict.iterator()),
	itValori(itChei.valid()?
		itChei.element().second->iterator():
		(new LDI<TValoare>())->iterator()) {

}

TElem IteratorMD::element() const{
	if (this->valid()) {
		return pair<TCheie, TValoare>(itChei.element().first, itValori.element());
	}
	else {
		throw IteratorException("Invalid element");
	}
}

bool IteratorMD::valid() const {

	return itChei.valid() || itValori.valid();
}

void IteratorMD::urmator() {
	if (itValori.valid()) {
		itValori.urmator();
		if (!itValori.valid()) {
			if (itChei.valid()) {
				itChei.urmator();
				if (itChei.valid()) {
					itValori = itChei.element().second->iterator();
					itValori.prim();
				}
				// else {
				// 	throw IteratorException("Invalid urmator");
				// }

			}
		}
	}
}

void IteratorMD::prim() {
	itChei =md.multidict.iterator();
	itValori = itChei.valid()?
	itChei.element().second->iterator():
	(new LDI<TValoare>())->iterator();
}

