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
	const m_int m{{1, 2, 3}, {1, 2}, {}};
	cout << (m);
	
	return EXIT_SUCCESS;
}
