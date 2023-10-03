/*
 * processlab - part2.c
 *
 * Ecole polytechnique de Montreal, GIGL, Automne  2022
 * vos noms, prénoms et matricules
 *
 *  *          GROUPE 04
 * Loïc Nguemegne Temena - 2180845
 * Roman Alejandro Roman Canizalez - 2089991
 */

// TODO
// Si besoin, ajouter ici les directives d'inclusion
// -------------------------------------------------

// -------------------------------------------------

#include "./libprocesslab/libprocesslab.h"

#define m 1000000
// question2 calcule la somme des m premiers nombres naturels 1+2+...+m

// nb est le nombre de threads qui vont contribuer au calcul
#define nb 4

// tableau somme est utilisé pour le calcul des sommes patielles par les threads
long somme[nb];

// fonction exécutée par chaque thread créé
void *contribution(void *p)
{
  // TODO
  int no = *(int *)p;
  somme[no] = 0;
  long start = 1 + ((no * (long)m) / nb);
  long end = ((no + 1) * (long)m) / nb;
  for (long i = start; i <= end; i++)
    somme[no] += i;
  return NULL;
}

void question2()
{
  // TODO
  pthread_t threadArray[nb];
  int thread_args[nb];
  for (size_t no = 0; no < nb; no++)
  {
    thread_args[no] = no;
    pthread_create(&threadArray[no], NULL, contribution, (void *)&thread_args[no]);
  }

  long totalSum = 0;
  long TotalSumWithFormula = ((long)m * (long)(m + 1)) / 2;
  for (size_t no = 0; no < nb; no++)
  {
    pthread_join(threadArray[no], NULL);
    totalSum += somme[no];
  }
  int no = nb;

  printf("\nLa somme avec les thread est:\t%lu\n", totalSum);
  printf("\nLa somme avec la formule est:\t%lu\n", TotalSumWithFormula);
}
