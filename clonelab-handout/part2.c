/*
 * Clone Lab - part2.c
 * 
 * Ecole polytechnique de Montreal, 2018
 */

#include "libclonelab.h"

#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

// TODO
// Si besoin, ajouter ici les directives d'inclusion
// -------------------------------------------------

// -------------------------------------------------

#define PART2_OUTPUT_FILE_PATH "part2Output.txt"

void part2() {
    // Ouverture du fichier de sortie pour la question 2.3
    FILE* part2OutputFile = fopen(PART2_OUTPUT_FILE_PATH, "a");
    fprintf(part2OutputFile,"Root process has pid %d", getpid());
    fclose(part2OutputFile);

    pid_t l1_1 = fork();
    char level0PID[50];
    sprintf(level0PID, "%d", getpid());

    if (l1_1 == 0) {                                // level 1.1

        registerProc(1, 1, getpid(), getppid());
        char parentID [50];
        sprintf(parentID, "%i", getppid());

        pid_t l2_1 = fork();
        if (l2_1 == 0) {                           // level 2.1
            pid_t pid = getpid();
            pid_t ppid = getppid();
            registerProc(2, 1, pid, ppid);
            fprintf(part2OutputFile, "message from process level2.1");
            fclose(part2OutputFile);
            execl("./part2/level2.1", "level2.1", NULL);
        }
        else {
            pid_t l2_2 = fork();
            if (l2_2 == 0) {                       // level 2.2
                pid_t pid = getpid();
                pid_t ppid = getppid();
                registerProc(2, 2, pid, ppid);
                fprintf(part2OutputFile, "message from process level2.2");
                fclose(part2OutputFile);
                execl("./part2/level2.2", "level2.2", NULL);

            }
            
            else {
                pid_t l2_3 = fork();
                if (l2_3 == 0) {                    // level 2.3
                    pid_t pid = getpid();
                    pid_t ppid = getppid();
                    registerProc(2, 3, pid, ppid);
                    fprintf(part2OutputFile, "message from process level2.3");
                    fclose(part2OutputFile);
                    execl("./part2/level2.3", "level2.3", NULL);
                }

                else {
                    pid_t l2_4 = fork();
                    if (l2_4 == 0) {            // level 2.4
                        pid_t pid = getpid();
                        pid_t ppid = getppid();
                        registerProc(2, 4, pid, ppid);
                        fprintf(part2OutputFile, "message from process level2.1");
                        fclose(part2OutputFile);
                        execl("./part2/level2.4", "level2.4", NULL);
                    }

                }
            }
        }
        while(wait(NULL)>0);
        execl("./part2/level1.1", "level1.1", parentID, NULL);

    }
    

    else {                                                  // stay in level 0

        pid_t l1_2 = fork();
        char parentID[50];
        sprintf(parentID, "%i", getppid());

        if (l1_2 == 0) {                                    // level 1.2

            registerProc(1, 2, getpid(), getppid());

            pid_t l2_5 = fork();
            if (l2_5 == 0) {                                // level 2.5
                registerProc(2, 5, getpid(), getppid());
                execl("./part2/level2.5", "level2.5", NULL);
            }
            else {
                pid_t l2_6 = fork();
                if (l2_6 == 0) {                            // level 2.6
                    registerProc(2, 6, getpid(), getppid());
                    execl("./part2/level2.6", "level2.6", NULL);
                }

                else {
                    pid_t l2_7 = fork();
                    if (l2_7 == 0) {                           // level 2.7
                        registerProc(2, 7, getpid(), getppid());
                        execl("./part2/level2.7", "level2.7", NULL);
                    }
                }
            }
        }

        while (wait(NULL)>0);
        execl("./part2/level1.2", "level1.2", parentID, NULL);

        }

    while (wait(NULL)>0);
    execl("./part2/level0", "level0", "3b68d787dc04bd9c615aaa88", NULL);

}
