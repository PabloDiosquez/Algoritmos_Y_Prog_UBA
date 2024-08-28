# Escribir una función que reciba un número entero k e imprima su descomposición
# en factores primos.

from helpers import es_divisible, es_primo, obtener_exponente_en_factorizacion

def imprimir_factorización_primos(n: int) -> None:
    "Dado un número, imprime su factorización en primos."
    factorizacion = []
    for i in range(2, (n//2) + 1):
        if es_primo(i) and es_divisible(n, i):
            factorizacion.append(f'{i}^{obtener_exponente_en_factorizacion(n, i)}')
    factorizacion = 'x'.join(factorizacion)
    
    print(f'{n} = {factorizacion}') 

imprimir_factorización_primos(75) 