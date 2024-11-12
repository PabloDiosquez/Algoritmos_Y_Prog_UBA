// Implementar en C la función invertir_arreglo(int arreglo[], unsigned int n), que invierte 
// el arreglo de números in-place.

/**
 * Intercambia los elementos de un arreglo en las posiciones especificadas por los índices s y e.
 * 
 * @param arr Arreglo de enteros en el que se realizarán los intercambios.
 * @param s Índice del primer elemento que se intercambiará.
 * @param e Índice del segundo elemento que se intercambiará.
 */
void swap(int* arr, int s, int e){
    int aux = arr[s];  
    arr[s] = arr[e];   
    arr[e] = aux;      
}

/**
 * Invierte un arreglo de enteros de forma iterativa, intercambiando los elementos en las posiciones opuestas.
 * 
 * @param arr Arreglo de enteros a invertir.
 * @param len Longitud del arreglo (número de elementos).
 */
void invertir_arreglo(int *arr, unsigned int len){
    int s = 0, e = len - 1;  
    while(s < e){             
        swap(arr, s, e);      
        s++;                  
        e--;                  
    }
}

/**
 * Invierte una sección específica de un arreglo entre los índices s y e de forma recursiva.
 * 
 * @param arr Arreglo de enteros que contiene los elementos a invertir.
 * @param s Índice inicial de la sección del arreglo que se invertirá.
 * @param e Índice final de la sección del arreglo que se invertirá.
 */
void invertir_arreglo_entre(int *arr, int s, int e){
    if(s > e){               
        return;               
    }
    swap(arr, s, e);          
    invertir_arreglo_entre(arr, s+1, e-1);  
}

/**
 * Invierte un arreglo completo de enteros de forma recursiva utilizando la función auxiliar.
 * 
 * @param arr Arreglo de enteros a invertir.
 * @param len Longitud del arreglo (número de elementos).
 */
void invertir_arreglo_rec(int *arr, unsigned int len){
    invertir_arreglo_entre(arr, 0, len - 1);  
}