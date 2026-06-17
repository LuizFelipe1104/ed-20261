#include <stdio.h>
#include "fila.h"
 
int main() {
 
    printf("========== TESTE DO TDA FILA ==========\n\n");
 
    // Criando a fila //
    Fila f = fila_criar();
 
    // Testando a fila vazia //
    printf("--- Fila esta vazia? ---\n");
    printf("%s\n\n", fila_esta_vazia(f) ? "Sim" : "Nao");
 
    // Testando o enfileiramento //
    printf("--- Enfileirando ---\n");
    fila_enfileirar(f, 10);
    fila_enfileirar(f, 20);
    fila_enfileirar(f, 30);
    fila_enfileirar(f, 40);
    fila_enfileirar(f, 50);
    printf("\n");
 
    // Exibindo a fila //
    printf("--- Exibindo fila ---\n");
    fila_exibir(f);
    printf("\n");
 
    // Consultando o inicio //
    printf("--- Consultando inicio ---\n");
    fila_inicio(f);
    printf("\n");
 
    // Testando o desenfileiramento //
    printf("--- Desenfileirando ---\n");
    fila_desenfileirar(f);
    fila_desenfileirar(f);
    fila_desenfileirar(f);
    printf("\n");
 
    // Exibindo a fila apos o desenfileiramento //
    printf("--- Fila apos desenfileiramento ---\n");
    fila_exibir(f);
    printf("\n");
 
    // Consultando o novo inicio //
    printf("--- Novo inicio ---\n");
    fila_inicio(f);
    printf("\n");
 
    // Destruindo a fila //
    printf("--- Destruindo fila ---\n");
    fila_destruir(f);
 
    return 0;
}