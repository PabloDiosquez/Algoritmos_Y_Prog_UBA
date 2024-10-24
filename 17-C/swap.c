// Implementar una función swap que reciba 2 datos a y b por puntero y los intercambie, de forma tal que b sea a y viceversa.

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Intercambia los contenidos de dos bloques de memoria de tamaño especificado.
 *
 * Esta función intercambia los datos de los bloques de memoria apuntados por
 * `ptr1` y `ptr2`, cada uno de tamaño `size` bytes. Los bloques de memoria deben ser 
 * lo suficientemente grandes para contener los `size` bytes especificados.
 *
 * @param ptr1 Puntero al primer bloque de memoria.
 * @param ptr2 Puntero al segundo bloque de memoria.
 * @param size Tamaño de los bloques de memoria en bytes.
 */
void swap(void* ptr1, void* ptr2, size_t size) {
    void* temp = malloc(size);
    if (temp == NULL) {
        return;
    }

    memcpy(temp, ptr1, size);
    memcpy(ptr1, ptr2, size);
    memcpy(ptr2, temp, size);

    free(temp);
}