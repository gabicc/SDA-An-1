#pragma once

#define NULL_TELEM -1
#include <stddef.h>
#include <iostream>
#include <exception>
typedef int TElem;

using namespace std;

class Nod {
	friend class IteratorMultime;
	friend class Multime;
private:
	TElem val;
	Nod* next;
	Nod* prev;
public:
	Nod(TElem val, Nod* next = NULL, Nod* prev = NULL): val(val), next(next), prev(prev){}
	virtual ~Nod(){};
};


class IteratorMultime;

class Multime {
	friend class IteratorMultime;

    private:
		/* aici e reprezentarea */
		Nod* head;
		Nod* tail;
		int size;

    public:
 		//constructorul implicit
		Multime();

		//adauga un element in multime
		//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
		bool adauga(TElem e);

		//sterge un element din multime
		//returneaza adevarat daca elementul a existat si a fost sters
		bool sterge(TElem e);

		//verifica daca un element se afla in multime
		bool cauta(TElem elem) const;


		//intoarce numarul de elemente din multime;
		int dim() const;

		//verifica daca multimea e vida;
		bool vida() const;

		//returneaza un iterator pe multime
		IteratorMultime iterator() const;

		// destructorul multimii
		virtual ~Multime();
};




