# Escribir la clase NumeroComplejo, cuyo constructor recibe la parte real y la parte imaginaria del número. Implementar los métodos suma y multiplicación; ambos reciben otro NumeroComplejo, y devuelven un nuevo NumeroComplejo que es el resultado de la operación. Además, al usar la funcion print sobre una instancia de esta clase, se debe imprimir al número como a+bi. Realizar los chequeos correspondientes, lanzando excepciones cuando sea necesario.

class NumeroComplejo:
    """
    Representa un número complejo en la forma a + bi, donde 'a' es la parte real
    y 'b' es la parte imaginaria.

    Atributos:
        parte_real (float): La parte real del número complejo.
        parte_imaginaria (float): La parte imaginaria del número complejo.
    """

    def __init__(self, parte_real: float, parte_imaginaria: float) -> None:
        """
        Inicializa un número complejo con las partes real e imaginaria especificadas.
        """
        self.parte_real = parte_real
        self.parte_imaginaria = parte_imaginaria

    def __str__(self) -> str:
        """
        Devuelve una representación en cadena del número complejo en la forma a + bi.
        """
        return f'{self.parte_real} + {self.parte_imaginaria}i'

    def __add__(self, otro: 'NumeroComplejo') -> 'NumeroComplejo':
        """
        Suma este número complejo con otro número complejo.
        """
        return NumeroComplejo(
            self.parte_real + otro.parte_real,
            self.parte_imaginaria + otro.parte_imaginaria
        )

    def __mul__(self, otro: 'NumeroComplejo') -> 'NumeroComplejo':
        """
        Multiplica este número complejo por otro número complejo.
        """
        return NumeroComplejo(
            self.parte_real * otro.parte_real - self.parte_imaginaria * otro.parte_imaginaria,
            self.parte_real * otro.parte_imaginaria + self.parte_imaginaria * otro.parte_real
        )