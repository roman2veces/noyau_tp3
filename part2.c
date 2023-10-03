/*
 * processlab - part2.c
 *
 * Ecole polytechnique de Montreal, GIGL, Automne  2022
 * vos noms, prénoms et matricules
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

//tableau somme est utilisé pour le calcul des sommes patielles par les threads
long somme[nb];


// fonction exécutée par chaque thread créé
void* contribution(void*p)
{
  const size_t no = (size_t)p; 
  const size_t start = (no * ((size_t)m / nb)) + 1;  
  const size_t end = (no + 1) * ((size_t)m / nb);  
  size_t sum = 0;
  somme[no] = 0;
  for (size_t i = start; i <= end; i++)
    somme[no] += i;
    
  return NULL;
}

void question2( )
{
  pthread_t threads[nb];
  for (size_t i = 0; i < nb; i++)
    pthread_create(&threads[i], NULL, contribution, (void*)i);

  size_t sum = 0;
  for (size_t i = 0; i < nb; i++) {
    pthread_join(threads[i], NULL);
    sum += somme[i];
  }

  const size_t expected = ((size_t)m * (size_t)(m + 1)) / 2; 
  printf("SUM = %lu ", sum);
  printf("EXPECTED = %lu ", expected);
}