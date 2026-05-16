#pragma once
#include<vector>
#include<utility>
#include "LDI.h"

using namespace std;

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

class IteratorMD;

class MDPair {
private:
	TCheie key;
	LDI<TValoare>* values;
public:
	MDPair(): key{0}, values{NULL} {};
	MDPair(TCheie key, LDI<TValoare>* values): key{key}, values{values} {};
	virtual ~MDPair() {

	};
	TCheie getKey() const {
		return this->key;
	}
	LDI<TValoare>* getValues() const {
		return this->values;
	}
	void setKey(TCheie newKey) {
		this->key = newKey;
	}
	void setValues(LDI<TValoare>* newValues) {
		if (this->values != NULL)
			delete values;
		this->values = newValues;
	}

	MDPair& operator=(const MDPair& other) {
		this->key = other.key;
		if (other.values != NULL)
			this->values = other.values;
		return *this;
	}
	bool operator==(const MDPair& other) {
		return this->key == other.key && *(this->values) == *(other.values);
	}

	bool operator!=(const MDPair& other) {
		return !(*this==other);
	}
};

class MD
{
	friend class IteratorMD;

private:
	// map<TCheie, vector<TValoare>> multidict;
	LDI<MDPair> multidict;

public:
	// constructorul implicit al MultiDictionarului
	MD();

	// adauga o pereche (cheie, valoare) in MD	
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MD 
	int dim() const;

	//verifica daca MultiDictionarul e vid 
	bool vid() const;

	// se returneaza iterator pe MD
	IteratorMD iterator() const;

	// destructorul MultiDictionarului	
	~MD();



};

