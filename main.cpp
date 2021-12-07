/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Loïc Brasey
Date creation  : 7-12-2021
Description    : 
                 
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include "Matrice_Vecteur.h"

using namespace std;

int main() {
	const M_int m{{1,2,3},{1,2},{1}};
   M_int m2{{4, 4}, {1, 3}, {2}};
	cout << sommeColonne(m) << endl;

   sortMatrice(m2);
   cout << m2 << endl;
   cout << vectSommeMin(m2) << endl;

   shuffleMatrice(m2);
   cout << m2 << endl;
   shuffleMatrice(m2);
   cout << m2 << endl;

	return EXIT_SUCCESS;
}
