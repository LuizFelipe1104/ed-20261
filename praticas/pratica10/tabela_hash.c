#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"
 

struct no_t {
    int valor;
    struct no_t *proximo;
};
 

struct hash_t {
    struct no_t **tabela;
    int tamanho;
};
 
// Funcao de hash: resto da divisao pelo tamanho da tabela //
static int funcao_hash(TabelaHash h, int valor) {
    return valor % h->tamanho;
}
 
TabelaHash hash_criar(int tamanho) {
    TabelaHash h = (TabelaHash) malloc(sizeof(struct hash_t));
    if (h == NULL) {
        printf("Erro ao criar tabela hash!\n");
        return NULL;
    }
    h->tamanho = tamanho;
    h->tabela  = (struct no_t **) calloc(tamanho, sizeof(struct no_t *));
    if (h->tabela == NULL) {
        printf("Erro ao alocar tabela hash!\n");
        free(h);
        return NULL;
    }
    return h;
}
 
void hash_inserir(TabelaHash h, int valor) {
    int indice = funcao_hash(h, valor);
 
    struct no_t *novo = (struct no_t *) malloc(sizeof(struct no_t));
    if (novo == NULL) {
        printf("Erro ao inserir elemento!\n");
        return;
    }
    novo->valor   = valor;
    novo->proximo = h->tabela[indice];
    h->tabela[indice] = novo;
 
    printf("Valor %d inserido na posicao %d.\n", valor, indice);
}
 
int hash_buscar(TabelaHash h, int valor) {
    int indice = funcao_hash(h, valor);
    struct no_t *atual = h->tabela[indice];
 
    while (atual != NULL) {
        if (atual->valor == valor) {
            printf("Valor %d encontrado na posicao %d.\n", valor, indice);
            return 1;
        }
        atual = atual->proximo;
    }
 
    printf("Valor %d nao encontrado na tabela hash.\n", valor);
    return 0;
}
 
int hash_remover(TabelaHash h, int valor) {
    int indice = funcao_hash(h, valor);
    struct no_t *atual   = h->tabela[indice];
    struct no_t *anterior = NULL;
 
    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                h->tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            printf("Valor %d removido da posicao %d.\n", valor, indice);
            return 1;
        }
        anterior = atual;
        atual    = atual->proximo;
    }
 
    printf("Valor %d nao encontrado para remocao.\n", valor);
    return 0;
}
 
void hash_exibir(TabelaHash h) {
    int i;
    printf("Tabela Hash:\n");
    for (i = 0; i < h->tamanho; i++) {
        printf("  [%2d]: ", i);
        struct no_t *atual = h->tabela[i];
        if (atual == NULL) {
            printf("vazio");
        } else {
            while (atual != NULL) {
                printf("%d", atual->valor);
                if (atual->proximo != NULL) printf(" -> ");
                atual = atual->proximo;
            }
        }
        printf("\n");
    }
}
 
int hash_esta_vazia(TabelaHash h) {
    int i;
    for (i = 0; i < h->tamanho; i++) {
        if (h->tabela[i] != NULL) return 0;
    }
    return 1;
}
 
void hash_destruir(TabelaHash h) {
    int i;
    for (i = 0; i < h->tamanho; i++) {
        struct no_t *atual = h->tabela[i];
        while (atual != NULL) {
            struct no_t *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }
    free(h->tabela);
    free(h);
    printf("Tabela hash destruida com sucesso.\n");
}