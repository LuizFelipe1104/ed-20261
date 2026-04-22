#ifndef CONTA_H
#define CONTA_H
 
// Tipo opaco - o usuario nao acessa a struct diretamente
typedef struct conta_t *Conta;
 
// Cria uma nova conta com numero e saldo inicial
Conta conta_criar(int numero, double saldo_inicial);
 
// Deposita um valor na conta
void conta_depositar(Conta c, double valor);
 
// Saca um valor da conta (retorna 1 se ok, 0 se saldo insuficiente)
int conta_sacar(Conta c, double valor);
 
// Exibe o saldo atual da conta
void conta_ver_saldo(Conta c);
 
// Libera a memoria da conta
void conta_destruir(Conta c);
 
#endif
