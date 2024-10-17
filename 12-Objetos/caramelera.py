# Implementar la clase Caramelera, que recibe en su constructor la cantidad de caramelos que puede contener, y tiene el siguiente comportamiento:

# >>> c = Caramelera(20)            >>> c.sacar_caramelos(50)
# >>> c.poner_caramelos(10)        Traceback (most recent call last):
# >>> c.sacar_caramelos(4)         ...
# >>> c.caramelos()                ValueError: No quedan tantos caramelos!
# 6                                >>> c.poner_caramelos(50)
# >>> print(c)                     Traceback (most recent call last):
# Caramelera con 6/20 caramelos    ...
#                                     ValueError: No queda lugar para tantos caramelos

class Caramelera:
    """
    Representa una caramelera que almacena caramelos con una capacidad máxima.

    Atributos:
        capacidad_maxima (int): La cantidad máxima de caramelos que puede contener la caramelera.
        cantidad_actual (int): La cantidad actual de caramelos en la caramelera.
    """

    def __init__(self, capacidad_maxima: int) -> None:
        """
        Inicializa la caramelera con la capacidad máxima especificada y sin caramelos.
        """
        if capacidad_maxima <= 0:
            raise ValueError("La capacidad máxima debe ser mayor a cero.")
        self.capacidad_maxima = capacidad_maxima
        self.cantidad_actual = 0

    def __str__(self) -> str:
        """
        Devuelve una representación en cadena de la caramelera, mostrando la cantidad
        actual de caramelos y la capacidad máxima.
        """
        return f'Caramelera con {self.cantidad_actual}/{self.capacidad_maxima} caramelos'

    def poner_caramelos(self, cantidad: int) -> None:
        """
        Agrega caramelos a la caramelera.
        """
        if cantidad < 0:
            raise ValueError("La cantidad de caramelos a agregar debe ser positiva.")
        if self.cantidad_actual + cantidad > self.capacidad_maxima:
            raise ValueError("No queda lugar para tantos caramelos.")
        self.cantidad_actual += cantidad

    def sacar_caramelos(self, cantidad: int) -> None:
        """
        Elimina caramelos de la caramelera.
        """
        if cantidad < 0:
            raise ValueError("La cantidad de caramelos a sacar debe ser positiva.")
        if self.cantidad_actual < cantidad:
            raise ValueError("No quedan tantos caramelos.")
        self.cantidad_actual -= cantidad