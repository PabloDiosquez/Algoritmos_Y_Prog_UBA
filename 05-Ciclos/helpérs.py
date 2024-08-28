def es_divisible(dividendo: int, divisor: int) -> bool:
    """
    Indica si el primer número (dividendo) es divisible por el segundo (divisor).
    
    Lanza ValueError si se intenta dividir por 0.
    
    Parameters:
    dividendo (int): El número que se desea dividir.
    divisor (int): El número por el cual se desea dividir.
    
    Returns:
    bool: True si el dividendo es divisible por el divisor, False en caso contrario.
    """
    if divisor == 0:
        raise ValueError('No se puede dividir por 0.')
    return dividendo % divisor == 0

def es_primo(numero: int) -> bool:
    """
    Indica si el número dado es un número primo.
    
    Parameters:
    numero (int): El número que se desea evaluar.
    
    Returns:
    bool: True si el número es primo, False en caso contrario.
    """
    return numero > 1 and not tiene_divisores_propios(numero)

def tiene_divisores_propios(numero: int) -> bool:
    """
    Indica si el número dado tiene divisores propios en el intervalo [2, numero//2].
    
    Parameters:
    numero (int): El número que se desea evaluar.
    
    Returns:
    bool: True si el número tiene divisores propios, False en caso contrario.
    """
    for i in range(2, (numero // 2) + 1):
        if es_divisible(numero, i):
            return True
    return False

def obtener_exponente_en_factorizacion(numero: int, divisor: int) -> int:
    """
    Devuelve el exponente del divisor en la factorización del primer número.
    Si el divisor no divide al número, devuelve 0.
    
    Parameters:
    numero (int): El número que se desea factorizar.
    divisor (int): El divisor para el cual se desea encontrar el exponente.
    
    Returns:
    int: El exponente del divisor en la factorización del número.
    """
    if not es_divisible(numero, divisor):
        return 0
    return 1 + obtener_exponente_en_factorizacion(numero // divisor, divisor)
