// Implemente el TDA cadena, con las siguientes primitivas:

#include <stdlib.h>
#include <string.h>


typedef struct cadena {
    char *str; 
} cadena_t;

/**
 * @brief Crea una nueva instancia de cadena_t con una copia de la cadena proporcionada.
 *
 * @param s Puntero a una cadena terminada en nulo.
 * @return Puntero a una estructura cadena_t con la cadena copiada, o NULL si falla.
 */
cadena_t *cadena_crear(const char *s) {
    if (s == NULL) {
        return NULL;
    }

    cadena_t *cadena = malloc(sizeof(cadena_t));
    if (cadena == NULL) {
        return NULL; 
    }

    size_t len = strlen(s);
    char *str = malloc(len + 1); 
    if (str == NULL) {
        free(cadena); 
        return NULL;
    }

    strcpy(str, s);

    cadena->str = str;
    return cadena;
}


// void cadena_destruir(cadena_t *);

// cadena_t * cadena_copiar(cadena_t *, const cadena_t *);

// cadena_t * cadena_clonar(const cadena_t *);

// cadena_t * cadena_concatenar(cadena_t *, const cadena_t *);

// cadena_t * cadena_strcpy(cadena_t *, const char *);

// cadena_t * cadena_strcat(cadena_t *, const char *);