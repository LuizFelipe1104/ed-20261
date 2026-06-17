#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
 

struct no_t {
    int valor;
    struct no_t *proximo;
};
 

struct pilha_t {
    struct no_t *topo;
};
 
Pilha pilha_criar() {
    Pilha p = (Pilha) malloc(sizeof(struct pilha_t));
    if (p == NULL) {
        printf("Erro ao criar pilha!\n");
        return NULL;
    }
    p->topo = NULL;
    return p;
}
 
void pilha_empilhar(Pilha p, int valor) {
    struct no_t *novo = (struct no_t *) malloc(sizeof(struct no_t));
    if (novo == NULL) {
        printf("Erro ao empilhar elemento!\n");
        return;
    }
    novo->valor   = valor;
    novo->proximo = p->topo;
    p->topo       = novo;
    printf("Valor %d empilhado com sucesso.\n", valor);
}
 
int pilha_desempilhar(Pilha p) {
    if (pilha_esta_vazia(p)) {
        printf("Pilha vazia! Nao e possivel desempilhar.\n");
        return 0;
    }
    struct no_t *removido = p->topo;
    printf("Valor %d desempilhado com sucesso.\n", removido->valor);
    p->topo = removido->proximo;
    free(removido);
    return 1;
}
 
int pilha_topo(Pilha p) {
    if (pilha_esta_vazia(p)) {
        printf("Pilha vazia! Nao ha topo.\n");
        return -1;
    }
    printf("Topo da pilha: %d\n", p->topo->valor);
    return p->topo->valor;
}
 
int pilha_esta_vazia(Pilha p) {
    return p->topo == NULL;
}
 
void pilha_exibir(Pilha p) {
    if (pilha_esta_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    struct no_t *atual = p->topo;
    printf("Pilha (topo -> base): ");
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->proximo != NULL) printf(" -> ");
        atual = atual->proximo;
    }
    printf("\n");
}
 
void pilha_destruir(Pilha p) {
    struct no_t *atual = p->topo;
    while (atual != NULL) {
        struct no_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(p);
    printf("Pilha destruida com sucesso.\n");
}