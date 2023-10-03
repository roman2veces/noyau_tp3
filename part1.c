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
    int statusProcess_1_1 = 0; 
    int statusProcess_1_2 = 0; 
    int statusProcess_1_3 = 0; 
    int nChildren = 0; 

    if ((process_1_1 = fork()) == 0) {
        registerProc(getpid(), getppid(), 1, 1);
        int statusProcess_2_1 = 0; 
        
        pid_t process_2_1;
        if ((process_2_1 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 1);
            _exit(1);
        }

        waitpid(process_2_1, &statusProcess_2_1, 0);
        if (WIFEXITED(statusProcess_2_1)) 
            printf("PROCESS 1.1: I created %d processes\n", WEXITSTATUS(statusProcess_2_1));

        _exit(WEXITSTATUS(statusProcess_2_1) + 1);
    }

    if ((process_1_2 = fork()) == 0) {
        registerProc(getpid(), getppid(), 1, 2);
        int statusProcess_2_2 = 0; 
        int statusProcess_2_3 = 0; 
        int nChildren = 0;
        
        id_t process_2_2;
        id_t process_2_3;
        if ((process_2_2 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 2);
            _exit(1);
        }

        if ((process_2_3 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 3);
            _exit(1);
        }
        
        waitpid(process_2_2, &statusProcess_2_2, 0);
        waitpid(process_2_3, &statusProcess_2_3, 0);
        if (WIFEXITED(statusProcess_2_2) && WIFEXITED(statusProcess_2_3)) {
            nChildren = WEXITSTATUS(statusProcess_2_2) + WEXITSTATUS(statusProcess_2_3);
            printf("PROCESS 1.2: I created %d processes\n", nChildren);
        }
        
        _exit(nChildren + 1);
    }

    if ((process_1_3 = fork()) == 0) {
        registerProc(getpid(), getppid(), 1, 3);
        int statusProcess_2_4 = 0; 
        int statusProcess_2_5 = 0; 
        int statusProcess_2_6 = 0; 
        int nChildren = 0;

        id_t process_2_4;
        id_t process_2_5;
        id_t process_2_6;
        if ((process_2_4 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 4);
            _exit(1);
        }

        if ((process_2_5 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 5);
            _exit(1);
        }

        if ((process_2_6 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 6);
            _exit(1);
        }
        
        waitpid(process_2_4, &statusProcess_2_4, 0);
        waitpid(process_2_5, &statusProcess_2_5, 0);
        waitpid(process_2_6, &statusProcess_2_6, 0);
        if (WIFEXITED(statusProcess_2_4) && WIFEXITED(statusProcess_2_5) && WIFEXITED(statusProcess_2_6)) {
            nChildren = WEXITSTATUS(statusProcess_2_4) + WEXITSTATUS(statusProcess_2_5) + WEXITSTATUS(statusProcess_2_6);
            printf("PROCESS 1.3: I created %d processes\n", nChildren);
        }

        _exit(nChildren + 1);
    } 
    
    // TODO: There is some macros to use instead of 0 here, which should I use? 
    waitpid(process_1_1, &statusProcess_1_1, 0);
    waitpid(process_1_2, &statusProcess_1_2, 0);
    waitpid(process_1_3, &statusProcess_1_3, 0);
    if (WIFEXITED(statusProcess_1_1) && WIFEXITED(statusProcess_1_2) && WIFEXITED(statusProcess_1_3)) {
        nChildren = WEXITSTATUS(statusProcess_1_1) + WEXITSTATUS(statusProcess_1_2) + WEXITSTATUS(statusProcess_1_3);
        printf("PROCESS 0: I created %d processes\n", nChildren);
    }
    printProcRegistrations();     
}

