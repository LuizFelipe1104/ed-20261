#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
 
int main() {
 
   printf("========== TESTE DO TDA CONTA ==========\n\n");
 
   // Criando contas
   Conta c1 = conta_criar(1001, 500.00);
   Conta c2 = conta_criar(1002, 0.00);
   printf("\n");
 
   // Testando depositos
   printf("--- Depositos ---\n");
   conta_depositar(c1, 250.00);
   conta_depositar(c2, 1000.00);
   conta_depositar(c2, -50.00);  // invalido
   printf("\n");
 
   // Testando saques
   printf("--- Saques ---\n");
   conta_sacar(c1, 100.00);
   conta_sacar(c2, 500.00);
   conta_sacar(c2, 9999.00);  // saldo insuficiente
   printf("\n");
 
   // Consultando saldos
   printf("--- Saldos ---\n");
   conta_ver_saldo(c1);
   conta_ver_saldo(c2);
   printf("\n");
 
   // Destruindo contas
   printf("--- Encerrando contas ---\n");
   conta_destruir(c1);
   conta_destruir(c2);
 
   return 0;
}
