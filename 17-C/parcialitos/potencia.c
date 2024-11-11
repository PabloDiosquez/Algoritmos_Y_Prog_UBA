// Implementar en C la función potencia(), que recibe la base (número entero) y el exponente 
// (número entero no negativo) y devuelva el resultado de elevar la base al exponente. 
// Nota: no pueden incluir bibliotecas para resolver la potencia, por lo que la funcion 
// math.pow no está disponible para usar.

/*
 * Calcula la potencia de una base entera elevada a un exponente entero no negativo.
 *
 * Parámetros:
 *   b - La base (entero).
 *   e - El exponente (entero sin signo, no negativo).
 *
 * Retorno:
 *   El resultado de elevar la base b a la potencia e.
 */

int potencia(int b, unsigned int e){
    if(e == 0){
        return 1;
    }

    if(e % 2 == 0){
        int res = potencia(b, e / 2);
        return res * res;
    }

    int res = potencia(b, (e-1) / 2);
    return res * res * b;
}