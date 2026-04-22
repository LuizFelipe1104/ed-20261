#include <stdio.h>
#include <stdlib.h>
 
void calcularPotencia(double base, int expoente) {
    double resultado;
    int i;
 
    if (expoente > 0) {
        resultado = 1;
        for (i = 0; i < expoente; i++) {
            resultado *= base;
        }
        printf("%.2f ^ %d = %.2f\n", base, expoente, resultado);
    } else if (expoente == 0) {
        resultado = 1;
        printf("%.2f ^ %d = %.2f (qualquer numero elevado a 0 e 1)\n", base, expoente, resultado);
    } else {
        printf("Expoente invalido! Digite um expoente inteiro positivo ou zero.\n");
    }
}
 
int main() {
   calcularPotencia(2, 10);
   calcularPotencia(3, 5);
   calcularPotencia(5, 3);
   calcularPotencia(3, 0);   
   return 0;
}
