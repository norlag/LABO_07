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
	const m_int m_carre{{1,2,3},{1,2,4},{3,4,5}};
   m_int m_reg{{4, 4}, {1, 3}, {2,3}};
	m_int m_vide{};
	m_int m_ireg{{1,2,3},{4,5},{6},{}};
	
	cout << "(m_carre , m_reg, m_vide, m_ireg)" << endl;
	cout << m_carre << " " << m_reg  << " "
	     << m_vide  << " " << m_ireg << endl << endl;
	
	cout << "estCarre():" << endl;
	cout << estCarre(m_carre) << " " << estCarre(m_reg) << " "
		  << estCarre(m_vide)  << " " << estCarre(m_ireg)  << endl << endl;
	
	cout << "estReguliere():" << endl;
	cout << estReguliere(m_carre) << " " << estReguliere(m_reg) << " "
		  << estReguliere(m_vide)  << " " << estReguliere(m_ireg) << endl << endl;
	
	cout << "minCol():" << endl;
	cout << minCol(m_carre) << " " << minCol(m_reg)  << " "
	     << minCol(m_vide)  << " " << minCol(m_ireg) << endl << endl;
	
	cout << "sommeLigne():" << endl;
	cout << sommeLigne(m_carre) << " " << sommeLigne(m_reg)  << " "
	     << sommeLigne(m_vide)  << " " << sommeLigne(m_ireg) << endl << endl;
	
	cout << "sommeColonne():" << endl;
	cout << sommeColonne(m_carre) << " " << sommeColonne(m_reg)  << " "
	     << sommeColonne(m_vide)  << " " << sommeColonne(m_ireg) << endl << endl;
	
	cout << "sortMatrice(m_ireg):" << endl;
   sortMatrice(m_ireg);
   cout << m_ireg<< endl << endl;
	
	cout << "vectSommeMin(m_ireg):" << endl;
   cout << vectSommeMin(m_ireg) << endl << endl;
	
	cout << "shuffleMatrice(m_ireg):" << endl;
   shuffleMatrice(m_ireg);
   cout << m_ireg << endl << endl;
	
	cout << "shuffleMatrice(m_ireg):" << endl;
   shuffleMatrice(m_ireg);
   cout << m_ireg << endl << endl;
	
	return EXIT_SUCCESS;
}
