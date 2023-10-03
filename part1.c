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
        printf("LEVEL 1.1 PROCESS: started. Waiting for 2.1 \n");
        
        pid_t process_2_1;
        if ((process_2_1 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 1);
            printf("LEVEL 2.1 PROCESS: started. \n");
            printf("LEVEL 2.1 PROCESS: finished. \n");
            _exit(0);
        }

        waitpid(process_2_1, NULL, 0);
        printf("LEVEL 1.1 PROCESS: finished waiting. \n");
        _exit(0);
    }

    if ((process_1_2 = fork()) == 0) {
        registerProc(getpid(), getppid(), 1, 2);
        printf("LEVEL 1.2 PROCESS: started. Waiting for 2.2 and 2.3 \n");
        
        id_t process_2_2;
        id_t process_2_3;
        if ((process_2_2 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 2);
            printf("LEVEL 2.2 PROCESS: started. \n");
            printf("LEVEL 2.2 PROCESS: finished. \n");
            _exit(0);
        }

        if ((process_2_3 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 3);
            printf("LEVEL 2.3 PROCESS: started. \n");
            printf("LEVEL 2.3 PROCESS: finished. \n");
            _exit(0);
        }
        
        waitpid(process_2_2, NULL, 0);
        waitpid(process_2_3, NULL, 0);
        printf("LEVEL 1.2 PROCESS: finished waiting. \n");
        _exit(0);
    }

    if ((process_1_3 = fork()) == 0) {
        registerProc(getpid(), getppid(), 1, 3);
        printf("LEVEL 1.3 PROCESS: started. Waiting for 2.4, 2.5 and 2.6 \n");

        id_t process_2_4;
        id_t process_2_5;
        id_t process_2_6;
        if ((process_2_4 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 4);
            printf("LEVEL 2.4 PROCESS: started. \n");
            printf("LEVEL 2.4 PROCESS: finished. \n");
            _exit(0);
        }

        if ((process_2_5 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 5);
            printf("LEVEL 2.5 PROCESS: started. \n");
            printf("LEVEL 2.5 PROCESS: finished. \n");
            _exit(0);
        }

        if ((process_2_6 = fork()) == 0) {
            registerProc(getpid(), getppid(), 2, 6);
            printf("LEVEL 2.6 PROCESS: started. \n");
            printf("LEVEL 2.6 PROCESS: finished. \n");
            _exit(0);
        }
        
        waitpid(process_2_4, NULL, 0);
        waitpid(process_2_5, NULL, 0);
        waitpid(process_2_6, NULL, 0);
        printf("LEVEL 1.3 PROCESS: finished waiting. \n");
        _exit(0);
    } 
    
    printf("LEVEL 0 PROCESS: waiting for children process. \n");
    // TODO: There is some macros to use instead of 0 here, which should I use? 
    waitpid(process_1_1, NULL, 0);
    waitpid(process_1_2, NULL, 0);
    waitpid(process_1_3, NULL, 0);
    printf("LEVEL 0 PROCESS: finished waiting. \n");  
    printProcRegistrations();     
}

