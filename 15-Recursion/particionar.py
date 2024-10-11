# Hacer una función recursiva que recibe una lista L y una función f, y devuelve una nueva lista que contiene al principio todos los elementos de L para los que f devuelve True, y al final el resto de los elementos. No es necesario mantener el orden relativo de los elementos en cada grupo. Ejemplo: particionar([7,8,3,5,2], es_par) → [8,2,5,3,7]

def particionar(L: list, f) -> list:
    """
    Recibe una lista `L` y una función booleana `f`. Devuelve una nueva lista donde todos los elementos 
    de la lista original que cumplen con la función `f` están al principio, y el resto de los elementos 
    se encuentran al final.

    Parameters:
    L (list): La lista original de elementos.
    f (function): Una función booleana que se aplica a cada elemento de la lista.

    Returns:
    list: Una nueva lista con los elementos que cumplen la función `f` al principio, y los que no la cumplen al final.
    """
    particion = []
    particionar_desde(L, f, particion, 0)
    return particion

def particionar_desde(L: list, f, particion: list, desde: int) -> None:
    """
    Función auxiliar recursiva que procesa la lista `L` a partir del índice dado, insertando los elementos que cumplen con la función `f` al principio de la lista `particion`, y los que no cumplen al final.

    Parameters:
    L (list): La lista de elementos a procesar.
    f (function): Función booleana que determina el criterio de partición.
    particion (list): La lista donde se insertan los elementos particion.
    desde (int): El índice desde el cual se comienza a procesar la lista `L`.

    Returns:
    None: Modifica la lista `particion` en el lugar, pero no devuelve ningún valor explícito.
    """
    if desde == len(L):
        return
    
    if f(L[desde]):
        particion.insert(0, L[desde])
    else:
        particion.append(L[desde])

    particionar_desde(L, f, particion, desde + 1)
