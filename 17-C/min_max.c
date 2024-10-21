// Implementar una función que reciba un mensaje y dos números enteros min y
// max. La función debe pedir al usuario que ingrese un número entero entre min y max (inclusive)
// y devolverlo. Si el usuario ingresa un valor inválido se le debe informar y pedir que ingrese un
// nuevo valor, repitiendo hasta que ingrese un número válido.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CAPACIDAD_ENTRADA 30

/**
 * Pide al usuario que ingrese un número entero entre min y max (inclusive).
 *
 * La función muestra un mensaje personalizado para solicitar el número, y
 * continúa solicitando hasta que el usuario ingrese un valor válido dentro
 * del rango especificado.
 *
 * @param mensaje Un mensaje personalizado para mostrar al usuario.
 * @param min El valor mínimo aceptable.
 * @param max El valor máximo aceptable.
 * @return Un número entero ingresado por el usuario que se encuentra en el
 *         rango [min, max].
 */
int pedir_numero_entre(const char* mensaje, int min, int max) {
    char entrada[CAPACIDAD_ENTRADA];
    while (true) {
        printf("%s", mensaje);
        if (fgets(entrada, sizeof(entrada), stdin) != NULL) {
            int numero = atoi(entrada);
            if (numero >= min && numero <= max) {
                return numero;
            }
        }
        printf("El número ingresado no está en el rango [%d, %d]. Intente nuevamente.\n", min, max);
    }
}