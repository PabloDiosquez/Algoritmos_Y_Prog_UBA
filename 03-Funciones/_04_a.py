from math import sqrt

def norma_3D(x: float, y: float, z: float) -> float:
    """
    Calcula la norma euclidiana (también conocida como magnitud) de un vector en el espacio 3D.

    Args:
        x (float): Componente en el eje x del vector.
        y (float): Componente en el eje y del vector.
        z (float): Componente en el eje z del vector.

    Returns:
        float: La norma euclidiana del vector en el espacio 3D.

    Ejemplo:
        >>> norma_3D(1, 2, 2)
        3.0

    La norma euclidiana se calcula como la raíz cuadrada de la suma de los cuadrados 
    de las componentes del vector: `sqrt(x^2 + y^2 + z^2)`.
    """
    return _raiz_cuadrada(_cuad(x) + _cuad(y) + _cuad(z))


def _raiz_cuadrada(x: float) -> float:
    """
    Calcula la raíz cuadrada de un número no negativo.

    Args:
        x (float): Número del cual se desea calcular la raíz cuadrada. Debe ser mayor o igual a 0.

    Returns:
        float: La raíz cuadrada de x.

    Raises:
        ValueError: Si x es negativo, se lanzará una excepción.

    Ejemplo:
        >>> _raiz_cuadrada(9)
        3.0
    """
    if x < 0:
        raise ValueError("El argumento debe ser mayor o igual a 0.")
    return sqrt(x)


def _cuad(x: float) -> float:
    """
    Calcula el cuadrado de un número.

    Args:
        x (float): Número que se desea elevar al cuadrado.

    Returns:
        float: El cuadrado de x.

    Ejemplo:
        >>> _cuad(3)
        9.0
    """
    return x * x
