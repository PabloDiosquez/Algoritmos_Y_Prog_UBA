// Escribir en C una función que pida al usuario que ingrese un número natural e imprima por pantalla
// los primeros n números primos. Se debe implementar una función auxiliar es_primo que recibe un número
// y devuelve true o false dependiendo si el número es primo o no. Por ej, si el usuario ingresa 4, 
// debe imprimir 2,3,5,7.

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

/**
 * @brief Verifica si un número entero es primo.
 *
 * Un número es primo si es mayor que 1 y no tiene divisores
 * además de 1 y él mismo. La función utiliza la optimización
 * de verificar divisibilidad solo hasta la raíz cuadrada del número.
 *
 * @param n El número a verificar si es primo.
 * @return true si el número es primo, false si no lo es.
 */
bool es_primo(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true; 
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false; 
    }

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false; 
        }
    }

    return true; 
}

/**
 * @brief Imprime todos los números primos hasta el número especificado.
 *
 * Esta función recorre los números desde 0 hasta `n` y utiliza la
 * función `es_primo` para verificar si cada número es primo. Los
 * números primos encontrados se imprimen en la consola.
 *
 * @param n El número hasta el cual se deben imprimir los primos.
 */
void imprimir_primos_hasta(int n){
    for (int i = 0; i <= n; i++) {
        if (es_primo(i)) {
            printf("%d >> ", i);
        }
    }
    printf("FIN\n");
}

/**
 * @brief Función principal que imprime los números primos hasta 10.
 *
 * Llama a `imprimir_primos_hasta` con el valor 10 para imprimir los
 * números primos menores o iguales a 10.
 *
 * @return 0 si la ejecución fue exitosa.
 */
int main(void) {
    imprimir_primos_hasta(10);
    return 0;
}