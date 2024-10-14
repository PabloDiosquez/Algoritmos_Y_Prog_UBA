# Implementar la función merge en forma recursiva. La función recibe dos listas ordenadas y devuelve una lista con los elementos intercalados ordenadamente.

def merge(lista1, lista2):
    """
    Fusiona dos listas ordenadas en una sola lista ordenada de manera recursiva.

    Precondición:
    - Ambas listas deben estar ordenadas de menor a mayor.
    """
    lista_fusionada = []
    _merge_recursivo(lista1, lista2, lista_fusionada, 0, 0)
    return lista_fusionada

def _merge_recursivo(lista1, lista2, lista_fusionada, indice1, indice2):
    """
    Función auxiliar recursiva que fusiona dos listas ordenadas en una sola lista.

    La función compara los elementos en los índices actuales de ambas listas y
    añade el menor de ellos a la lista fusionada. Si una de las listas se agota,
    se añaden los elementos restantes de la otra lista.
    """
    if indice1 == len(lista1):
        lista_fusionada.extend(lista2[indice2:])
        return
    if indice2 == len(lista2):
        lista_fusionada.extend(lista1[indice1:])
        return

    if lista1[indice1] < lista2[indice2]:
        lista_fusionada.append(lista1[indice1])
        _merge_recursivo(lista1, lista2, lista_fusionada, indice1 + 1, indice2)
    else:
        lista_fusionada.append(lista2[indice2])
        _merge_recursivo(lista1, lista2, lista_fusionada, indice1, indice2 + 1)
