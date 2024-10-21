// Implementar la función void strcpy(const char *origen, char *destino) que
// copia la cadena origen en la dirección de memoria apuntada por destino. Asumir que destino
// apunta a un arreglo de caracteres con espacio suficiente (strlen(origen) + 1).


/**
 * Copia la cadena origen en la dirección de memoria apuntada por destino.
 * 
 * Asume que destino apunta a un arreglo de caracteres con espacio suficiente 
 * para almacenar la cadena origen, incluyendo el carácter nulo ('\0').
 *
 * @param origen Un puntero a la cadena de caracteres de origen.
 * @param destino Un puntero al arreglo de caracteres donde se copiará la cadena.
 */
void strcpy(const char* origen, char* destino) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';
}