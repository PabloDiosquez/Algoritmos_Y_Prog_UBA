def mayor_producto(a: int, b: int, c: int, d: int) -> int:
    """
    Dado cuatro números, devuelve el mayor producto de dos de ellos.

    Args:
        a (int): Primer número.
        b (int): Segundo número.
        c (int): Tercer número.
        d (int): Cuarto número.

    Returns:
        int: El mayor producto posible entre dos de los números dados.
    """
    # Calculamos todos los posibles productos de dos números
    productos = [
        a * b,
        a * c,
        a * d,
        b * c,
        b * d,
        c * d
    ]
    
    # Devolvemos el mayor producto
    return max(productos)
