/*
-----------------------------------------------------------------------------------
Nom du fichier : Matrice_Vecteur.cpp
Auteur(s)      : Loïc Brasey, Schneider Sebastian
Date creation  : 7-12-2021
Description    : Ce fichier contient les définitions de plusieurs fonctions
                 utilitaires pour les vecteurs et les matrices d'entiés.

Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include "Matrice_Vecteur.h"
#include <algorithm> // pour for_each et all_of()
#include <numeric>   // pour accumulate()
#include <random>    // pour default_random_engine
#include <chrono>    // pour chrono::system_clock
#include <limits>    // pour numeric_limits<int>::min()

using namespace std;

const v_type MIN_DATA = numeric_limits<v_type>::min();

ostream& operator<< (ostream& os, const v_int& v) {
	// Ajout du premier crochet
	os << "[";
	
	// Pour chaque élément du vecteur (itérateur).
	for (v_int::const_iterator i = v.cbegin(); i != v.cend(); ++i) {
		
		// Pour tous les passages sauf le premier, ajout de ", "
		if (i != v.cbegin()) os << ", ";
		
		// Ajout de l'élément pointer par l'itérateur.
		os << *i;
	}
	
	// Ajout du crochet de fin
	os << "]";
	
	//retour du flux
	return os;
}


ostream& operator<< (ostream& os, const m_int& v) {
	// Ajout du premier crochet
	os << "[";
	
	// Pour chaque vecteur de la matrice (itérateur).
	for (m_int::const_iterator i = v.cbegin(); i != v.cend(); ++i) {
		
		// Pour tous les passages sauf le premier, ajout de "\n "
		 os << (i != v.cbegin() ? "), (" : "(");
		
		// Pour chaque élément du vecteur (itérateur).
		for (v_int::const_iterator j = (*i).cbegin(); j != (*i).cend(); ++j) {
			
			// Pour tous les passages sauf le premier, ajout de ", "
			if (j != (*i).cbegin()) os << ", ";
			
			// Ajout de l'élément pointer par l'itérateur.
			os << *j;
		}
		
	}
	if(!v.empty()) cout << ')';
	
	// Ajout du crochet de fin
	os << "]";
	
	//retour du flux
	return os;
}

bool estCarre(const m_int& m){
	
	// Si la matrice est vide on la considère comme carré.
	if(m.empty()) return true;
	
	// pour tous les vecteurs de la matrice on vérifie que leurs tailles soit
	// la même que celle de la matrice et on retourne le résultat.
	return all_of(m.cbegin(), m.cend(),[&m](const v_int& v)
					 { return m.size() == v.size(); });
}

bool estReguliere(const m_int& m){
	
	// Si la matrice est vide on la considère comme régulière.
	if(m.empty()) return true;
	
	// pour tous les vecteurs de la matrice on vérifie que leurs tailles soit
	// la même que celle de la première ligne matrice et on retourne le résultat.
	return all_of(m.cbegin(), m.cend(),[&m](const v_int& v)
	{ return m[0ull].size() == v.size(); });
}

size_t minCol(const m_int& m){
	
	// Si la matrice est vide on la considère que la taille du plus petit vecteur
	// est 0.
	if(m.empty()) return 0ull;
	
	// Pour chaque vecteur de la matrice on vient comparer si leur taille est plus
	// petite que le précédant pour trouver le minimum et on retourne la taille
	// ensuite.
	return (*min_element(m.cbegin(),m.cend(),[](const v_int& v1,const v_int& v2)
			  { return v1.size() < v2.size(); })).size();
}

v_int sommeLigne(const m_int& m){
	
	// On initialise un vecteur de résultat vide qui va servir de retour plus tard.
	v_int resultat(m.size());
	
	// Pour chaque vecteur de la matrice on ajoute la somme de tous ses éléments dans
	// le vecteur de résultat.
	transform(m.cbegin(),m.cend(),resultat.begin(),[](const v_int& v)
	{ return accumulate(v.cbegin(),v.cend(),0); });
	
	// on retourne le vecteur de résultat.
	return resultat;
}

v_int sommeColonne(const m_int& m){
	// On initialise un vecteur de résultat vide qui va servir de retour plus tard.
	v_int resultat;
	
	// Pour chaque vecteur de la matrice
	for_each(m.cbegin(),m.cend(),[&resultat](const v_int& v)
	// On resize le vecteur de résultat si le vecteur actuel est plus grand
	{if(v.size() > resultat.size()) resultat.resize(v.size());
	// On ajoute les éléments du vecteur actuel dans l'index correspondant du
	// vecteur de résultat.
    transform(v.cbegin(), v.cend(), resultat.cbegin(), resultat.begin(), plus<>{});
	});
	
	// on retourne le vecteur de résultat.
	return resultat;
}

v_int vectSommeMin(const m_int& m) {
	
   // Retourne un itérateur sur le plus petit élément
   m_int::const_iterator i = min_element(m.cbegin(), m.cend(), [](const v_int& v1, const v_int& v2) {
      // Retourne la somme la plus petite
      return accumulate(v1.cbegin(),v1.cend(),0) < accumulate(v2.cbegin(),v2.cend(),0); });
   return *i;
}

void shuffleMatrice(m_int& m) {
   // Seed par rapport au temps
   unsigned seed = unsigned(chrono::system_clock::now().time_since_epoch().count());
   // Mélange les vecteurs par rapport à la seed
   shuffle(m.begin(),m.end(), default_random_engine(seed));
}

void sortMatrice(m_int& m) {
   // Arrange les vecteurs
   sort(m.begin(), m.end(), [](const v_int& v1, const v_int& v2) {
      return(
		// Compare les vecteurs par la valeur minimum vecteur
		// Si ils sont vide, ils seront placés devant les autres
      (v1.empty() ? MIN_DATA : *min_element(v1.cbegin(), v1.cend())) <
		(v2.empty() ? MIN_DATA : *min_element(v2.cbegin(), v2.cend())));
   });
}