/*
-----------------------------------------------------------------------------------
Nom du fichier : Matrice_Vecteur.h
Auteur(s)      : Loïc Brasey, Schneider Sebastian
Date creation  : 7-12-2021
Description    : Ce fichier contient les déclarations de plusieurs fonctions
                 utilitaires pour les vecteurs et les matrices d'entiés.

Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef VECTEUR_ET_MATRICE_07_MATRICE_VECTEUR_H
#define VECTEUR_ET_MATRICE_07_MATRICE_VECTEUR_H

#include <iostream>  // l'opérateur <<
#include <vector>    // pour le type vecteur

///@typedef  int
typedef int                 v_type;

///@typedef  std::vector\<int>
typedef std::vector<v_type> v_int;

///@typedef  std::vector\<vector\<int>>
typedef std::vector<v_int>  m_int;

/**
 *
 * @operator  \<\< vector\<int>
 *
 * @brief opérateur \<\< pour le type vector\<int>.
 *
 * L'operateur permet de convertir un vecteur d'entié au format: [1, 2, 3].\n
 * Pour permètre de l'afficher via cout.
 */
std::ostream& operator<< (std::ostream& os, const v_int& v);

/**
 *
 * @operator  \<\< vector\<vector\<int>>
 *
 * @brief opérateur \<\< pour le type vector\<vector\<int>>.
 *
 * L'opérateur permet de convertir un vecteur d'entié au format: [(..),(..)]
 * Pour permètre de l'afficher via cout.
 */
std::ostream& operator<< (std::ostream& os, const m_int& v);

/**
 *
 * @fn estCarre()
 *
 * @brief Retourne \b true si la matrice est carrée.
 *
 * La fonction compare la taille de chaque ligne avec la taille
 * de la matrice.\n
 * À la première incohérence la fonction retourne false.\n
 * S'il n'y a pas d'incoherence la fonction retourne true.
 *
 * @note Les matrice vide sont considéré comme carré (\b true ).
 *
 * @param[in] m  la matrice à verifier.
 * @return bool  \b true si la matrice est carrée sinon \b false.
 */
bool estCarre(const m_int& m);

/**
 *
 * @fn estReguliere()
 *
 * @brief Retourne \b true si la matrice est régulière.
 *
 * La fonction compare la taille de chaque ligne avec la taille
 * de la première ligne de la matrice.\n
 * À la première incoherence la fonction retourne false.\n
 * S'il n'y a pas d'incoherence la fonction retourne true.
 *
 * @note Les matrice vide sont considéré comme régulière (\b true ).
 *
 * @param[in] m  la matrice à verifier.
 * @return bool  \b true si la matrice est régulière sinon \b false.
 */
bool estReguliere(const m_int& m);

/**
 *
 * @fn minCol()
 *
 * @brief Retourne la taille du plus petit vecteur de la matrice.
 *
 * La fonction compare la taille de chaque vecteur avec la taille
 * du plus petit vecteur croisé.\n
 * La fonction retourne ensuite la taille du plus petit vecteur croisé.
 *
 * @note Si la matrice d'entrée est vide, la fonction retourne 0.
 *
 * @param[in] m    la matrice à verifier.
 * @return size_t  la taille de la plus petit ligne de la matrice.
 */
size_t minCol(const m_int& m);

/**
 *
 * @fn sommeLigne()
 *
 * @brief Retourne un vecteur contenant la somme de chaque ligne de la matrice.
 *
 * La fonction additionne les élément de  chaque ligne et ajoute le résultat dans
 * un vecteur qui sera retourné a la fin de la fonction.\n
 *
 * @param[in] m         la matrice à traiter.
 * @return vector<int>  vecteur contenant la somme de chaque ligne.
 */
v_int sommeLigne(const m_int& m);

/**
 *
 * @fn sommeColonne()
 *
 * @brief Retourne un vecteur contenant la somme de chaque colonne de la matrice.
 *
 * La fonction commence par initialisé un vecteur de résultat vide.\n
 * Ensuite on prends les lignes une par une et verifie aaugmente le taille du vecteur
 * de résultat si nécessaire puis ajouter chaque élément de la ligne dans l'index
 * correspondant du vecteur de résultat.\n
 * Pour finir la fonction retourne le vecteur de résultat.
 *
 * @param[in] m         la matrice à traiter.
 * @return vector<int>  vecteur contenant la somme de chaque colonne.
 */
v_int sommeColonne(const m_int& m);

/**
 *
 * @fn vectSommeMin()
 *
 * @brief Retour le vecteur d’une matrice dont la somme des valeurs
 * est la plus faible. Si plusieurs vecteurs présentent la même
 * somme, la fonction retourne celui d’indice le plus faible.
 *
 *
 * @param[in] m         la matrice à traiter.
 * @return vector<int>  le vecteur d’une matrice dont la somme des valeurs
 * est la plus faible
 */
v_int vectSommeMin(const m_int& m);

/**
 *
 * @fn shuffleMatrice()
 *
 * @brief Mélange l'ordre des vecteurs dans la matrice sans les modifier
 *
 *
 *
 * @param[in] m         la matrice à traiter.
 * @return -
 */
void shuffleMatrice(m_int& m);

/**
 *
 * @fn sortMatrice()
 *
 * @brief Trie dans l'ordre croissant les vecteurs en fonction du plus petit élément du vecteur
 *
 *
 * @param[in] m         la matrice à traiter.
 * @return -
 */
void sortMatrice(m_int& m);

#endif //VECTEUR_ET_MATRICE_07_MATRICE_VECTEUR_H
