# Escribir una función que reciba un número entero k e imprima su descomposición
# en factores primos.

from helpers import es_divisible, es_primo, obtener_exponente_en_factorizacion

def imprimir_factorizacion_primos(numero: int) -> None:
    """
    Dado un número, imprime su factorización en primos.

    Si el número es menor o igual a 1, o si es primo, se imprime el número tal cual.
    De lo contrario, se imprime la factorización en primos del número.
    
    Parameters:
    numero (int): El número que se desea factorizar.
    """

    if numero <= 1 or es_primo(numero):
        print(f'{numero} = {numero}')
        return
    
    factorizacion = []
    for i in range(2, (numero // 2) + 1):
        if es_primo(i) and es_divisible(numero, i):
            exponente = obtener_exponente_en_factorizacion(numero, i)
            factorizacion.append(f'{i}^{exponente}')
    
    factorizacion_str = ' x '.join(factorizacion)
    print(f'{numero} = {factorizacion_str}')
