#ifndef PILHA_H
#define PILHA_H
 

typedef struct pilha_t *Pilha;
 
// Cria uma nova pilha vazia //
Pilha pilha_criar();
 
// Empilha um valor no topo da pilha //
void pilha_empilhar(Pilha p, int valor);
 
// Desempilha o valor do topo da pilha //
int pilha_desempilhar(Pilha p);
 
// Retorna o valor do topo sem remover //
int pilha_topo(Pilha p);
 
// Verifica se a pilha esta vazia //
int pilha_esta_vazia(Pilha p);
 
// Exibe todos os elementos da pilha do topo para a base //
void pilha_exibir(Pilha p);
 
// Libera a memoria da pilha //
void pilha_destruir(Pilha p);
 
#endif
 