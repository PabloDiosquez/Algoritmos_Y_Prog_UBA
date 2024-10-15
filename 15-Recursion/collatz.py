# Sea la siguiente operación, aplicable a cualquier número entero positivo:

# Si el número es par, se divide por 2.
# Si el número es impar, se multiplica por 3 y se suma 1.
# La conjetura de Collatz dice que, para cualquier número con el que comencemos, si aplicamos la operación sucesivamente, siempre alcanzaremos el número 1. Escribir la función recursiva collatz(n) que imprime la secuencia de operaciones comenzando desde el número n, y terminando en el número 1. Ejemplo: collatz(5) → 5 16 8 4 2 1

def collatz(n: int):
    """
    Imprime la secuencia de la conjetura de Collatz para un número entero positivo.
    La secuencia de Collatz comienza desde el número dado y aplica las siguientes
    operaciones sucesivamente hasta llegar al número 1:
    - Si el número es par, se divide por 2.
    - Si el número es impar, se multiplica por 3 y se suma 1.
    """
    if n == 1:
        print(n)
        return
    print(n)
    if n % 2 == 0:
        collatz(n // 2)
    else:
        collatz(3 * n + 1)

def len_secuencia_collatz(n: int) -> int:
    """
    Calcula la longitud de la secuencia de Collatz para un número entero positivo.
    La longitud se determina aplicando la operación de Collatz repetidamente hasta
    llegar al número 1.
    """
    if n == 1:
        return 1
    if n % 2 == 0:
        return 1 + len_secuencia_collatz(n // 2)
    return 1 + len_secuencia_collatz(3 * n + 1)
