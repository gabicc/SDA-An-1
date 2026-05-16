#pragma once
#include <iostream>
#include <string>


using namespace std;
template <typename T> class LDI;
template <typename T> class Nod;
class IteratorException: public exception {
private:
	string message;
public:
	IteratorException(string msg): message(msg){}
	const char* what() const noexcept override {
		return message.c_str();
	}

	string getValue() const {
		return message;
	}
};

template <typename T> class IteratorLDI
{
	template <typename> friend class LDI;
private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorLDI(const LDI<T>* m): multime(m), curent(m->head) {
	}

	//contine o referinta catre containerul pe care il itereaza
	const LDI<T>* multime;
	/* aici e reprezentarea  specifica a iteratorului */
	int curent;

public:

		//reseteaza pozitia iteratorului la inceputul containerului
		void prim() {
			this->curent = this->multime->head;
		}

		//muta iteratorul in container
		// arunca exceptie daca iteratorul nu e valid
		void urmator() {
			if (this->valid()) {
				curent = this->multime->elements[curent].next;
			}
			else {
				throw IteratorException("Invalid position for the next element");
			}
		}

		//verifica daca iteratorul e valid (indica un element al containerului)
		bool valid() const {
			if (curent == -1)
				return false;
			return true;
		}

		//returneaza valoarea elementului din container referit de iterator
		//arunca exceptie daca iteratorul nu e valid
		T element() const {
			if (this->valid())
				return this->multime->elements[curent].val;
			throw IteratorException("Invalid position to return");
		}

		IteratorLDI<T>& operator=(const IteratorLDI<T>& ot) {
			if (this != &ot) {
				this->multime = ot.multime;
				this->curent = ot.curent;
			}
			return *this;
		}
};
