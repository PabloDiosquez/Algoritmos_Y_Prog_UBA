# Para desarrollar un videojuego necesitamos que todos los personajes tengan una cantidad de vida entre 0 y 100, y un valor de daño de ataque. Cuando un personaje ataca a otro, se le resta el daño del atacante a su cantidad de vida. Se dice que un personaje está muerto si su cantidad de vida llega a 0.

# Implementar la clase Personaje con los siguientes métodos:

# -El constructor recibe el daño que hace su ataque. La cantidad de vida arranca siendo 100.
# -esta_muerto() que debe informar si el personaje está muerto
# -atacar() que recibe otro personaje. Si alguno de los dos personajes está muerto debe lanzar una excepción. En caso contrario debe atacar al personaje recibido.
# -curar() que recibe una cantidad de vida a regenerar. La vida máxima no se modifica. Si el personaje está muerto, debe lanzar una excepción.

class Personaje:
    """
    Clase que representa un personaje en un videojuego, con vida y capacidad de ataque.
    Atributos de un personaje:
        >> vida (int): La cantidad de vida del personaje, limitada entre 0 y 100.
        >> ataque (int): El daño que el personaje hace al atacar.
    """

    def __init__(self, ataque: int):
        """
        Inicializa un personaje con 100 de vida y un daño de ataque específico.
        """
        self.vida = 100
        self.ataque = ataque

    def esta_muerto(self) -> bool:
        """
        Indica si el personaje está muerto.
        """
        return self.vida == 0

    def atacar(self, otro: 'Personaje'):
        """
        Ataca a otro personaje, reduciendo su vida en función del daño de ataque.
        Si el personaje actual o el otro están muertos, lanza una excepción.
        """
        if self.esta_muerto():
            raise Exception('El personaje está muerto y no puede atacar.')
        if otro.esta_muerto():
            raise Exception('El personaje a atacar ya está muerto.')

        otro.vida -= self.ataque
        if otro.vida < 0:
            otro.vida = 0

    def curar(self, cant_vida: int):
        """
        Cura al personaje, incrementando su vida hasta un máximo de 100.
        Si el personaje está muerto, lanza una excepción.
        """
        if self.esta_muerto():
            raise Exception('El personaje está muerto y no puede ser curado.')

        self.vida += cant_vida
        if self.vida > 100:
            self.vida = 100