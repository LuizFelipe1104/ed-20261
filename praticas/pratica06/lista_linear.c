/*
Nome: Luiz Felipe Borges Pinho
Matricula:2412130056
*/
#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"
 
// Struct interna do no - so visivel dentro deste arquivo
struct no_t {
    int valor;
    struct no_t *anterior;
    struct no_t *proximo;
};
 
// Struct interna da lista - so visivel dentro deste arquivo
struct lista_t {
    struct no_t *primeiro;
    struct no_t *ultimo;
};
 
Lista lista_criar() {
    Lista l = (Lista) malloc(sizeof(struct lista_t));
    if (l == NULL) {
        printf("Erro ao criar lista!\n");
        return NULL;
    }
    l->primeiro = NULL;
    l->ultimo   = NULL;
    return l;
}
 
void lista_inserir(Lista l, int valor) {
    struct no_t *novo = (struct no_t *) malloc(sizeof(struct no_t));
    if (novo == NULL) {
        printf("Erro ao inserir elemento!\n");
        return;
    }
    novo->valor    = valor;
    novo->proximo  = NULL;
    novo->anterior = l->ultimo;
 
    if (lista_esta_vazia(l)) {
        l->primeiro = novo;
    } else {
        l->ultimo->proximo = novo;
    }
 
    l->ultimo = novo;
    printf("Valor %d inserido com sucesso.\n", valor);
}
 
int lista_remover(Lista l, int valor) {
    struct no_t *atual = l->primeiro;
 
    while (atual != NULL) {
        if (atual->valor == valor) {
            if (atual->anterior != NULL) {
                atual->anterior->proximo = atual->proximo;
            } else {
                l->primeiro = atual->proximo;
            }
 
            if (atual->proximo != NULL) {
                atual->proximo->anterior = atual->anterior;
            } else {
                l->ultimo = atual->anterior;
            }
 
            free(atual);
            printf("Valor %d removido com sucesso.\n", valor);
            return 1;
        }
        atual = atual->proximo;
    }
 
    printf("Valor %d nao encontrado na lista.\n", valor);
    return 0;
}
 
int lista_buscar(Lista l, int valor) {
    struct no_t *atual = l->primeiro;
 
    while (atual != NULL) {
        if (atual->valor == valor) {
            printf("Valor %d encontrado na lista.\n", valor);
            return 1;
        }
        atual = atual->proximo;
    }
 
    printf("Valor %d nao encontrado na lista.\n", valor);
    return 0;
}
 
void lista_exibir(Lista l) {
    if (lista_esta_vazia(l)) {
        printf("Lista vazia.\n");
        return;
    }
 
    struct no_t *atual = l->primeiro;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->proximo != NULL) printf(" <-> ");
        atual = atual->proximo;
    }
    printf("\n");
}
 
int lista_esta_vazia(Lista l) {
    return l->primeiro == NULL;
}
 
void lista_destruir(Lista l) {
    struct no_t *atual = l->primeiro;
    while (atual != NULL) {
        struct no_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(l);
    printf("Lista destruida com sucesso.\n");
}