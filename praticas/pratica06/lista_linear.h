#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H
 
typedef struct lista_t *Lista;
 
// Cria uma nova lista vazia // 
Lista lista_criar();
 
// Insere um valor no final da lista //
void lista_inserir(Lista l, int valor);
 
// Remove um valor da lista 
int lista_remover(Lista l, int valor);
 
// Busca um valor na lista 
int lista_buscar(Lista l, int valor);
 
// Exibe todos os elementos da lista //
void lista_exibir(Lista l);
 
// Verifica se a lista esta vazia //
int lista_esta_vazia(Lista l);
 
// Libera a memoria da lista // 
void lista_destruir(Lista l);
 
#endif