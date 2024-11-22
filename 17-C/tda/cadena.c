// Implemente el TDA cadena, con las siguientes primitivas:

#include <stdlib.h>
#include <string.h>


typedef struct cadena {
    char *str; 
} cadena_t;

/**
 * @brief Crea una nueva instancia de cadena_t con una copia de la cadena proporcionada.
 *
 * @param s Puntero a una cadena terminada en '\0'.
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

// Destruye una estructura cadena_t, liberando toda la memoria asociada.
/**
 * @brief Libera la memoria asociada a una estructura cadena_t y su cadena.
 *
 * @param cadena Puntero a la estructura cadena_t a destruir. Puede ser NULL.
 */
void cadena_destruir(cadena_t *cadena) {
    if (cadena != NULL) {
        free(cadena->str); 
        free(cadena);      
    }
}

// Copia el contenido de una cadena_t a otra.
/**
 * @brief Copia el contenido de la cadena de `orig` a `dest`.
 *
 * @param dest Puntero a la estructura cadena_t destino. Debe estar inicializada y tener suficiente memoria.
 * @param orig Puntero constante a la estructura cadena_t fuente.
 * @return Puntero a la estructura `dest` si la copia es exitosa, o NULL si ocurre un error.
 */
cadena_t *cadena_copiar(cadena_t *dest, const cadena_t *orig) {
    if (dest == NULL || orig == NULL || dest->str == NULL || orig->str == NULL) {
        return NULL;
    }

    if (strlen(dest->str) < strlen(orig->str)) {
        return NULL; 
    }

    strcpy(dest->str, orig->str); 
    return dest;
}

// Crea un clon de una estructura cadena_t.
/**
 * @brief Crea un clon de la estructura cadena_t `orig`.
 *
 * @param orig Puntero constante a la estructura cadena_t a clonar.
 * @return Puntero a una nueva estructura cadena_t con la copia, o NULL si ocurre un error.
 */
cadena_t *cadena_clonar(const cadena_t *orig) {
    if (orig == NULL || orig->str == NULL) {
        return NULL;
    }

    cadena_t *nueva = malloc(sizeof(cadena_t));
    if (nueva == NULL) {
        return NULL; 
    }

    nueva->str = malloc(strlen(orig->str) + 1);
    if (nueva->str == NULL) {
        free(nueva); 
        return NULL;
    }

    strcpy(nueva->str, orig->str); 
    return nueva;
}

#include <stdlib.h>
#include <string.h>

// Concatena el contenido de `cadena` al final de `dest`.
/**
 * @brief Concatena la cadena de `cadena` al final de `dest`.
 *
 * @param dest Puntero a la estructura cadena_t que será modificada.
 * @param cadena Puntero constante a la estructura cadena_t fuente.
 * @return Puntero a la estructura `dest` con la cadena concatenada, o NULL si ocurre un error.
 */
cadena_t *cadena_concatenar(cadena_t *dest, const cadena_t *cadena) {
    if (dest == NULL || cadena == NULL || dest->str == NULL || cadena->str == NULL) {
        return NULL;
    }

    size_t len1 = strlen(dest->str);
    size_t len = strlen(cadena->str);

    char *nueva_str = malloc(len1 + len + 1); 
    if (nueva_str == NULL) {
        return NULL; 
    }

    strcpy(nueva_str, dest->str);
    strcpy(nueva_str + len1, cadena->str);

    free(dest->str);

    dest->str = nueva_str;

    return dest;
}


// cadena_t * cadena_strcpy(cadena_t *, const char *);

// cadena_t * cadena_strcat(cadena_t *, const char *);