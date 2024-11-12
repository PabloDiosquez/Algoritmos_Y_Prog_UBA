// Escribir en C la función contar_menores, que recibe un vector de enteros y la cantidad de elementos, 
// y devuelve cuántos números del vector son menores al valor recibido.

/**
 * @brief Cuenta cuántos números en el arreglo son menores al valor dado,
 *        comenzando desde un índice específico.
 * 
 * @param arr Un puntero al arreglo de enteros.
 * @param len La cantidad total de elementos en el arreglo.
 * @param valor El valor con el que se comparan los elementos del arreglo.
 * @param desde El índice desde el cual comenzar a contar.
 * @return El número de elementos menores al valor en el arreglo desde el índice `desde`.
 */
int contar_menores_desde(int *arr, unsigned int len, int valor, unsigned int desde) {
    if (desde == len) {
        return 0;
    }

    int cant_menores = contar_menores_desde(arr, len, valor, desde + 1);

    return arr[desde] < valor ? 1 + cant_menores : cant_menores;
}

/**
 * @brief Cuenta cuántos números en el arreglo son menores al valor dado,
 *        comenzando desde el primer elemento.
 *
 * @param arr Un puntero al arreglo de enteros.
 * @param len La cantidad total de elementos en el arreglo.
 * @param valor El valor con el que se comparan los elementos del arreglo.
 * @return El número de elementos menores al valor en el arreglo.
 */
int contar_menores(int *arr, unsigned int len, int valor) {
    return contar_menores_desde(arr, len, valor, 0);
}