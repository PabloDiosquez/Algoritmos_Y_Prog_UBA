#include <stdio.h>
#include <stdlib.h>

// 1. Analizar el funcionamiento de la siguiente función en lenguaje C. ¿Hay algún
// problema en su implementación?
//  void f() {
//  int *p = malloc(sizeof(int) * 100);
//  for (int i = 0; i < 10; i++) {
//       p[i] = i+1000;
//  }
//  for (int j = 0; j < 100; j++) {
//       printf("%d\n", p[i]);
//      }
//  }

// Análisis de la implementación

// 1. Asignación de memoria con malloc:
//    - La función reserva memoria para un arreglo de 100 enteros (`sizeof(int) * 100`).
// Esto está bien, ya que se garantiza que hay suficiente memoria para almacenar 100 enteros.

// 2. Primer bucle for:
//    - El bucle itera desde `i = 0` hasta `i < 10`, asignando valores a los primeros 10 elementos
// del arreglo. Cada posición `p[i]` se establece en `i + 1000`. Esto es válido y no causa errores,
// ya que el acceso al arreglo está dentro de los límites asignados (0 a 99).

// 3. Segundo bucle for:
//    - En este bucle, hay un error en el uso de la variable `i` en la línea `printf("%d\n", p[i]);`.
// La variable `i` no está definida en este contexto, ya que solo se declaró en el primer bucle.
// La variable correcta que debería usarse aquí es `j`, por lo que la línea debería ser:
//      ```
//      printf("%d\n", p[j]);
//      ```
//    - Este error causará un problema de compilación, ya que `i` no está en el alcance.

// 4. Falta de liberación de memoria:
//    - La función reserva memoria con `malloc`, pero nunca libera la memoria asignada con `free`.
// Esto provoca una fuga de memoria (*memory leak*), ya que la memoria asignada no se devuelve al 
// sistema.

// Solución propuesta

void f() {
    int *p = malloc(sizeof(int) * 100);
    if (p == NULL) {                   // Verificación de error en la asignación de memoria
        printf("Error en la asignación de memoria.\n");
        return;
    }

    for (int i = 0; i < 10; i++) {
        p[i] = i + 1000;
    }
    for (int j = 0; j < 100; j++) {    // Usar la variable j en lugar de i
        printf("%d\n", p[j]);
    }

    free(p);                           
}