#include <stdio.h>
#include "tabela_hash.h"
 
int main() {
 
    printf("========== TESTE DO TDA TABELA HASH ==========\n\n");
 
    // Criando tabela hash de tamanho 10 //
    TabelaHash h = hash_criar(10);
 
    // Testando tabela vazia //
    printf("--- Tabela esta vazia? ---\n");
    printf("%s\n\n", hash_esta_vazia(h) ? "Sim" : "Nao");
 
    // Testando as insercoes //
    printf("--- Insercoes ---\n");
    hash_inserir(h, 10);
    hash_inserir(h, 20);  // colisao com 10 (ambos % 10 == 0)
    hash_inserir(h, 15);
    hash_inserir(h, 25);  // colisao com 15 (ambos % 10 == 5)
    hash_inserir(h, 33);
    hash_inserir(h, 7);
    hash_inserir(h, 42);
    printf("\n");
 
    // Exibindo a tabela //
    printf("--- Exibindo tabela ---\n");
    hash_exibir(h);
    printf("\n");
 
    // Testando buscas //
    printf("--- Buscas ---\n");
    hash_buscar(h, 15);   // encontrado
    hash_buscar(h, 20);   // encontrado (colisao)
    hash_buscar(h, 99);   // nao encontrado
    printf("\n");
 
    // Testando remocoes //
    printf("--- Remocoes ---\n");
    hash_remover(h, 20);  // remove elemento com colisao
    hash_remover(h, 7);   // remove elemento sem colisao
    hash_remover(h, 99);  // nao encontrado
    printf("\n");
 
    // Exibindo a tabela apos remocoes //
    printf("--- Tabela apos remocoes ---\n");
    hash_exibir(h);
    printf("\n");
 
    // Destruindo a tabela //
    printf("--- Destruindo tabela ---\n");
    hash_destruir(h);
 
    return 0;
}