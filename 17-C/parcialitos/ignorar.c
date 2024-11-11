// Implementar en C una función que reciba dos arreglos de enteros (y sus respectivos tamaños), y que
// imprima los números del primer arreglo que no están presentes en el segundo.

// Ejemplo:

// int numeros[] = {1, 2, 7, 2, 3, 5};
// int ignorar[] = {2, 3};
// imprimir_faltantes(numeros, 6, ignorar, 2);
// Debe imprimir 1, 7 y 5

#include <stdio.h>

/**
 * Verifica si un valor está presente en un arreglo.
 * 
 * Recorre el arreglo y compara cada elemento con el valor proporcionado.
 * Si el valor se encuentra, la función retorna 1 (verdadero); de lo contrario, retorna 0 (falso).
 * 
 * @param arr El arreglo en el que se buscará el valor.
 * @param len La longitud del arreglo.
 * @param valor El valor a buscar en el arreglo.
 * 
 * @return 1 si el valor está presente en el arreglo, 0 en caso contrario.
 */
unsigned int pertenece(int *arr, size_t len, int valor){
    for (size_t i = 0; i < len; i++)
    {
        if(arr[i] == valor){
            return 1;
        }
    }
    return 0;
}

/**
 * Imprime los elementos de un arreglo que no están presentes en otro arreglo.
 * 
 * La función recorre el primer arreglo y, para cada elemento, verifica si está presente en el segundo arreglo.
 * Si el elemento no está presente en el segundo arreglo, se imprime en la pantalla.
 * 
 * @param arr El primer arreglo cuyos elementos se evaluarán.
 * @param len1 La longitud del primer arreglo.
 * @param ignorar El segundo arreglo que contiene los elementos a ignorar.
 * @param len2 La longitud del segundo arreglo.
 */
void imprimir_faltantes(int *arr, size_t len1, int *ignorar, size_t len2){
    for (size_t i = 0; i < len1; i++)
    {
        if(!pertenece(ignorar, len2, arr[i])){
            printf("%d >> ", arr[i]);
        }
    }
    printf("FIN\n");
}

/**
 * Función principal que demuestra el uso de la función imprimir_faltantes.
 * 
 * Inicializa dos arreglos: uno con los números a evaluar y otro con los números a ignorar.
 * Luego llama a imprimir_faltantes para imprimir los números del primer arreglo que no están en el segundo.
 * 
 * @return 0 al finalizar correctamente.
 */
int main(void){
    int numeros[] = {1, 2, 7, 2, 3, 5};
    int ignorar[] = {2, 3};
    imprimir_faltantes(numeros, 6, ignorar, 2);

    return 0;
}