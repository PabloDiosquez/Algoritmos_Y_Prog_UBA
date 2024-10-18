# Implementar la siguiente clase Reactor. Las excepciones del ejemplo corresponden a una excepción
#  en la ejecución. El combustible solo se puede agregar con al menos 50% de refrigeración, y al 
# agregar combustible se reduce la refrigeración un 25%.

# >>> reactor = Reactor()                                >>> print(reactor)
# >>> print(reactor)                                     Reactor (refrigeración = 75%, combustible = 1/3)
# Reactor (refrigeración = 0%, combustible = 0/3)        >>> reactor.agregar_combustible()
# >>> reactor.agregar_combustible()                      >>> reactor.controlar_refrigeracion(100)
# Exception: No hay al menos 50% de refrigeración        >>> reactor.agregar_combustible()
# >>> reactor.controlar_refrigeracion(100)                 >>> reactor.agregar_combustible()
# >>> print(reactor)                                     Exception: El reactor ya está lleno!
# Reactor (refrigeración = 100%, combustible = 0/3)      >>> reactor.controlar_refrgeracion(1989)
# >>> reactor.agregar_combustible()                      Exception: El control va entre 0 y 100

class Reactor:
    """
    La clase Reactor simula un reactor nuclear con control de refrigeración y niveles de combustible.
    
    Atributos:
        refrigeracion (int): Nivel actual de refrigeración del reactor (0-100%).
        combustible (int): Cantidad de combustible en el reactor (0-3 unidades).
    """
    
    def __init__(self):
        """
        Inicializa un nuevo objeto Reactor con 0% de refrigeración y 0 unidades de combustible.
        """
        self.refrigeracion = 0
        self.combustible = 0

    def __str__(self):
        """
        Devuelve una representación en cadena del estado actual del reactor.
        
        Returns:
            str: Representación del reactor con el nivel de refrigeración y combustible.
        """
        return f'Reactor (refrigeración = {self.refrigeracion}%, combustible = {self.combustible}/3)'

    def agregar_combustible(self):
        """
        Agrega una unidad de combustible al reactor si las condiciones lo permiten.
        
        Condiciones:
            - La refrigeración debe ser al menos del 50%.
            - El reactor no debe estar lleno (máximo 3 unidades de combustible).
            
        Excepciones:
            - Lanza una excepción si la refrigeración es inferior al 50%.
            - Lanza una excepción si el reactor ya está lleno.
        """
        if self.refrigeracion < 50:
            raise Exception('No hay al menos 50% de refrigeración')

        if self.combustible == 3:
            raise Exception('El reactor ya está lleno!')

        self.combustible += 1
        self.refrigeracion -= 25

    def controlar_refrigeracion(self, refrigeracion):
        """
        Ajusta el nivel de refrigeración del reactor.
        
        Parámetros:
            refrigeracion (int): Nuevo nivel de refrigeración (0-100%).
        
        Excepciones:
            - Lanza una excepción si el nivel de refrigeración no está en el rango 0-100%.
        """
        if not 0 <= refrigeracion <= 100:
            raise Exception('El control va entre 0 y 100')

        self.refrigeracion = refrigeracion