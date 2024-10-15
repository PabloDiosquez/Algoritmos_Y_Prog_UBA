# Realizar una función recursiva que elimine los números pares de una lista de Python que contiene únicamente números.

def eliminar_pares(L: list):
    """
    Elimina los números pares de una lista.

    """
    eliminar_pares_desde(L, 0)

def eliminar_pares_hasta(L: list, e: int):
    """
    Recorre la lista desde el índice 'e' hasta el inicio, eliminando los elementos pares.
    """
    if e == -1:
        return
    if not L[e] % 2:
        L.pop(e)
    eliminar_pares_hasta(L, e - 1)

def eliminar_pares_desde(L: list, s: int):
    """
    Elimina los números pares de una lista, comenzando desde el inicio.
    """
    if s == len(L):
        return
    if not L[s] % 2:
        L.pop(s)
        eliminar_pares_desde(L, s)  
    else:
        eliminar_pares_desde(L, s + 1)
