#include <stdio.h>
#include "selecao.h"
 
// ============================================================
// Linear Search (selecao por busca linear)
// Encontra o k-esimo menor elemento sem ordenar o vetor
// Complexidade: O(n * k)
// ============================================================
int linear_search(int vetor[], int tamanho, int k) {
   int i, j, min_idx, min_val;
   int visitado[tamanho];
 
   for (i = 0; i < tamanho; i++) {
       visitado[i] = 0;
   }
 
   for (j = 0; j < k; j++) {
       min_idx = -1;
       for (i = 0; i < tamanho; i++) {
           if (!visitado[i]) {
               if (min_idx == -1 || vetor[i] < min_val) {
                   min_val = vetor[i];
                   min_idx = i;
               }
           }
       }
       visitado[min_idx] = 1;
   }
 
   return min_val;
}
 
// ============================================================
// Quick Select
// Encontra o k-esimo menor elemento usando particionamento
// Complexidade: O(n) media, O(n^2) pior caso
// ============================================================
static int particionar(int vetor[], int inicio, int fim) {
   int pivot = vetor[fim];
   int i = inicio - 1;
   int j, temp;
 
   for (j = inicio; j < fim; j++) {
       if (vetor[j] <= pivot) {
           i++;
           temp     = vetor[i];
           vetor[i] = vetor[j];
           vetor[j] = temp;
       }
   }
 
   temp         = vetor[i + 1];
   vetor[i + 1] = vetor[fim];
   vetor[fim]   = temp;
 
   return i + 1;
}
 
int quick_select(int vetor[], int inicio, int fim, int k) {
   if (inicio == fim) {
       return vetor[inicio];
   }
 
   int pivot_idx = particionar(vetor, inicio, fim);
   int pos       = pivot_idx - inicio + 1;
 
   if (k == pos) {
       return vetor[pivot_idx];
   } else if (k < pos) {
       return quick_select(vetor, inicio, pivot_idx - 1, k);
   } else {
       return quick_select(vetor, pivot_idx + 1, fim, k - pos);
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