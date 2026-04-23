#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
 
// Struct interna - so visivel dentro deste arquivo
struct conta_t {
   int numero;
   double saldo;
};
 
Conta conta_criar(int numero, double saldo_inicial) {
   Conta c = (Conta) malloc(sizeof(struct conta_t));
   if (c == NULL) {
       printf("Erro ao criar conta!\n");
       return NULL;
   }
   c->numero = numero;
   c->saldo  = saldo_inicial;
   printf("Conta %d criada com saldo inicial: R$ %.2f\n", c->numero, c->saldo);
   return c;
}
 
void conta_depositar(Conta c, double valor) {
   if (valor > 0) {
       c->saldo += valor;
       printf("Deposito de R$ %.2f realizado. Novo saldo: R$ %.2f\n", valor, c->saldo);
   } else {
       printf("Valor de deposito invalido!\n");
   }
}
 
int conta_sacar(Conta c, double valor) {
   if (valor <= 0) {
       printf("Valor de saque invalido!\n");
       return 0;
   }
   if (valor > c->saldo) {
       printf("Saldo insuficiente para sacar R$ %.2f. Saldo atual: R$ %.2f\n", valor, c->saldo);
       return 0;
   }
   c->saldo -= valor;
   printf("Saque de R$ %.2f realizado. Novo saldo: R$ %.2f\n", valor, c->saldo);
   return 1;
}
 
void conta_ver_saldo(Conta c) {
   printf("Conta %d | Saldo atual: R$ %.2f\n", c->numero, c->saldo);
}
 
void conta_destruir(Conta c) {
   printf("Conta %d encerrada.\n", c->numero);
   free(c);
}
