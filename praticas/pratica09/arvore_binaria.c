#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"
 

struct no_t {
    int valor;
    struct no_t *esquerda;
    struct no_t *direita;
};
 

struct arvore_t {
    struct no_t *raiz;
};
 
// Funcao auxiliar recursiva para inserir //
static struct no_t *inserir_no(struct no_t *no, int valor) {
    if (no == NULL) {
        struct no_t *novo = (struct no_t *) malloc(sizeof(struct no_t));
        if (novo == NULL) {
            printf("Erro ao inserir elemento!\n");
            return NULL;
        }
        novo->valor    = valor;
        novo->esquerda = NULL;
        novo->direita  = NULL;
        return novo;
    }
    if (valor < no->valor) {
        no->esquerda = inserir_no(no->esquerda, valor);
    } else if (valor > no->valor) {
        no->direita = inserir_no(no->direita, valor);
    } else {
        printf("Valor %d ja existe na arvore.\n", valor);
    }
    return no;
}
 
// Funcoes auxiliares recursivas para percursos // 
static void pre_ordem(struct no_t *no) {
    if (no == NULL) return;
    printf("%d ", no->valor);
    pre_ordem(no->esquerda);
    pre_ordem(no->direita);
}
 
static void em_ordem(struct no_t *no) {
    if (no == NULL) return;
    em_ordem(no->esquerda);
    printf("%d ", no->valor);
    em_ordem(no->direita);
}
 
static void pos_ordem(struct no_t *no) {
    if (no == NULL) return;
    pos_ordem(no->esquerda);
    pos_ordem(no->direita);
    printf("%d ", no->valor);
}
 
// Funcao auxiliar recursiva para destruir //
static void destruir_no(struct no_t *no) {
    if (no == NULL) return;
    destruir_no(no->esquerda);
    destruir_no(no->direita);
    free(no);
}
 
Arvore arvore_criar() {
    Arvore a = (Arvore) malloc(sizeof(struct arvore_t));
    if (a == NULL) {
        printf("Erro ao criar arvore!\n");
        return NULL;
    }
    a->raiz = NULL;
    return a;
}
 
void arvore_inserir(Arvore a, int valor) {
    a->raiz = inserir_no(a->raiz, valor);
    printf("Valor %d inserido com sucesso.\n", valor);
}
 
void arvore_exibir_pre_ordem(Arvore a) {
    if (arvore_esta_vazia(a)) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("Pre-ordem  (raiz, esq, dir): ");
    pre_ordem(a->raiz);
    printf("\n");
}
 
void arvore_exibir_em_ordem(Arvore a) {
    if (arvore_esta_vazia(a)) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("Em-ordem   (esq, raiz, dir): ");
    em_ordem(a->raiz);
    printf("\n");
}
 
void arvore_exibir_pos_ordem(Arvore a) {
    if (arvore_esta_vazia(a)) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("Pos-ordem  (esq, dir, raiz): ");
    pos_ordem(a->raiz);
    printf("\n");
}
 
int arvore_esta_vazia(Arvore a) {
    return a->raiz == NULL;
}
 
void arvore_destruir(Arvore a) {
    destruir_no(a->raiz);
    free(a);
    printf("Arvore destruida com sucesso.\n");
}