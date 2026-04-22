#include <stdio.h>
#include <time.h>
 
#define LINHAS 10
#define COLUNAS 10
 
// Complexidade: O(n^2) - dois lacos aninhados de tamanho n
void exibirMatrizDoisLacos(int matriz[LINHAS][COLUNAS]) {
    int i, j;
    clock_t inicio, fim;
 
    inicio = clock();
    printf("--- Dois lacos aninhados ---\n");
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
    fim = clock();
 
    printf("Complexidade: O(n^2)\n");
    printf("Tempo de execucao: %.6f segundos\n\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
}
 
// Complexidade: O(n^2) - um laco de n*n iteracoes (mesmo custo, forma diferente)
void exibirMatrizUmLaco(int matriz[LINHAS][COLUNAS]) {
    int k, linha, coluna;
    clock_t inicio, fim;
 
    inicio = clock();
    printf("--- Um laco ---\n");
    for (k = 0; k < LINHAS * COLUNAS; k++) {
        linha = k / COLUNAS;
        coluna = k % COLUNAS;
        printf("%3d ", matriz[linha][coluna]);
        if (coluna == COLUNAS - 1) {
            printf("\n");
        }
    }
    fim = clock();
 
    printf("Complexidade: O(n^2)\n");
    printf("Tempo de execucao: %.6f segundos\n\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
}
 
int main() {
    int matriz[LINHAS][COLUNAS];
    int i, j;
 
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            matriz[i][j] = i * COLUNAS + j + 1;
        }
    }
 
    exibirMatrizDoisLacos(matriz);
    exibirMatrizUmLaco(matriz);
 
    return 0;
}
 