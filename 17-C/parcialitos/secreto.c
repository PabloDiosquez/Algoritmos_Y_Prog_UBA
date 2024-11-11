// Escribir en C una función que reciba un número secreto n (de tipo int) y le pregunte un número al 
// usuario. Si el número ingresado es distinto a n, debe indicarle si es mayor o menor y volver a 
// pedirle otro número. Si es igual, debe felicitar al usuario y mostrar en cuántos intentos adivinó.

#include <stdio.h>
#include <stdlib.h>

/**
 * Cuenta la cantidad de intentos realizados para adivinar un número secreto.
 * 
 * La función solicita al usuario ingresar números, comparándolos con el número secreto.
 * Después de cada intento, proporciona una pista sobre si el número ingresado es mayor o menor que el número secreto.
 * Cuando el número ingresado coincide con el número secreto, se muestra un mensaje de felicitación y se devuelve el total de intentos.
 * Si ocurre un error de entrada, se informa y la función devuelve 0.
 * 
 * @param numero_secreto El número secreto que el usuario debe adivinar.
 * @return El número total de intentos realizados para adivinar el número secreto.
 */
unsigned int contar_intentos(int numero_secreto) {
    unsigned int total_intentos = 0;
    char entrada[20];

    while (1) {
        printf("Ingrese un número: ");
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            fprintf(stderr, "Error de entrada inesperado.\n");
            return 0;
        }

        int numero_ingresado = atoi(entrada);
        total_intentos++;

        if (numero_ingresado == numero_secreto) {
            printf("Felicitaciones! El número secreto es %d\n", numero_secreto);
            return total_intentos;
        }

        if (numero_ingresado > numero_secreto) {
            printf("El número ingresado es mayor que el número secreto.\n");
        } else {
            printf("El número ingresado es menor que el número secreto.\n");
        }
    }
}