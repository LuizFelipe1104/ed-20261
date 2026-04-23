#include <stdio.h>
#include <stdlib.h>
 
// Melhor caso: O(1) - elemento encontrado na primeira posicao
// Pior caso:   O(n) - elemento encontrado na ultima posicao ou nao encontrado
void buscaSequencial(int vetor[], int tamanho, int valor) {
    int i, operacoes = 0;
 
    printf("Buscando valor %d no vetor...\n", valor);
 
    for (i = 0; i < tamanho; i++) {
        operacoes++;
        if (vetor[i] == valor) {
            printf("  Valor %d encontrado na posicao %d\n", valor, i);
            printf("  Operacoes realizadas: %d de %d  -> %s\n", operacoes, tamanho,
                   (i == 0) ? "Melhor caso O(1)" : (i == tamanho - 1) ? "Pior caso O(n)" : "Caso medio O(n)");
            printf("\n");
            return;
        }
    }
 
    printf("  Valor %d nao encontrado\n", valor);
    printf("  Operacoes realizadas: %d de %d  -> Pior caso O(n)\n", operacoes, tamanho);
    printf("\n");
}
 
int main() {
    int vetor[100], i;
 
    for (i = 0; i < 100; i++) {
        vetor[i] = i + 1;  // vetor de 1 a 100
    }
 
    buscaSequencial(vetor, 100, 1);    // melhor caso - primeiro elemento
    buscaSequencial(vetor, 100, 50);   // caso medio
    buscaSequencial(vetor, 100, 100);  // pior caso - ultimo elemento
    buscaSequencial(vetor, 100, 200);  // pior caso - nao encontrado
 
    return 0;
}
 