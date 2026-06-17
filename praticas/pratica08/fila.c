#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
 

struct no_t {
    int valor;
    struct no_t *proximo;
};
 

struct fila_t {
    struct no_t *inicio;
    struct no_t *fim;
};
 
Fila fila_criar() {
    Fila f = (Fila) malloc(sizeof(struct fila_t));
    if (f == NULL) {
        printf("Erro ao criar fila!\n");
        return NULL;
    }
    f->inicio = NULL;
    f->fim    = NULL;
    return f;
}
 
void fila_enfileirar(Fila f, int valor) {
    struct no_t *novo = (struct no_t *) malloc(sizeof(struct no_t));
    if (novo == NULL) {
        printf("Erro ao enfileirar elemento!\n");
        return;
    }
    novo->valor   = valor;
    novo->proximo = NULL;
 
    if (fila_esta_vazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->proximo = novo;
    }
 
    f->fim = novo;
    printf("Valor %d enfileirado com sucesso.\n", valor);
}
 
int fila_desenfileirar(Fila f) {
    if (fila_esta_vazia(f)) {
        printf("Fila vazia! Nao e possivel desenfileirar.\n");
        return 0;
    }
    struct no_t *removido = f->inicio;
    printf("Valor %d desenfileirado com sucesso.\n", removido->valor);
    f->inicio = removido->proximo;
 
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
 
    free(removido);
    return 1;
}
 
int fila_inicio(Fila f) {
    if (fila_esta_vazia(f)) {
        printf("Fila vazia! Nao ha inicio.\n");
        return -1;
    }
    printf("Inicio da fila: %d\n", f->inicio->valor);
    return f->inicio->valor;
}
 
void fila_exibir(Fila f) {
    if (fila_esta_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    struct no_t *atual = f->inicio;
    printf("Fila (inicio -> fim): ");
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->proximo != NULL) printf(" -> ");
        atual = atual->proximo;
    }
    printf("\n");
}
 
int fila_esta_vazia(Fila f) {
    return f->inicio == NULL;
}
 
void fila_destruir(Fila f) {
    struct no_t *atual = f->inicio;
    while (atual != NULL) {
        struct no_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(f);
    printf("Fila destruida com sucesso.\n");
}
 