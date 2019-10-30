/*
 * Init Lab - q2.c
 * 
 * Ecole polytechnique de Montreal, 2018
 */

// TODO
// Si besoin, ajouter ici les directives d'inclusion
// -------------------------------------------------
#include <stdio.h>
#include <unistd.h>
// -------------------------------------------------

/*
 * Vous devez imprimer le message indiqué dans l'énoncé:
 * - En exécutant un premier appel à printf AVANT l'appel à write
 * - Sans utiliser la fonction fflush
 * - En terminant chaque ligne par le caractère '\n' de fin de ligne
 */

void question2() {
    // TODO
    printf("86bc9f3ccf57 (printed using printf)");
    write(1, "86bc9f3ccf57 (printed using write)\n", sizeof("86bc9f3ccf57 (printed using write)"));
    printf("\n");
}