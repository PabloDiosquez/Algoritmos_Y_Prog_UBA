# Escribir una función recursiva para replicar los elementos de una lista una cantidad n de veces. Por ejemplo:
# replicar([1, 3, 3, 7], 2) -> ([1, 1, 3, 3, 3, 3, 7, 7])

def replicar(L: list, n: int) -> list:
    """
    Replica los elementos de una lista una cantidad 'n' de veces de manera recursiva.
    """
    return _replicar(L, n, 0)

def _replicar(L: list, n: int, s: int) -> list:
    """
    Función auxiliar recursiva para replicar los elementos de la lista.

    Recorre la lista desde el índice 's', replicando cada elemento 'n' veces.
    Cuando se alcanza el final de la lista, la recursión se detiene.
    """
    if s == len(L):
        return []  
    return [L[s]] * n + _replicar(L, n, s + 1)
