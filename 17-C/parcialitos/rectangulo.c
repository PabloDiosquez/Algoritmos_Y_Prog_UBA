// Escribir en C un programa que pide al usuario un número n >= 1 (repitiendo hasta que el número 
// ingresado sea válido), y luego imprime un triángulo de altura n. Ejemplo:

// Ingrese la altura del triangulo: 3
// *
// **
// ***

#include <stdio.h>

#define CARACTER '*' 

/**
 * @brief Imprime un triángulo de altura especificada.
 * 
 * Esta función imprime un triángulo de asteriscos cuyo número de filas es igual a la altura
 * proporcionada. En cada fila, el número de asteriscos aumenta progresivamente.
 * 
 * @param altura Altura del triángulo. La altura debe ser un valor entero mayor o igual a 1.
 */
void imprimir_rectangulo(int altura){
    for (size_t i = 0; i < altura; i++){
        for (size_t j = 0; j <= i; j++){
            printf("%c", CARACTER);  
        }
        printf("\n");  
    }
}

/**
 * @brief Función principal del programa.
 * 
 * La función `main` pide al usuario que ingrese la altura del triángulo y luego llama a
 * la función `imprimir_rectangulo` para imprimir el triángulo correspondiente.
 * Si el valor ingresado no es válido (es decir, menor que 1), se repetirá el pedido hasta que
 * se ingrese un valor válido.
 * 
 * @return 0 al finalizar correctamente.
 */
int main(void){
    int altura;
    do {
        printf("Ingrese la altura del triángulo (n >= 1): ");
        if (scanf("%d", &altura) != 1 || altura < 1) {
            while (getchar() != '\n'); 
            printf("Entrada inválida. Por favor ingrese un número entero mayor o igual a 1.\n");
        }
    } while (altura < 1);

    imprimir_rectangulo(altura);  

    return 0;  
}