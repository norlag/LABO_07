/*
-----------------------------------------------------------------------------------
Nom du fichier : Matrice_Vecteur.cpp
Auteur(s)      : Loïc Brasey
Date creation  : 7-12-2021
Description    :

Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include "Matrice_Vecteur.h"
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

ostream& operator<< (ostream& os, const V_int& v) {
	os << "[";
	for (V_int::const_iterator i = v.begin(); i != v.end(); ++i) {
		if (i != v.begin())
			os << ", ";
		os << *i;
	}
	os << "]";
	return os;
}


ostream& operator<< (ostream& os, const M_int& v) {
	os << "[";
	for (M_int::const_iterator i = v.begin(); i != v.end(); ++i) {
		if (i != v.begin())
			os << ", ";
		os << *i;
	}
	os << "]";
	return os;
}

bool estCarre(const M_int& m) {
	if(m.empty()) return true;
	return all_of(m.begin(), m.end(),[&m](const V_int& v)
					 { return m.size() == v.size(); });
}

bool estReguliere(const M_int& m) {
	if(m.empty()) return true;
	return all_of(m.begin(), m.end(),[&m](const V_int& v)
                { return m[0].size() == v.size(); });
}

size_t minCol(const M_int& m) {
	if(m.empty()) return 0;
	size_t minimum = m[0].size();
	for_each(m.begin(),m.end(),[&minimum](const V_int& v)
			  { minimum = min(minimum,v.size()); });
	return minimum;
}

V_int sommeLigne(const M_int& m) {
	V_int resultat;
	for_each(m.begin(),m.end(),[&resultat](const V_int& v)
	{ resultat.push_back(accumulate(v.begin(),v.end(),0)); });
	return resultat;
}

V_int sommeColonne(const M_int& m) {
	V_int resultat;
	for_each(m.begin(),m.end(),[&resultat](const V_int& v)
	{ if(v.size() > resultat.size()) resultat.resize(v.size());
	 for(size_t i = 0; i < v.size(); i++) resultat[i] += v[i];
	});
	return resultat;
}

V_int vectSommeMin(const M_int& m) {
   M_int::const_iterator i = min_element(m.cbegin(), m.cend(), [](const V_int& v1, const V_int& v2) {
      return accumulate(v1.cbegin(),v1.cend(),0) < accumulate(v2.cbegin(),v2.cend(),0); });
   return *i;
}

void shuffleMatrice(M_int& m) {
   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   shuffle(m.begin(),m.end(), std::default_random_engine(seed));
}

void sortMatrice(M_int& m) {
   sort(m.begin(), m.end(), [](const V_int& v1, const V_int& v2) {
      return *min_element(v1.cbegin(), v1.cend()) < *min_element(v2.cbegin(), v2.cend());
   });
}