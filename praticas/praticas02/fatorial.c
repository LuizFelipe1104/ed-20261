#include <stdio.h>
#include <stdlib.h>
 
// Complexidade: O(n) - um laco que executa n vezes//
long long fatorialIterativo(int n) {
    long long resultado = 1;
    int i;
    for (i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}
 
// Complexidade: O(n) - funcao chamada recursivamente n vezes//
long long fatorialRecursivo(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fatorialRecursivo(n - 1);
}
 
void calcularFatorial(int n) {
    printf("n = %d\n", n);
    printf("  Iterativo: %lld  -> O(n)\n", fatorialIterativo(n));
    printf("  Recursivo: %lld  -> O(n)\n", fatorialRecursivo(n));
    printf("\n");
}
 
int main() {
    calcularFatorial(5);
    calcularFatorial(10);
    calcularFatorial(12);
    return 0;
}
 