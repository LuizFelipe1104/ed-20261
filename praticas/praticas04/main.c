#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
 
#define TAMANHO 100
 
int main() {
   int original[TAMANHO];
   int vetor[TAMANHO];
   clock_t inicio, fim;
   int i;
 
   // Gera vetor com 100 numeros aleatorios entre 1 e 1000
   srand(42);  // semente fixa para reproducibilidade
   for (i = 0; i < TAMANHO; i++) {
       original[i] = rand() % 1000 + 1;
   }
 
   printf("========== ALGORITMOS DE ORDENACAO ==========\n\n");
 
   printf("Vetor original:\n");
   exibir_vetor(original, TAMANHO);
   printf("\n");
 
   // --- Bubble Sort ---
   copiar_vetor(original, vetor, TAMANHO);
   inicio = clock();
   bubble_sort(vetor, TAMANHO);
   fim = clock();
   printf("--- Bubble Sort ---\n");
   printf("Complexidade: O(n^2)\n");
   printf("Tempo de execucao: %.6f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
   printf("Vetor ordenado:\n");
   exibir_vetor(vetor, TAMANHO);
   printf("\n");
 
   // --- Selection Sort ---
   copiar_vetor(original, vetor, TAMANHO);
   inicio = clock();
   selection_sort(vetor, TAMANHO);
   fim = clock();
   printf("--- Selection Sort ---\n");
   printf("Complexidade: O(n^2)\n");
   printf("Tempo de execucao: %.6f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
   printf("Vetor ordenado:\n");
   exibir_vetor(vetor, TAMANHO);
   printf("\n");
 
   // --- Quick Sort ---
   copiar_vetor(original, vetor, TAMANHO);
   inicio = clock();
   quick_sort(vetor, 0, TAMANHO - 1);
   fim = clock();
   printf("--- Quick Sort ---\n");
   printf("Complexidade: O(n log n)\n");
   printf("Tempo de execucao: %.6f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
   printf("Vetor ordenado:\n");
   exibir_vetor(vetor, TAMANHO);
   printf("\n");
 
   return 0;
}