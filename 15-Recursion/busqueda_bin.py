# Implementar el algoritmo de búsqueda binaria de manera recursiva.

def buscar(L: list, x: any) -> int:
    """
    Realiza una búsqueda binaria de un elemento en una lista ordenada.
    Si el elemento no se encuentra, devuelve -1.
    Precondición:
        La lista L debe estar ordenada de menor a mayor.
    """
    return _buscar(L, x, 0, len(L) - 1)

def _buscar(L: list, x: any, s: int, e: int) -> int:
    """
    Implementa la búsqueda binaria de manera recursiva.
    Busca el índice del elemento 'x' en la sublista de 'L' que va desde el índice 's'
    hasta el índice 'e'. Si no se encuentra, devuelve -1.
    Precondición:
        La lista L debe estar ordenada de menor a mayor.
    """
    if s > e:
        return -1

    med = s + (e - s) // 2
    if L[med] == x:
        return med

    if L[med] < x:
        return _buscar(L, x, med + 1, e)

    return _buscar(L, x, s, med - 1)