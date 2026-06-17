#ifndef TABELA_HASH_H
#define TABELA_HASH_H
 

typedef struct hash_t *TabelaHash;
 
// Criar uma nova tabela hash com o tamanho informado //
TabelaHash hash_criar(int tamanho);
 
// Inserir um valor na tabela hash //
void hash_inserir(TabelaHash h, int valor);
 
// Buscar um valor na tabela hash //
int hash_buscar(TabelaHash h, int valor);
 
// Remover um valor da tabela hash //
int hash_remover(TabelaHash h, int valor);
 
// Exibir todos os elementos da tabela hash //
void hash_exibir(TabelaHash h);
 
// Verificar se a tabela hash esta vazia //
int hash_esta_vazia(TabelaHash h);
 
// Liberar a memoria da tabela hash //
void hash_destruir(TabelaHash h);
 
#endif