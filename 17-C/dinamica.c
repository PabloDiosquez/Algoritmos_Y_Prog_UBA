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

/*
2. Considerar el siguiente ejemplo. ¿La invocación a free realmente libera la me-
moria apuntada por el puntero a 

  int *a = malloc(42);
  int *b = a;
  free(b);

¿La invocación a free realmente libera la memoria apuntada por el puntero a?

Sí, la invocación a free(b) libera la memoria apuntada por el puntero a.

Explicación:

1. Asignación de memoria:
   int *a = malloc(42);
   - La función malloc asigna 42 bytes de memoria en el heap y devuelve un puntero a la primera 
   dirección de ese bloque de memoria. El puntero a apunta a esta ubicación.

2. Asignación de b:
   int *b = a;
   - El puntero b se asigna para apuntar a la misma dirección de memoria que a. Esto significa que
    tanto a como b apuntan al mismo bloque de memoria en el heap.

3. Liberación de memoria:
   free(b);
   - Al invocar free(b), se libera el bloque de memoria al que b (y también a) apuntan. Después de
    esta operación, la memoria ya no está asignada, y el uso de los punteros a o b sin reasignarlos sería un comportamiento indefinido.

Nota importante:

Después de la llamada a free(b), los punteros a y b siguen apuntando a la misma dirección de memoria,
pero esa memoria ya no está reservada. Por lo tanto, intentar acceder a esa memoria después de free
puede causar errores en tiempo de ejecución o comportamiento impredecible. Es una buena práctica 
establecer los punteros a NULL después de liberar la memoria para evitar accesos accidentales:

    free(b);
    a = NULL;
    b = NULL;

De esta manera, queda claro que los punteros ya no están apuntando a memoria válida.
*/