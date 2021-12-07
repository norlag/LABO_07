/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Loïc Brasey, Schneider Sebastian
Date creation  : 7-12-2021
Description    : Ce fichier teste les fonctionalité de la librairie personalisé
                 Matrice_Vecteur.h

Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include "Matrice_Vecteur.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	const m_int m{{1,3},{1,2},{1,1}};
   m_int m2{{4, 4}, {1, 3}, {2}};
	m_int m3{{2,2},{4,4}};
	m_int m4{};
	
	cout << estCarre(m4)     << " " << estCarre(m2)     << " " << estCarre(m3) <<
	endl;
	cout << estReguliere(m) << " " << estReguliere(m2) << " " << estReguliere(m4)
		  << endl;
	cout << minCol(m)        << endl;
	cout << sommeLigne(m)    << endl;
	cout << sommeColonne(m2) << endl;

   sortMatrice(m2);
   cout << m2 << endl << endl;
   cout << vectSommeMin(m2) << endl << endl;

   shuffleMatrice(m2);
   cout << m2 << endl << endl;
   shuffleMatrice(m2);
   cout << m2 << endl << endl;
	
	return EXIT_SUCCESS;
}
