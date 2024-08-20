def vector_diferencia(x1: float, y1: float, z1: float, x2: float, y2: float, z2: float) -> tuple:
    """
    Calcula el vector diferencia entre dos vectores en el espacio tridimensional (R3).

    Args:
        x1 (float): Componente en el eje x del primer vector.
        y1 (float): Componente en el eje y del primer vector.
        z1 (float): Componente en el eje z del primer vector.
        x2 (float): Componente en el eje x del segundo vector.
        y2 (float): Componente en el eje y del segundo vector.
        z2 (float): Componente en el eje z del segundo vector.

    Returns:
        tuple: Una tupla de tres valores flotantes que representan las coordenadas del vector diferencia (x1-x2, y1-y2, z1-z2).

    Ejemplo:
        >>> vector_diferencia(8, 7, -3, 5, 3, 2)
        (3, 4, -5)

    El vector diferencia se calcula restando las correspondientes componentes del segundo vector a las del primero: 
    `(x1 - x2, y1 - y2, z1 - z2)`.
    """
    return x1 - x2, y1 - y2, z1 - z2
