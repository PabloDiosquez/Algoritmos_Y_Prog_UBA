# Realizar una función recursiva en Python que reciba un número entero y devuelva el producto de sus dígitos. Ejemplo: producto_digital(356) → 90.

def prod_digital(n: int) -> int:
    '''
    Recibe un número entero y devuelve el producto de sus dígitos. 
    '''
    if n <= 9:
        return n
    return prod_digital(n // 10) * (n % 10)