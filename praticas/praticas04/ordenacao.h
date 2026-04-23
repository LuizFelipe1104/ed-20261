#ifndef ORDENACAO_H
#define ORDENACAO_H
 
// Complexidade: O(n^2) - melhor caso O(n), pior caso O(n^2)
void bubble_sort(int vetor[], int tamanho);
 
// Complexidade: O(n^2) - melhor e pior caso O(n^2)
void selection_sort(int vetor[], int tamanho);
 
// Complexidade: O(n log n) - melhor e medio caso O(n log n), pior caso O(n^2)
void quick_sort(int vetor[], int inicio, int fim);
 
// Utilitarios
void copiar_vetor(int origem[], int destino[], int tamanho);
void exibir_vetor(int vetor[], int tamanho);
 
#endif
