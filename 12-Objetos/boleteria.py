# Se pide implementar la clase Boleteria, que recibe en su constructor un evento y la cantidad de localidades para el mismo; de modo tal que cumpla el siguiente comportamiento:

# >>> b = Boleteria("Rush",500)                       
# >>> b.localidades_agotadas()
# False
# >>> print(b)                                        
# Evento: Rush - Localidades vendidas: 0 de 500       
# >>> b.vender_localidades(100)
# >>> b.vender_localidades(400)                       
# >>> b.localidades_agotadas()
# True
# >>> print(b)
# Evento: Rush - Localidades vendidas: 500 de 500
# >>> b.vender_localidades(200)                       
# Traceback (most recent call last):                  
# ...                                                 
# ValueError: No hay localidades suficientes

class Boleteria:
    """
    Representa una boletería para un evento, permitiendo la venta de localidades.

    Atributos:
        evento (str): El nombre del evento.
        total_localidades (int): La cantidad total de localidades disponibles.
        localidades_vendidas (int): La cantidad de localidades vendidas.
    """

    def __init__(self, evento: str, total_localidades: int) -> None:
        """
        Inicializa la boletería con el nombre del evento y la cantidad total de localidades.
        """
        if total_localidades <= 0:
            raise ValueError("El número de localidades debe ser mayor a cero.")
        self.evento = evento
        self.total_localidades = total_localidades
        self.localidades_vendidas = 0

    def __str__(self) -> str:
        """
        Devuelve una representación en cadena de la boletería.
        """
        return f'Evento: {self.evento} - Localidades vendidas: {self.localidades_vendidas} de {self.total_localidades}'

    def localidades_agotadas(self) -> bool:
        """
        Verifica si todas las localidades han sido vendidas.
        """
        return self.localidades_vendidas == self.total_localidades

    def vender_localidades(self, cantidad: int) -> None:
        """
        Vende la cantidad especificada de localidades.
        """
        if cantidad <= 0:
            raise ValueError("La cantidad de localidades a vender debe ser mayor a cero.")
        if self.localidades_vendidas + cantidad > self.total_localidades:
            raise ValueError("No hay localidades suficientes.")
        self.localidades_vendidas += cantidad