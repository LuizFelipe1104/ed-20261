#include <stdio.h>
#include "arvore_binaria.h"
 
int main() {
 
    printf("========== TESTE DO TDA ARVORE BINARIA ==========\n\n");
 
    // Criando a arvore //
    Arvore a = arvore_criar();
 
    // Testando a arvore vazia //
    printf("--- Arvore esta vazia? ---\n");
    printf("%s\n\n", arvore_esta_vazia(a) ? "Sim" : "Nao");
 
    // Testando as insercoes //
    
    printf("--- Insercoes ---\n");
    arvore_inserir(a, 50);
    arvore_inserir(a, 30);
    arvore_inserir(a, 70);
    arvore_inserir(a, 20);
    arvore_inserir(a, 40);
    arvore_inserir(a, 60);
    arvore_inserir(a, 80);
    arvore_inserir(a, 50);  // duplicado
    printf("\n");
 
    // Testando percursos //
    printf("--- Percursos ---\n");
    arvore_exibir_pre_ordem(a);
    arvore_exibir_em_ordem(a);
    arvore_exibir_pos_ordem(a);
    printf("\n");
 
    // Destruindo a arvore //
    printf("--- Destruindo arvore ---\n");
    arvore_destruir(a);
 
    return 0;
}