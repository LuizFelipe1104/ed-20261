#ifndef FILA_H
#define FILA_H
 
typedef struct fila_t *Fila;
 
// Cria uma nova fila vazia //
Fila fila_criar();
 
// Enfileira um valor no fim da fila //
void fila_enfileirar(Fila f, int valor);
 
// Desenfileirar o valor do inicio da fila //
int fila_desenfileirar(Fila f);
 
// Retornar o valor do inicio sem remover 
int fila_inicio(Fila f);
 
// Exibir todos os elementos da fila do inicio ao fim //
void fila_exibir(Fila f);
 
// Verificar se a fila esta vazia //
int fila_esta_vazia(Fila f);
 
// Liberar a memoria da fila //
void fila_destruir(Fila f);
 
#endif
 