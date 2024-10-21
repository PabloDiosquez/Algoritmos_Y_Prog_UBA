// Escribir una función que reciba un número entero n y calcule el factorial de n.
// a) En forma iterativa.
// b) En forma recursiva.

/**
 * Calcula el factorial de un número entero n de forma iterativa.
 *
 * @param n El número entero para el cual se quiere calcular el factorial.
 * @return El factorial de n (n!).
 */
int fact(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

/**
 * Calcula el factorial de un número entero n de forma recursiva.
 *
 * @param n El número entero para el cual se quiere calcular el factorial.
 * @return El factorial de n (n!).
 */
int fact_rec(int n) {
    if (n == 0) {
        return 1;
    }
    return fact_rec(n - 1) * n;
}