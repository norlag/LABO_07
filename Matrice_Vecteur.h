#ifndef VECTEUR_ET_MATRICE_07_MATRICE_VECTEUR_H
#define VECTEUR_ET_MATRICE_07_MATRICE_VECTEUR_H
#include <vector>
#include <iostream>
#include <random>       // default_random_engine
#include <chrono>       // chrono::system_clock

typedef std::vector<int>  V_int;
typedef std::vector<V_int>  M_int;

std::ostream& operator<< (std::ostream& os, const V_int& v);
std::ostream& operator<< (std::ostream& os, const M_int& v);

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
bool estCarre(const M_int& m);


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
bool estReguliere(const M_int& m);

/**
 *
 * @fn minCol()
 *
 * @brief Retourne la taille de la plus petite ligne de la matrice.
 *
 * La fonction compare la taille de chaque ligne avec la taille
 * de la plus petit ligne croisé.\n
 * La fonction retourne ensuite la taille de la plus petite ligne croisé.
 *
 * @note Si la matrice d'entrée est vide, la fonction retourne 0.
 *
 * @param[in] m    la matrice à verifier.
 * @return size_t  la taille de la plus petit ligne de la matrice.
 */
size_t minCol(const M_int& m);

/**
 *
 * @fn sommeLigne()
 *
 * @brief Retourne vect.
 *
 * La fonction compare la taille de chaque ligne avec la taille
 * de la plus petit ligne croisé.\n
 * La fonction retourne ensuite la taille de la plus petite ligne croisé.
 *
 * @note Si la matrice d'entrée est vide, la fonction retourne 0.
 *
 * @param[in] m    la matrice à verifier.
 * @return size_t  la taille de la plus petit ligne de la matrice.
 */
V_int sommeLigne(const M_int& m);

V_int sommeColonne(const M_int& m);

V_int vectSommeMin(const M_int& m);

void shuffleMatrice(M_int& m);

void sortMatrice(M_int& m);

#endif //VECTEUR_ET_MATRICE_07_MATRICE_VECTEUR_H
