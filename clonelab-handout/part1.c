/*
 * Clone Lab - part1.c
 * 
 * Ecole polytechnique de Montreal, 2018
 */

// TODO
// Si besoin, ajouter ici les directives d'inclusion
// -------------------------------------------------
#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
// -------------------------------------------------

void part1() {

    pid_t princeID = fork();
    pid_t milagroID;

    if (princeID == 0) {
        milagroID = getppid();
        char milagroIDstring[50];
        sprintf(milagroIDstring, "%d", milagroID);
        execl("./part1/prince", "prince", "--P", milagroIDstring, NULL);
        exit(0);
    }

    char princeIDstring[50];
    sprintf(princeIDstring, "%d", princeID);
    execl("./part1/milagro", "milagro","--P", princeIDstring, NULL);
}