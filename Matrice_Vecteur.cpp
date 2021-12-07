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

using namespace std;

ostream& operator<< (ostream& os, const v_int& v) {
	// Ajout du premier crochet
	os << "[";
	
	// Pour chaque élément du vecteur (itérateur).
	for (v_int::const_iterator i= v.begin(); i != v.end(); ++i) {
		
		// Pour tous les passages sauf le premier, ajout de ", "
		if (i != v.begin()) os << ", ";
		
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
	for (m_int::const_iterator i= v.begin(); i != v.end(); ++i) {
		
		// Pour tous les passages sauf le premier, ajout de "\n "
		if (i != v.begin()) os << "\n ";
		
		// Ajout du vecteur pointer par l'itérateur.
		os << *i;
	}
	
	// Ajout du crochet de fin
	os << "]";
	
	//retour du flux
	return os;
}

bool estCarre(const m_int& m){
	
	// Si la matrice est vide on la considère comme carré.
	if(m.empty())return true;
	
	// pour tous les vecteurs de la matrice on vérifie que leurs tailles soit
	// la même que celle de la matrice et on retourne le résultat.
	return all_of(m.begin(), m.end(),[&m](const v_int& v)
					 {return m.size() == v.size();});
}

bool estReguliere(const m_int& m){
	
	// Si la matrice est vide on la considère comme régulière.
	if(m.empty())return true;
	
	// pour tous les vecteurs de la matrice on vérifie que leurs tailles soit
	// la même que celle de la première ligne matrice et on retourne le résultat.
	return all_of(m.begin(), m.end(),[&m](const v_int& v)
	{return m[0ull].size() == v.size();});
}

size_t minCol(const m_int& m){
	
	// Si la matrice est vide on la considère que la taille du plus petit vecteur
	// est 0.
	if(m.empty())return 0ull;
	
	// On initialise une variable qui vaut la taille du premier vecteur de la matrice
	size_t minimum = m[0ull].size();
	
	// Pour chaque vecteur de la matrice on vient comparer si leur taille est plus
	// petite que la variable minimum et dans le cas échehant minimum prends la
	// valeur de la taille du vecteur.
	for_each(m.begin(),m.end(),[&minimum](const v_int& v)
			  {minimum = min(minimum,v.size());});
	
	// On retourne minimum.
	return minimum;
}

v_int sommeLigne(const m_int& m){
	
	// On initialise un vecteur de résultat vide qui va servir de retour plus tard.
	v_int resultat;
	
	// Pour chaque vecteur de la matrice on ajoute la somme de tous ses éléments à
	// la fin du vecteur de résultat.
	for_each(m.begin(),m.end(),[&resultat](const v_int& v)
	{resultat.push_back(accumulate(v.begin(),v.end(),0));});
	
	// on retourne le vecteur de résultat.
	return resultat;
}

v_int sommeColonne(const m_int& m){
	// On initialise un vecteur de résultat vide qui va servir de retour plus tard.
	v_int resultat;
	
	// Pour chaque vecteur de la matrice
	for_each(m.begin(),m.end(),[&resultat](const v_int& v)
	// On resize le vecteur de résultat si le vecteur actuel est plus grand
	{if(v.size() > resultat.size())resultat.resize(v.size());
	// On ajoute les éléments du vecteur actuel dans l'index correspondant du
	// vecteur de résultat.
	 for(size_t i = 0ull; i < v.size(); i++)resultat[i] += v[i];
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
   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   // Mélange les vecteurs par rapport à la seed
   shuffle(m.begin(),m.end(), std::default_random_engine(seed));
}

void sortMatrice(m_int& m) {
   // Arrange les vecteurs
   sort(m.begin(), m.end(), [](const v_int& v1, const v_int& v2) {
      return *min_element(v1.cbegin(), v1.cend()) < *min_element(v2.cbegin(), v2.cend());
   });
}