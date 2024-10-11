def suma_en_listas(lista1: list, lista2: list) -> list:
    """
    Recibe dos listas de números enteros y devuelve una nueva lista donde cada i-ésimo elemento 
    representa la suma de los i-ésimos elementos de cada lista. Si las listas no tienen la misma 
    cantidad de elementos, la lista resultante tendrá la misma cantidad de elementos que la menor 
    de las listas.

    Parameters:
    lista1 (list): La primera lista de números enteros.
    lista2 (list): La segunda lista de números enteros.

    Returns:
    list: Una nueva lista donde cada elemento es la suma de los correspondientes elementos de `lista1` y `lista2`.
    """
    suma = []
    suma_en_listas_desde(lista1, lista2, suma, 0)
    return suma


def suma_en_listas_desde(lista1: list, lista2: list, suma: list, desde: int) -> None:
    """
    Función auxiliar recursiva que calcula la suma de los elementos de `lista1` y `lista2` desde 
    un índice dado, y agrega los resultados a la lista `suma`.

    Parameters:
    lista1 (list): La primera lista de números enteros.
    lista2 (list): La segunda lista de números enteros.
    suma (list): La lista donde se almacenan las sumas calculadas.
    desde (int): El índice desde el cual se empieza a calcular la suma de los elementos.

    Returns:
    None: Modifica la lista `suma` en el lugar, pero no devuelve ningún valor explícito.
    """
    if desde == len(lista1) or desde == len(lista2):
        return
    suma.append(lista1[desde] + lista2[desde])
    suma_en_listas_desde(lista1, lista2, suma, desde + 1)
