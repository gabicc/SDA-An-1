#pragma once

#define NULL_TELEM -1
typedef int TElem;
typedef int TCheie;
typedef int TValoare;

class IteratorColectie;

struct Frecventa {
	int frecv;
	TElem elem;
};

class Colectie
{
	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
	//TCheie key;
	//TValoare* values;
	Frecventa* values;
	int capacity;
	int size;
	int total;

	void resize(int capacity);
public:
		//constructorul implicit
		Colectie();

		//adauga un element in colectie
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(TElem e);

		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) const;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) const;


		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();

};

