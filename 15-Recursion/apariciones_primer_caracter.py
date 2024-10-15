# Implementar una función recursiva que dada una cadena, devuelva la cantidad de veces que aparece el primer caracter (sin contar la primera aparición), en las posiciones pares de la cadena. Ej:

# Para "No es tan fácil, que todo te salga bien" debe devolver 2
# Para "No es tan fácil que todo te salga bien" debe devolver 1

def contar_apariciones_primer_caracter(s: str) -> int:
    """
    Cuenta las apariciones del primer carácter en posiciones pares de la cadena, 
    excluyendo la primera aparición.
    """
    return _contar_apariciones(s, s[0], 1)

def _contar_apariciones(s: str, c: str, i: int) -> int:
    """
    Función auxiliar recursiva para contar las apariciones de un carácter en posiciones pares.

    Recorre la cadena a partir del índice 'i', verificando si el carácter en esa posición
    coincide (sin distinguir mayúsculas y minúsculas) con el carácter dado 'c' y si 'i' 
    es una posición par.
    """
    if i == len(s):
        return 0

    cant_apariciones_actual = _contar_apariciones(s, c, i + 1)
    if i % 2 == 0 and s[i].lower() == c.lower():
        return 1 + cant_apariciones_actual

    return cant_apariciones_actual