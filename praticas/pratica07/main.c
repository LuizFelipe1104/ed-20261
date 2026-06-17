#include <stdio.h>
#include "pilha.h"
 
int main() {
 
    printf("========== TESTE DO TDA PILHA ==========\n\n");
 
    // Criando a pilha //
    Pilha p = pilha_criar();
 
    // Testando a pilha vazia //
    printf("--- Pilha esta vazia? ---\n");
    printf("%s\n\n", pilha_esta_vazia(p) ? "Sim" : "Nao");
 
    // Testando o empilhamento //
    printf("--- Empilhando ---\n");
    pilha_empilhar(p, 10);
    pilha_empilhar(p, 20);
    pilha_empilhar(p, 30);
    pilha_empilhar(p, 40);
    pilha_empilhar(p, 50);
    printf("\n");
 
    // Exibindo a pilha //
    printf("--- Exibindo pilha ---\n");
    pilha_exibir(p);
    printf("\n");
 
    // Consultando o topo //
    printf("--- Consultando topo ---\n");
    pilha_topo(p);
    printf("\n");
 
    // Testando o desempilhamento //
    printf("--- Desempilhando ---\n");
    pilha_desempilhar(p);
    pilha_desempilhar(p);
    pilha_desempilhar(p);
    printf("\n");
 
    // Exibindo pilha apos o desempilhamento //
    printf("--- Pilha apos desempilhamento ---\n");
    pilha_exibir(p);
    printf("\n");
 
    // Consultando o novo topo //
    printf("--- Novo topo ---\n");
    pilha_topo(p);
    printf("\n");
 
    // Destruindo a pilha //
    printf("--- Destruindo pilha ---\n");
    pilha_destruir(p);
 
    return 0;
}