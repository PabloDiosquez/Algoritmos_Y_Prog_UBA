# 3. Implementar una clase Rectangulo que permita representar un rectángulo en R² dadas sus coordenadas cartesianas (x1, y1, x2, y2). Debe permitir las siguientes operaciones:

# >>> r = Rectangulo(1, 6, 4, 4)
# >>> r.ancho()
# 3
# >>> r.alto()
# 2
# >> print(r)
# "Rectangulo(1, 6, 4, 4)"
# >> q = r.mover(-2, 1)
# >> print(q)
# "Rectangulo(-1, 7, 2, 5)"

class Rectangulo:
    """
    Representa un rectángulo en el plano cartesiano R², definido por dos
    puntos (x1, y1) y (x2, y2).

    Atributos:
        x1 (float): Coordenada x del primer vértice.
        y1 (float): Coordenada y del primer vértice.
        x2 (float): Coordenada x del segundo vértice.
        y2 (float): Coordenada y del segundo vértice.
    """

    def __init__(self, x1: float, y1: float, x2: float, y2: float) -> None:
        """
        Inicializa un rectángulo con las coordenadas de dos vértices opuestos.
        """
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2

    def __str__(self) -> str:
        """
        Devuelve una representación en cadena del rectángulo.
        """
        return f'Rectangulo({self.x1}, {self.y1}, {self.x2}, {self.y2})'

    def ancho(self) -> float:
        """
        Calcula el ancho del rectángulo, que es la distancia horizontal entre los puntos.
        """
        return abs(self.x2 - self.x1)

    def alto(self) -> float:
        """
        Calcula el alto del rectángulo, que es la distancia vertical entre los puntos.
        """
        return abs(self.y2 - self.y1)

    def mover(self, dx: float, dy: float) -> 'Rectangulo':
        """
        Devuelve un nuevo rectángulo trasladado por un desplazamiento dado.
        """
        return Rectangulo(
            self.x1 + dx, self.y1 + dy,
            self.x2 + dx, self.y2 + dy
        )