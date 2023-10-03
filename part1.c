/*
 * processlab - part1.c
 *
 * Ecole polytechnique de Montreal, GIGL, Automne  2022
 * vos noms, prénoms et matricules
*/

#include "libprocesslab/libprocesslab.h"

// TODO
// Si besoin, ajouter ici les directives d'inclusion
// -------------------------------------------------

// -------------------------------------------------

void question1()
{
    registerProc(getpid(), getppid(), 0, 0);
    pid_t process_1_1;
    pid_t process_1_2;
    pid_t process_1_3;

    if ((process_1_1 = fork()) == 0) {
        registerProc(getpid(), getppid(), 1, 1);
        
        pid_t process_2_1;
        if ((process_2_1 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 1);
            _exit(0);
        }

        waitpid(process_2_1, NULL, 0);
        _exit(0);
    }

    if ((process_1_2 = fork()) == 0) {
        registerProc(getpid(), getppid(), 1, 2);
        
        id_t process_2_2;
        id_t process_2_3;
        if ((process_2_2 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 2);
            _exit(0);
        }

        if ((process_2_3 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 3);
            _exit(0);
        }
        
        waitpid(process_2_2, NULL, 0);
        waitpid(process_2_3, NULL, 0);
        _exit(0);
    }

    if ((process_1_3 = fork()) == 0) {
        registerProc(getpid(), getppid(), 1, 3);

        id_t process_2_4;
        id_t process_2_5;
        id_t process_2_6;
        if ((process_2_4 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 4);
            _exit(0);
        }

        if ((process_2_5 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 5);
            _exit(0);
        }

        if ((process_2_6 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 6);
            _exit(0);
        }
        
        waitpid(process_2_4, NULL, 0);
        waitpid(process_2_5, NULL, 0);
        waitpid(process_2_6, NULL, 0);
        _exit(0);
    } 
    
    // TODO: There is some macros to use instead of 0 here, which should I use? 
    waitpid(process_1_1, NULL, 0);
    waitpid(process_1_2, NULL, 0);
    waitpid(process_1_3, NULL, 0);
    printProcRegistrations();     
}

