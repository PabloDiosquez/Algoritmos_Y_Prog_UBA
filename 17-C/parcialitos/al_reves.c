// Escribir en C un programa que le pregunte al usuario por 5 números enteros y luego los imprima
// de manera inversa al orden en que fueron ingresados.

#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 5

/**
 * @brief Solicita al usuario ingresar 5 números enteros y los imprime en orden inverso.
 * 
 * Esta función solicita al usuario que ingrese 5 números enteros, los almacena en un arreglo
 * y luego los imprime en el orden inverso al que fueron ingresados.
 * Utiliza la función `fgets` para obtener las entradas del usuario y `atoi` para convertirlas en números enteros.
 * 
 * @note Si el usuario ingresa un valor que no se puede convertir a entero, el programa no hace una validación adicional
 * y almacenará el valor convertido como 0.
 */
void imprimir_al_reves(){
    char buffer[20]; 
    int numeros[CANTIDAD];
    
    printf("Ingrese %d números. Se los imprimirá al revés.\n", CANTIDAD);
    int i = 0;
    for(; i < CANTIDAD; i++){
        printf("Número: \n");
        if(fgets(buffer, sizeof(buffer), stdin) == NULL){
            fprintf(stderr, "Ocurrió un error inesperado.\n");
            return;
        }
        numeros[i] = atoi(buffer);  
    }

    printf("Al revés:\n");
    i--;  
    for (; i >= 0; i--){
        printf("%d >> ", numeros[i]);  
    }
    printf("FIN\n");
}

/**
 * @brief Función principal del programa.
 * 
 * La función `main` llama a la función `imprimir_al_reves` para ejecutar la lógica del programa:
 * solicitar al usuario 5 números y luego imprimirlos en orden inverso.
 * 
 * @return Retorna 0 al finalizar correctamente.
 */
int main(void){
    imprimir_al_reves(); 
    return 0; 
}
