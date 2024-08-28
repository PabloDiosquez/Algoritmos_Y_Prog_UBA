def es_divisible(n: int, k: int) -> bool:
    """Indica si el primer número es divisible por el segundo.
    Lanza ValueError si se intenta dividir por 0.
    """
    if not k:
        raise ValueError('No se puede dividir por 0.')
    return not n % k

def es_primo(n: int) -> bool:
    "Indica si el número dado es primo."
    return n > 1 and not tiene_divisores_propios(n)

def tiene_divisores_propios(n: int) -> bool:
    "Indica si el número dado tiene divisores en el intervalo [2, n//2]"
    for i in range(2, (n//2) + 1):
        if es_divisible(n, i):
            return True
    return False


def obtener_exponente_en_factorizacion(n: int, k: int) -> int:
    """
    Devuelve el exponente del divisor en la factorización del primer número. Si el 'k' no divide a 'n' devuelve 0.
    """
    if not es_divisible(n, k):
        return 0
    return 1 + obtener_exponente_en_factorizacion(n // k, k)
