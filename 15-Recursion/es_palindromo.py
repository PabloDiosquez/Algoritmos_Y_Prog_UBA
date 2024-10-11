# Escribir una función recursiva que reciba una cadena (sin espacios), y devuelva un booleano indicando si la cadena es o no un palíndromo.

def es_palindromo(cadena: str) -> bool:
    """
    Indica si la cadena recibida es un palíndromo. Un palíndromo es una cadena que se lee igual 
    de izquierda a derecha que de derecha a izquierda.

    Precondición:
    - La cadena recibida no debe contener espacios.

    Parameters:
    cadena (str): La cadena a evaluar.

    Returns:
    bool: `True` si la cadena es un palíndromo, `False` en caso contrario.
    """
    return _es_palindromo(cadena, 0, len(cadena) - 1)

def _es_palindromo(cadena: str, s: int, e: int) -> bool:
    """
    Función recursiva auxiliar que evalúa si una subcadena delimitada por los índices `s` (inicio) 
    y `e` (final) es un palíndromo.

    Parameters:
    cadena (str): La cadena a evaluar.
    s (int): El índice de inicio de la subcadena.
    e (int): El índice final de la subcadena.

    Returns:
    bool: `True` si la subcadena entre los índices `s` y `e` es un palíndromo, `False` en caso contrario.
    """
    if s > e:
        return True
    return cadena[s] == cadena[e] and _es_palindromo(cadena, s + 1, e - 1)