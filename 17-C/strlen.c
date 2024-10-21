// Implementar la función unsigned int strlen(const char *s) que devuelve la
// longitud de la cadena s (sin contar el último caracter '\0').
// a) En forma iterativa.
// b) En forma recursiva.

/**
 * Calcula la longitud de una cadena de caracteres de forma iterativa.
 *
 * @param s Un puntero a la cadena de caracteres.
 * @return La longitud de la cadena, sin contar el carácter nulo ('\0').
 */
unsigned int strlen_iter(const char* s) {
    unsigned int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

/**
 * Calcula la longitud de una cadena de caracteres de forma recursiva, a partir de un índice.
 *
 * @param s Un puntero a la cadena de caracteres.
 * @param d El índice desde el cual se empieza a calcular la longitud.
 * @return La longitud restante de la cadena a partir del índice d.
 */
unsigned int strlen_rec_desde(const char* s, int d) {
    if (s[d] == '\0') {
        return 0;
    }
    return 1 + strlen_rec_desde(s, d + 1);
}

/**
 * Calcula la longitud de una cadena de caracteres de forma recursiva.
 *
 * @param s Un puntero a la cadena de caracteres.
 * @return La longitud de la cadena, sin contar el carácter nulo ('\0').
 */
unsigned int strlen_rec(const char* s) {
    return strlen_rec_desde(s, 0);
}