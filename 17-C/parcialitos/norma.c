// Escribir en lenguaje C una función que recibe un arreglo de enteros y su longitud, y devuelve la norma
// del arreglo. La norma se calcula como $\sqrt{\sum{{x_i}^2}}$.

// Nota: la biblioteca math.h contiene las funciones double sqrt(double x) y double pow(double x, double y).

#include <stddef.h>
#include <math.h>

/**
 * Calcula la norma (longitud) de un arreglo de enteros.
 * La norma se calcula como la raíz cuadrada de la suma de los cuadrados de los elementos del arreglo.
 * 
 * La fórmula utilizada es: 
 *  norma = √(Σ{xi^2})
 * 
 * @param arr Un arreglo de enteros cuyos elementos se utilizarán para calcular la norma.
 * @param len La longitud del arreglo.
 * 
 * @return La norma del arreglo como un valor de tipo double.
 */
double norma(int *arr, size_t len){
    double suma_cuad = 0.0;
    for (size_t i = 0; i < len; i++)
    {
        suma_cuad += pow(arr[i], 2);
    }
    return sqrt(suma_cuad);
}