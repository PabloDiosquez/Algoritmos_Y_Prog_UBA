# Implementar una clase Carta, que se crea a partir de un palo y un valor. Las cartas deben poder imprimirse de la forma <valor> de <palo>. Las cartas deben poder compararse entre ellas: Una carta vale menos que otra si al ser del mismo palo su valor es menor, o si al ser de distintos palos el propio es menor que el palo de la otra carta (suponer que ya está implementada una clase Palo, que implementa los métodos __eq__, __lt__ y __str__).

class Palo:
    """
    Representa un palo de una carta en un mazo de cartas.
    """
    def __init__(self):
        pass

    def __eq__(self, otro) -> bool:
        """
        Compara si dos palos son iguales.
        """
        pass

    def __lt__(self, otro) -> bool:
        """
        Compara si este palo es menor que otro.
        """
        pass

    def __str__(self) -> str:
        """
        Devuelve una representación en cadena del palo.
        """
        pass

class Carta:
    """
    Representa una carta con un valor y un palo.

    Atributos:
        palo (Palo): El palo de la carta.
        valor (int): El valor numérico de la carta.
    """

    def __init__(self, palo: Palo, valor: int) -> None:
        """
        Inicializa una carta con un palo y un valor.
        """
        if not (1 <= valor <= 13):
            raise ValueError("El valor de la carta debe estar entre 1 y 13.")
        
        self.palo = palo
        self.valor = valor

    def __str__(self) -> str:
        """
        Devuelve una representación en cadena de la carta en la forma "<valor> de <palo>".
        """
        return f'{self.valor} de {self.palo}'

    def __lt__(self, otra: 'Carta') -> bool:
        """
        Compara si esta carta es menor que otra carta.
        """
        if self.palo == otra.palo:
            return self.valor < otra.valor
        return self.palo < otra.palo