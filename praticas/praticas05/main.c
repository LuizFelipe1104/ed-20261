#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"
 
#define TAMANHO 100
 
int main() {
   int original[TAMANHO];
   int vetor[TAMANHO];
   clock_t inicio, fim;
   int resultado, i;
   int k = 10;  // buscar o k-esimo menor elemento
 
   // Gera vetor com 100 numeros aleatorios entre 1 e 1000
   srand(42);  // semente fixa para reproducibilidade
   for (i = 0; i < TAMANHO; i++) {
       original[i] = rand() % 1000 + 1;
   }
 
   printf("========== ALGORITMOS DE SELECAO ==========\n\n");
 
   printf("Vetor original:\n");
   exibir_vetor(original, TAMANHO);
   printf("\nBuscando o %do menor elemento...\n\n", k);
 
   // --- Linear Search ---
   copiar_vetor(original, vetor, TAMANHO);
   inicio = clock();
   resultado = linear_search(vetor, TAMANHO, k);
   fim = clock();
   printf("--- Linear Search ---\n");
   printf("Complexidade: O(n * k)\n");
   printf("Tempo de execucao: %.6f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
   printf("O %do menor elemento e: %d\n\n", k, resultado);
 
   // --- Quick Select ---
   copiar_vetor(original, vetor, TAMANHO);
   inicio = clock();
   resultado = quick_select(vetor, 0, TAMANHO - 1, k);
   fim = clock();
   printf("--- Quick Select ---\n");
   printf("Complexidade: O(n) media, O(n^2) pior caso\n");
   printf("Tempo de execucao: %.6f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
   printf("O %do menor elemento e: %d\n\n", k, resultado);
 
   return 0;
}
 

