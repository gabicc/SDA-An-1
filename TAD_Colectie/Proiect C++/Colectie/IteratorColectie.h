#pragma once
#include <exception>
#include <string>
#include "Colectie.h"

class Colectie;
typedef int TElem;

using namespace std;

class IteratorException : public exception {
private:
	string message;
public:
	// Constructor
	IteratorException(string msg) : message(msg) {}

	// Override what() method
	const char* what() const noexcept override {
		return message.c_str();
	}

	// Optional: method to get the invalid value
	string getValue() const {
		return message;
	}
};

class IteratorColectie
{
	friend class Colectie;
private:
	//constructorul primeste o referinta catre Container
    //iteratorul va referi primul element din container
	IteratorColectie(const Colectie& c);

    //contine o referinta catre containerul pe care il itereaza
	const Colectie& col;
	/* aici e reprezentarea pecifica a iteratorului*/
	//int poz;
	int index;
	int poz_freq;

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

