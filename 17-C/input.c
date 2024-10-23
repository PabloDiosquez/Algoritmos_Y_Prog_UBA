// Escribir una función que se comporte como la función input de Python. Debe
// recibir un mensaje a imprimir, y luego debe leer una línea de texto de la consola y devolverla.
// La cadena producida debe ser alojada en el heap, y debe terminar con un \0. Asumir que la línea
// de texto ingresada no puede superar los 100 caracteres. Utilizar las funciones de la biblioteca
// estándar fputs y fgets.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Lee una línea de texto desde la consola después de mostrar un mensaje.
 * 
 * Esta función muestra un mensaje en la consola y luego lee una línea de entrada
 * del usuario. La línea de texto leída se almacena en la memoria dinámica (heap)
 * y se devuelve al llamador. Si ocurre un error durante la lectura o la
 * asignación de memoria, la función devuelve NULL.
 * 
 * @param mensaje Mensaje que se muestra al usuario antes de leer la entrada.
 * @return char* Un puntero a la cadena de texto leída, alojada en el heap.
 *         Retorna NULL si ocurre un error.
 */
char* input(const char* mensaje) {
    fputs(mensaje, stdout);
    
    char buffer[101];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return NULL;
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    char* r = malloc(100);
    if (r == NULL) {
        return NULL;
    }
    
    strcpy(r, buffer);

    return r;
}

/**
 * @brief Función principal que utiliza la función input para leer un mensaje del usuario.
 * 
 * La función muestra un mensaje pidiendo al usuario que ingrese un texto,
 * lee el texto ingresado, lo muestra en pantalla, y luego libera la memoria utilizada.
 * Si ocurre un error al leer la entrada, se imprime un mensaje de error.
 * 
 * @return int Retorna 0 si la ejecución es exitosa, 1 si ocurre un error.
 */
int main(void) {
    char* texto = input("Ingrese algún mensaje: ");

    if (texto == NULL) {
        printf("Algo salió mal :(\n");
        return 1;
    }

    printf("Se ingresó %s", texto);
    free(texto);
    return 0;
}