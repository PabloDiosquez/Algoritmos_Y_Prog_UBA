/*  Implementar funciones que reciban un arreglo de números y su longitud y realicen las operaciones
    detalladas abajo. Utilice notación de punteros exclusivamente.

    completar el vector con ceros
    completar el vector con unos
    calcular y retornar la suma por la interfaz
    calcular y retornar la media por la interfaz
    retornar el valor máximo del arreglo por la interfaz
    retornar el valor mínimo del arreglo por la interfaz
    modificar los elementos del vector reemplazándolos por sus valores al cuadrado
    modificar los elementos del arreglo reemplazando cada elemento por su signo. Considere  
    modificar los elementos del arreglo reemplazándolos por las diferencias finitas de primer orden.
    Para hacer esto, usando como caso de ejemplo el primer y segundo elemento               
        *(v + 0) = *(v + 1) - *(v + 0);
        *(v + 1) = *(v + 2) - *(v + 1);
*/

#include <stddef.h>

void ceros(int* arr, size_t len){
    if(arr == NULL || len == 0) return;

    for (size_t i = 0; i < len; i++)
    {
        *(arr + i) = 0;
    }   
}

void unos(int* arr, size_t len){
    if(arr == NULL || len == 0) return;

    for (size_t i = 0; i < len; i++)
    {
        *(arr + i) = 1;
    }   
}

void suma_en_arr(int* arr, size_t len, int* suma){
    if(arr == NULL || len == 0) return;

    for (size_t i = 0; i < len; i++)
    {
        *suma += *(arr + i);
    }
}

void suma_en_arr(int* arr, size_t len, float* media){
    if(arr == NULL || len == 0) return;

    int suma = 0;
    for (size_t i = 0; i < len; i++)
    {
        suma += *(arr + i);
    }

    *media = (float)suma / len;
}