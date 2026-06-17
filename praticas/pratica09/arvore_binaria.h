#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H
 

typedef struct arvore_t *Arvore;
 
// Criar uma nova arvore vazia //
Arvore arvore_criar();
 
// Insere um valor na arvore binaria de busca //
void arvore_inserir(Arvore a, int valor);
 
// Exibe os elementos em pre-ordem //
void arvore_exibir_pre_ordem(Arvore a);
 
// Exibe os elementos em ordem //
void arvore_exibir_em_ordem(Arvore a);
 
// Exibe os elementos em pos-ordem //
void arvore_exibir_pos_ordem(Arvore a);
 
// Verifica se a arvore esta vazia //
int arvore_esta_vazia(Arvore a);
 
// Libera a memoria da arvore //
void arvore_destruir(Arvore a);
 
#endif