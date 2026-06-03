#pragma once

#include <vector>
#include "LSI.h"
using namespace std;

#define NULL_TELEM -1
typedef int TElem;

class IteratorMultime;

class Multime {
	friend class IteratorMultime;

    private:
		/* aici e reprezentarea */
		int m;
		LSI* elements;
		int hashCode(TElem e) const;

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
		~Multime();
};




