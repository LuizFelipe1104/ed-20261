#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcularIMC(float peso, float altura) {
   float imc = peso / (altura * altura);
 
   printf("Peso: %.2f kg | Altura: %.2f m | IMC: %.2f | Situacao: ", peso, altura, imc);
 
   if (imc < 18.5) {
    
    //Abaixo do Peso//
       printf("abaixo do peso\n");

   } else if (imc >= 18.5 && imc <= 24.9) {
    
    //Peso ideal/normal//
       printf("peso normal\n");

   } else if (imc >= 25.0 && imc <= 29.9) {
    
    //Acima do peso/ Sobrepeso//
       printf("sobrepeso\n");

   } else if (imc >= 30.0) {
    
    //Obseidade//
       printf("obesidade\n");
   }
}
 
int main() {
   calcularIMC(50, 1.70);
   calcularIMC(70, 1.90);
   calcularIMC(100, 1.75);
   return 0;
}

