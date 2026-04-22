#include <stdio.h>
#include <stdlib.h>
 
void calcularNotas(int valor) {
   int cedulas[7] = {200, 100, 50, 20, 10, 5, 2};
   int i, quantidade;
 
   if (valor >= 2 && valor <= 1000 && valor % 2 == 0) {
       printf("Saque: R$ %d\n", valor);
       for (i = 0; i < 7; i++) {
           quantidade = valor / cedulas[i];
           valor = valor % cedulas[i];
           if (quantidade > 0) {
               printf("  R$ %3d: %d nota(s)\n", cedulas[i], quantidade);
           }
       }
   } else {
       printf("Valor invalido! Digite um valor entre 2 e 1000 multiplo de 2.\n");
   }
   printf("\n");
}
 
int main() {
   calcularNotas(380);
   calcularNotas(750);
   calcularNotas(127);
   return 0;
}
