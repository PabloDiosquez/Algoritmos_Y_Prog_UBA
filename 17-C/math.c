/* Implementar las siguientes funciones, retornando los sumados por la interfaz:

1. void suma(int a, int b, long int * suma),

2. void resta(int a, int b, long int * resta),

3. void producto(int multiplicando, int multiplicador, float * producto),

4. void division(int dividendo, int divisor, double* division), y

5. mod(): retorna el resto de una división.

*/

// 1.
/**
 * @brief Calcula la suma de dos enteros y almacena el resultado en la ubicación proporcionada.
 *
 * La función toma dos números enteros, los suma y almacena el resultado en 
 * la dirección de memoria apuntada por `suma`. El resultado se almacena como un `long int`.
 *
 * @param a Primer número entero a sumar.
 * @param b Segundo número entero a sumar.
 * @param suma Puntero a una variable de tipo `long int` donde se almacenará la suma de `a` y `b`.
 */
void suma(int a, int b, long int* suma) {
    *suma = a + b;
}

// 2.
/**
 * @brief Calcula la resta de dos enteros y almacena el resultado en la ubicación proporcionada.
 *
 * La función toma dos números enteros, resta `b` de `a`, y almacena el resultado en 
 * la dirección de memoria apuntada por `resta`. El resultado se almacena como un `long int`.
 *
 * @param a Minuendo, el número del que se resta.
 * @param b Sustraendo, el número que se resta de `a`.
 * @param resta Puntero a una variable de tipo `long int` donde se almacenará el resultado de `a - b`.
 */
void resta(int a, int b, long int* resta) {
    *resta = a - b;
}

// 3.
/**
 * @brief Calcula el producto de dos enteros y almacena el resultado en la ubicación proporcionada.
 *
 * La función multiplica dos números enteros y almacena el resultado como un número de punto flotante 
 * en la dirección de memoria apuntada por `producto`.
 *
 * @param multiplicando El número que se va a multiplicar.
 * @param multiplicador El número por el cual se multiplica el `multiplicando`.
 * @param producto Puntero a una variable de tipo `float` donde se almacenará el producto de los dos números.
 */
void producto(int multiplicando, int multiplicador, float* producto) {
    *producto = (float)(multiplicando * multiplicador);
}

// 4.
/**
 * @brief Calcula la división de dos enteros y almacena el resultado en la ubicación proporcionada.
 *
 * La función toma dos números enteros, `dividendo` y `divisor`, y calcula la división almacenando 
 * el resultado en la dirección de memoria apuntada por `division`. Si el divisor es cero, 
 * la función no realiza la operación.
 *
 * @param dividendo El número que se divide.
 * @param divisor El número por el cual se divide el `dividendo`.
 * @param division Puntero a una variable de tipo `double` donde se almacenará el resultado de la división.
 */
void division(int dividendo, int divisor, double* division) {
    if (divisor == 0) {
        return;
    }

    *division = (double)dividendo / divisor;
}

// 5.
/**
 * @brief Calcula el resto de la división entera de dos números y almacena el resultado en la ubicación proporcionada.
 *
 * La función toma dos números enteros, calcula el resto de la división de `dividendo` por `divisor`, 
 * y almacena el resultado en la dirección de memoria apuntada por `resto`. Si el divisor es cero, 
 * la función no realiza la operación.
 *
 * @param dividendo El número del cual se calcula el resto.
 * @param divisor El número por el cual se divide el `dividendo` para obtener el resto.
 * @param resto Puntero a una variable de tipo `int` donde se almacenará el resto de la división.
 */
void mod(int dividendo, int divisor, int* resto) {
    if (divisor == 0) {
        return;
    }
    *resto = dividendo % divisor;
}