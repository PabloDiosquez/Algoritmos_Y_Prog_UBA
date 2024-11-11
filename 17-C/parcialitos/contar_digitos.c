// Escribir una función en C que le pida al usuario que ingrese números del 0 al 9. Repetir este proceso
// hasta que el usuario ingresa -1. Luego, mostrar por pantalla cuántas veces ingresó cada número.

// Ayuda: usar un arreglo con las posiciones del 0 al 9 como diccionario

#include <stdio.h>
#include <stdlib.h>

/**
 * Solicita al usuario que ingrese números del 0 al 9 repetidamente, hasta que ingrese -1.
 * Luego, muestra cuántas veces se ingresó cada número.
 * 
 * La función utiliza un arreglo para contar las apariciones de cada número del 0 al 9.
 */
void contar_digitos(){
    unsigned int apariciones[10] = {0};
    char buffer[20];

    while(1){
        printf("Ingrese un número del 0 al 9 (-1 para finalizar): ");
        if(fgets(buffer, sizeof(buffer), stdin) == NULL){
            fprintf(stderr, "Ocurrió un error inesperado.\n");
            return;
        }

        int digito = atoi(buffer);

        if(digito == -1){
            break;
        }

        if(digito >= 0 && digito <= 9){
            apariciones[digito]++;
        } else {
            printf("Número no válido. Ingrese un número entre 0 y 9, o -1 para terminar.\n");
        }
    }

    printf("Apariciones:\n");
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d: %d\n", i, apariciones[i]);
    }
}

/**
 * Función principal que ejecuta la función contar_digitos().
 * 
 * @return 0 al finalizar correctamente.
 */
int main(void){
    contar_digitos();
    return 0;
}