# Escribir una función recursiva que reciba una lista de enteros y devuelva una nueva donde cada k-ésimo elemento representa el producto entre todos los elementos entre las posiciones 0 y k de la lista original. Por ejemplo, para [3, 4, 2, 1, 0, 6], debe devolverse [3, 12, 24, 24, 0, 0]. El primer elemento queda en 3, el segundo es 3 * 4, el tercero es 3 * 4 * 2, y así sucesivamente.

def producto_acumulado(numeros: list[int]) -> list[int]:
    """
    Calcula una nueva lista donde cada elemento k-ésimo representa el producto acumulado 
    de todos los elementos desde la posición 0 hasta k en la lista original.
    """
    acumulados = []
    _producto_acumulado(numeros, acumulados, len(numeros) - 1)
    return acumulados

def _producto_acumulado(numeros: list[int], acumulados: list[int], indice: int):
    """
    Función auxiliar recursiva que calcula el producto acumulado para cada posición de la lista.
    """
    if indice == -1:
        return

    _producto_acumulado(numeros, acumulados, indice - 1)

    acumulados.append(producto_hasta(numeros, indice))

def producto_hasta(numeros: list[int], indice: int) -> int:
    """
    Calcula el producto de todos los elementos en la lista desde la posición 0 hasta el índice dado.
    """
    if indice == -1:
        return 1

    return producto_hasta(numeros, indice - 1) * numeros[indice]