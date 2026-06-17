#include <stdio.h>
#include "lista_linear.h"
 
int main() {
 
    printf("========== TESTE DO TDA LISTA LINEAR ==========\n\n");
 
    // Criando a lista //
    Lista l = lista_criar();
 
    // Testando lista vazia //
    printf("--- Lista esta vazia? ---\n");
    printf("%s\n\n", lista_esta_vazia(l) ? "Sim" : "Nao");
 
    // Testando insercoes
    printf("--- Insercoes ---\n");
    lista_inserir(l, 10);
    lista_inserir(l, 20);
    lista_inserir(l, 30);
    lista_inserir(l, 40);
    lista_inserir(l, 50);
    printf("\n");
 
    // Exibir a lista // 
    printf("--- Exibindo lista ---\n");
    lista_exibir(l);
    printf("\n");
 
    // Testando sisteam de busca //
    printf("--- Buscas ---\n");
    lista_buscar(l, 30);   // encontrado // 
    lista_buscar(l, 99);   // nao encontrado //
    printf("\n");
 
    // Testando remocoes // 
    printf("--- Remocoes ---\n");
    lista_remover(l, 10);  // removendo o primeiro //
    lista_remover(l, 50);  // removendo o ultimo // 
    lista_remover(l, 30);  // removendo o do meio //
    lista_remover(l, 99);  // nao encontrado //
    printf("\n");
 
    // Exibir a lista apos as remocoes //
    printf("--- Lista apos remocoes ---\n");
    lista_exibir(l);
    printf("\n");
 
    // Destruindo a lista //
    printf("--- Destruindo lista ---\n");
    lista_destruir(l);
 
    return 0;
}