// Implemente el TDA complejo, con las siguientes primitivas:

// complejo_t * complejo_crear(double, double);

// void complejo_destruir(complejo_t *);

// complejo_t * complejo_copiar(complejo_t *, const complejo_t *);

// complejo_t * complejo_clonar(const complejo_t *);

// double complejo_get_real(const complejo_t *);

// double complejo_get_imag(const complejo_t *);

// double complejo_set_real(complejo_t *, double);

// double complejo_set_imag(complejo_t *, double);

// complejo_t * complejo_conjugar(complejo_t *);

#include <stdlib.h>

typedef struct {
    double re;
    double im;
} complejo_t;

complejo_t *complejo_crear(double re, double im){
    complejo_t *nuevo = malloc(sizeof(complejo_t));
    if(nuevo == NULL){
        return NULL;
    }
    nuevo->re = re;
    nuevo->im = im;

    return nuevo;
}

void complejo_destruir(complejo_t *complejo){
    if(complejo != NULL){
        free(complejo);
    }
}

complejo_t *complejo_copiar(complejo_t *dest, const complejo_t *orig){
    if(dest == NULL || orig == NULL){
        return NULL;
    }

    dest->re = orig->re; 
    dest->im = orig->im;

    return dest; 
}

complejo_t *complejo_clonar(const complejo_t *orig){
    if(orig == NULL){
        return NULL;
    }
    complejo_t *nuevo = malloc(sizeof(complejo_t));
    if(nuevo == NULL){
        return NULL;
    }

    nuevo->re = orig->re;
    nuevo->im = orig->im;

    return nuevo;
}

double complejo_get_real(const complejo_t *compl){
    if(compl != NULL){
        return compl->re;
    }
}

double complejo_get_imag(const complejo_t *compl){
    if(compl != NULL){
        return compl->im;
    }
}

void complejo_set_real(complejo_t *compl, double re){
    if(compl == NULL){
        return;
    }
    compl->re = re;
}

void complejo_set_imag(complejo_t *compl, double im){
    if(compl == NULL){
        return;
    }
    compl->im = im;
}

complejo_t *complejo_conjugar(complejo_t *compl){
    if(compl == NULL){
        return NULL;
    }
    compl->im = -compl->im;
}