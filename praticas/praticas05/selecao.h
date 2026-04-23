Selecao.h
#ifndef SELECAO_H
#define SELECAO_H
 
// Busca o k-esimo menor elemento percorrendo o vetor linearmente
// Complexidade: O(n * k)
int linear_search(int vetor[], int tamanho, int k);
 
// Busca o k-esimo menor elemento usando particionamento (estilo Quick Sort)
// Complexidade: O(n) media, O(n^2) pior caso
int quick_select(int vetor[], int inicio, int fim, int k);
 
// Utilitarios
void copiar_vetor(int origem[], int destino[], int tamanho);
void exibir_vetor(int vetor[], int tamanho);
 
#endif
