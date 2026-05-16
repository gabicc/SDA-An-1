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
	int next;
	int prev;
public:
	Nod() {};
	Nod(T val, int next = -1, int prev = -1): val(val), next(next), prev(prev){}
	virtual ~Nod(){};
	Nod<T>& operator=(const Nod<T>& other) {
		this->val = other.val;
		this->next = other.next;
		this->prev = other.prev;
		return *this;
	}
};

template <typename T> class LDI {
	friend class IteratorLDI<T>;
    private:
		/* aici e reprezentarea */
		Nod<T>* elements;
		int head;
		int tail;
		int size;
		int capacity;
		int dimm;

    public:
 		//constructorul implicit
		LDI() {
			this->elements = new Nod<T> [2];
			this->head = -1;
			this->tail = -1;
			this->size = 0;
			this->capacity = 2;
			this->dimm = 0;
		}
		// destructorul multimii
		virtual ~LDI() {
			delete[] this->elements;
		}

		//adauga un element in multime
		//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
		bool adauga(T elem) {
			// for (int i = this->head; i < this->dimm; i++) {
			// 	if (this->elements[i].val == elem)
			// 		return false;
			// }
			auto it = this->iterator();
			while (it.valid()) {
				if (it.element() == elem)
					return false;
				it.urmator();
			}
			if (this->size == this->capacity) {
				//TODO check if we should compact the elements
				this->capacity *= 2;
				Nod<T>* elemNou = new Nod<T> [this->capacity];
				for (int i = 0; i< this->size; i++) {
					elemNou[i] = this->elements[i];
				}
				delete[] this->elements;
				this->elements = elemNou;
			}
			Nod<T> n(elem, -1, this->tail);
			this->elements[this->tail].next = this->size;
			this->elements[this->size] = n;
			this->size++;
			this->tail = this->size -1;
			if (this->head == -1) {
				this->head = 0;
			}
			this->dimm++;
			return true;
		}

		//sterge un element din multime
		//returneaza adevarat daca elementul a existat si a fost sters
		bool sterge(T elem) {
			int curent = head;
			while (this->elements[curent].val != elem && this->elements[curent].next != -1) {
				curent = this->elements[curent].next;
			}
			if (curent == -1) {
				return false;
			}
			else {
				if (curent == head) {
					this->head = this->elements[curent].next;
					if (this->head != -1)
						this->elements[head].prev = -1;
					else {
						this->tail = -1;
					}
				}
				else if (curent == tail) {
					this->tail = this->elements[curent].prev;
					this->elements[tail].next = -1;
				}
				else {
					this->elements[this->elements[curent].prev].next = this->elements[curent].next;
					this->elements[this->elements[curent].next].prev = this->elements[curent].prev;
				}
				this->dimm--;
				return true;
			}
		}

		//verifica daca un element se afla in multime
		bool cauta(T elem) const {
			int curent = head;
			while (curent != -1) {
				if (this->elements[curent].val == elem)
					return true;
				curent = this->elements[curent].next;
			}
			return false;
		}

		//intoarce numarul de elemente din multime;
		int dim() const {
			return this->dim;
		}

		//verifica daca multimea e vida;
		bool vida() const {
			return this->dimm == 0;
		}

		//returneaza un iterator pe multime
		IteratorLDI<T> iterator() const {
			return IteratorLDI<T>(this);
		}

		bool operator == (const LDI<T>& other) const {
			if (this->dimm != other.dimm)
				return false;
			int curent1 = this->head;
			int curent2 = other.head;
			while (curent1 != -1) {
				if (this->elements[curent1].val != other.elements[curent2].val)
					return false;
				curent1 = this->elements[curent1].next;
				curent2 = other.elements[curent1].next;
			}
			return true;
		}
};