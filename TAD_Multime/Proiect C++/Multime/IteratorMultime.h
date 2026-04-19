#pragma once
#include <iostream>
#include <string>
#include "Multime.h"

using namespace std;
class Multime;
typedef int TElem;


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

class IteratorMultime
{
	friend class Multime;
private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorMultime(const Multime& m);

	//contine o referinta catre containerul pe care il itereaza
	const Multime& multime;
	/* aici e reprezentarea  specifica a iteratorului */
	Nod* curent;

public:

		//reseteaza pozitia iteratorului la inceputul containerului
		void prim();

		//muta iteratorul in container
		// arunca exceptie daca iteratorul nu e valid
		void urmator();

		//verifica daca iteratorul e valid (indica un element al containerului)
		bool valid() const;

		//returneaza valoarea elementului din container referit de iterator
		//arunca exceptie daca iteratorul nu e valid
		TElem element() const;
};
