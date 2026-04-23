#include <stdio.h>
#include "ordenacao.h"
 
// ============================================================
// Bubble Sort
// Complexidade: O(n^2) - melhor caso O(n), pior caso O(n^2)
// ============================================================
void bubble_sort(int vetor[], int tamanho) {
   int i, j, temp;
   for (i = 0; i < tamanho - 1; i++) {
       for (j = 0; j < tamanho - i - 1; j++) {
           if (vetor[j] > vetor[j + 1]) {
               temp        = vetor[j];
               vetor[j]    = vetor[j + 1];
               vetor[j + 1] = temp;
           }
       }
   }
}
 
// ============================================================
// Selection Sort
// Complexidade: O(n^2) - melhor e pior caso O(n^2)
// ============================================================
void selection_sort(int vetor[], int tamanho) {
   int i, j, min_idx, temp;
   for (i = 0; i < tamanho - 1; i++) {
       min_idx = i;
       for (j = i + 1; j < tamanho; j++) {
           if (vetor[j] < vetor[min_idx]) {
               min_idx = j;
           }
       }
       if (min_idx != i) {
           temp           = vetor[i];
           vetor[i]       = vetor[min_idx];
           vetor[min_idx] = temp;
       }
   }
}
 
// ============================================================
// Quick Sort
// Complexidade: O(n log n) - melhor e medio caso O(n log n), pior caso O(n^2)
// ============================================================
static int particionar(int vetor[], int inicio, int fim) {
   int pivot = vetor[fim];
   int i = inicio - 1;
   int j, temp;
   for (j = inicio; j < fim; j++) {
       if (vetor[j] <= pivot) {
           i++;
           temp      = vetor[i];
           vetor[i]  = vetor[j];
           vetor[j]  = temp;
       }
   }
   temp          = vetor[i + 1];
   vetor[i + 1]  = vetor[fim];
   vetor[fim]    = temp;
   return i + 1;
}
 
void quick_sort(int vetor[], int inicio, int fim) {
   if (inicio < fim) {
       int pivot_idx = particionar(vetor, inicio, fim);
       quick_sort(vetor, inicio, pivot_idx - 1);
       quick_sort(vetor, pivot_idx + 1, fim);
   }
}
 
// ============================================================
// Utilitarios
// ============================================================
void copiar_vetor(int origem[], int destino[], int tamanho) {
   int i;
   for (i = 0; i < tamanho; i++) {
       destino[i] = origem[i];
   }
}
 
void exibir_vetor(int vetor[], int tamanho) {
   int i;
   for (i = 0; i < tamanho; i++) {
       printf("%d ", vetor[i]);
   }
   printf("\n");
}
