# Escribir una función recursiva que dada una cadena le haga un "flip" de mayúsculas, es decir, que devuelva una nueva cadena con los caracteres en minúscula transformados a mayúscula y los caracteres en mayúscula transformados en minúscula.

# flip_mayusculas('AlgoRitmOs Y ProGramAcion 1') ==> 'aLGOrITMoS y pROgRAMaCION 1'

def flip_mayusculas(cadena: str) -> str:
    """
    Recibe una cadena y devuelve una nueva cadena con las mayúsculas transformadas a minúsculas 
    y las minúsculas a mayúsculas, manteniendo el resto de los caracteres igual.

    Parameters:
    cadena (str): La cadena a transformar.

    Returns:
    str: La cadena resultante con las mayúsculas y minúsculas invertidas.
    """
    return flip_mayusculas_desde(cadena, 0)

def flip_mayusculas_desde(cadena: str, desde: int) -> str:
    """
    Función recursiva auxiliar que invierte las mayúsculas y minúsculas de los caracteres de 
    la cadena, comenzando desde un índice dado.

    Parameters:
    cadena (str): La cadena a transformar.
    desde (int): El índice a partir del cual se procesa la cadena.

    Returns:
    str: La cadena resultante con las mayúsculas y minúsculas invertidas desde el índice dado hasta el final.
    """
    if desde == len(cadena):
        return ''
    return flip(cadena[desde]) + flip_mayusculas_desde(cadena, desde + 1)

def flip(caracter: str) -> str:
    """
    Recibe un caracter y devuelve el mismo en minúscula si el original estaba en mayúscula 
    y en mayúscula si el original estaba en minúscula. Si no es una letra, lo devuelve sin cambios.

    Parameters:
    caracter (str): Un caracter a transformar.

    Returns:
    str: El caracter invertido en mayúscula o minúscula, o el mismo caracter si no es una letra.
    """
    if caracter.islower():
        return caracter.upper()
    return caracter.lower()