#pragma once

#define NULL_TELEM -1
#include <stddef.h>
#include <iostream>
#include <exception>
#include "IteratorLDI.h"

using namespace std;

template <typename T> class Nod {
	template <typename> friend class LDI;
	template <typename> friend class IteratorLDI;
private:
	T val;
	Nod* next;
	Nod* prev;
public:
	Nod(T val, Nod* next = NULL, Nod* prev = NULL): val(val), next(next), prev(prev){}
	virtual ~Nod(){};
};

template <typename T> class LDI {
	friend class IteratorLDI<T>;
    private:
		/* aici e reprezentarea */
		Nod<T>* head;
		Nod<T>* tail;
		int size;

    public:
 		//constructorul implicit
		LDI() {
			this->head = NULL;
			this->tail = NULL;
			this->size = 0;
		}
		// destructorul multimii
		virtual ~LDI() {
			Nod<T>* curent = head;
			while (curent != NULL) {
				Nod<T>* next = curent->next;
				delete curent;
				curent = next;
			}
		}

		//adauga un element in multime
		//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
		bool adauga(T elem) {
			/*
			Nod<T>* curent = this->head;
			while (curent != NULL) {
				if (curent->val == elem)
					return false;
				curent = curent->next;
			}
			*/
			Nod<T>* nou = new Nod<T>(elem, NULL, this->tail);
			if (this->tail == NULL)
				this->head = nou;
			else {
				this->tail->next = nou;
			}
			this->tail = nou;
			this->size++;
			return true;
		}

		//sterge un element din multime
		//returneaza adevarat daca elementul a existat si a fost sters
		bool sterge(T elem) {
			Nod<T>* curent = head;
			while (curent != NULL) {
				if (curent->val == elem) {
					if (curent == head) {
						this->head = curent->next;
						if (this->head != NULL)
							this->head->prev = NULL;
						else {
							this->tail = NULL;
						}
					}
					else if (curent == tail){
						this->tail = curent->prev;
						this->tail->next = NULL;
					}
					else {
						curent->prev->next = curent->next;
						curent->next->prev = curent->prev;
					}
					delete curent;
					this->size--;
					return true;
				}
				curent = curent->next;
			}
			return false;
		}

		//verifica daca un element se afla in multime
		bool cauta(T elem) const {
			Nod<T>* curent = head;
			while (curent != NULL) {
				if (curent->val == elem)
					return true;
				curent = curent->next;
			}
			return false;
		}


		//intoarce numarul de elemente din multime;
		int dim() const {
			return this->size;
		}

		//verifica daca multimea e vida;
		bool vida() const {
			return this->size == 0;
		}

		//returneaza un iterator pe multime
		IteratorLDI<T> iterator() const {
			return IteratorLDI<T>(*this);
		}

		bool operator == (const LDI<T>& other) const {
			if (this->size != other.size)
				return false;
			Nod<T>* curent1 = this->head;
			Nod<T>* curent2 = other.head;
			while (curent1 != NULL) {
				if (curent1->val != curent2->val)
					return false;
				curent1 = curent1->next;
				curent2 = curent2->next;
			}
			return true;
		}
};