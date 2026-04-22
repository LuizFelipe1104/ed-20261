#include <stdio.h>
 
void calcularMedia(float numeros[], int n) {
   int i;
   float soma = 0, media;
 
   if (n >= 1 && n <= 100) {
       for (i = 0; i < n; i++) {
           soma += numeros[i];
       }
       media = soma / n;
       printf("Media aritmetica de %d numeros: %.2f\n", n, media);
   } else {
       printf("Valor de n invalido! Digite entre 1 e 100.\n");
   }
}
 
int main() {
   float n1[] = {8, 6, 10, 7, 9};
   float n2[] = {5, 5, 5};
   float n3[] = {100, 200, 300, 400};
 
   calcularMedia(n1, 5);
   calcularMedia(n2, 3);
   calcularMedia(n3, 4);
 
   return 0;
}
