# Escribir una función recursiva que recibe una cadena s y un caracter c, y devuelve la cantidad de apariciones de c en s.

def cant_apariciones(s: str, c: str) -> int:
    """
    Recibe una cadena de caracteres `s` y un caracter `c`, y devuelve la cantidad de 
    apariciones del caracter `c` en la cadena `s`.

    Parameters:
    s (str): La cadena en la cual se busca el caracter.
    c (str): El caracter cuya frecuencia se cuenta en la cadena.

    Returns:
    int: La cantidad de veces que el caracter `c` aparece en la cadena `s`.
    """
    return cant_apariciones_desde(s, c, 0)

def cant_apariciones_desde(s: str, c: str, desde: int) -> int:
    """
    Función auxiliar recursiva que cuenta las apariciones del caracter `c` en la cadena `s` 
    comenzando desde un índice dado.

    Parameters:
    s (str): La cadena en la cual se busca el caracter.
    c (str): El caracter cuya frecuencia se cuenta en la cadena.
    desde (int): El índice a partir del cual se realiza la búsqueda en la cadena `s`.

    Returns:
    int: La cantidad de veces que el caracter `c` aparece en `s` desde el índice `desde` hasta el final.
    """
    if desde == len(s):
        return 0
    cant_apariciones_al_momento = cant_apariciones_desde(s, c, desde + 1)
    return 1 + cant_apariciones_al_momento if s[desde] == c else cant_apariciones_al_momento
