# Se quiere modelar un perchero para colgar ropa. Se pide crear las clases Perchero y Prenda tal 
# que se se puedan ejecutar las siguientes líneas de código y se obtengan los resultados especificados.
# El constructor de Perchero recibe la cantidad de espacio total disponible, y el de Prenda recibe el
# nombre de la prenda y cuánto espacio ocupa:

# >>> p = Perchero(3)
# >>> p.colgar(Prenda('camisa', 1))
# >>> p.colgar(Prenda('pantalon', 1))
# >>> p.sacar('pantalon')
# Prenda('pantalon', 1)
# >>> p.sacar('remera')
# Exception: No se encontró la prenda
# >>> p.espacio_disponible()
# 2
# >>> p.colgar(Prenda('campera', 3))
# Exception: No hay espacio para colgar la prenda

class Prenda:
    """
    La clase Prenda representa una prenda de ropa con un nombre y el espacio que ocupa.
    
    Atributos:
        nombre (str): El nombre de la prenda.
        espacio (int): La cantidad de espacio que ocupa la prenda.
    """
    
    def __init__(self, nombre, espacio):
        """
        Inicializa una nueva instancia de Prenda.
        
        Parámetros:
            nombre (str): El nombre de la prenda.
            espacio (int): La cantidad de espacio que ocupa la prenda.
        """
        self.nombre = nombre
        self.espacio = espacio

    def __str__(self):
        """
        Devuelve una representación en cadena de la prenda.
        
        Returns:
            str: Una cadena que describe la prenda con su nombre y espacio.
        """
        return f'Prenda({self.nombre}, {self.espacio})'


class Perchero:
    """
    La clase Perchero representa un perchero con un espacio total disponible para colgar prendas.
    
    Atributos:
        espacio_total (int): El espacio total disponible en el perchero.
        prendas (list): Lista de prendas actualmente colgadas en el perchero.
    """
    
    def __init__(self, espacio):
        """
        Inicializa una nueva instancia de Perchero con el espacio total especificado.
        
        Parámetros:
            espacio (int): El espacio total disponible en el perchero.
        """
        self.espacio_total = espacio
        self.prendas = []

    def espacio_disponible(self):
        """
        Calcula el espacio restante disponible en el perchero.
        
        Returns:
            int: El espacio disponible en el perchero.
        """
        espacio_ocupado = sum(prenda.espacio for prenda in self.prendas)
        return self.espacio_total - espacio_ocupado

    def colgar(self, prenda):
        """
        Cuelga una prenda en el perchero si hay suficiente espacio disponible.
        
        Parámetros:
            prenda (Prenda): La prenda que se desea colgar.
        
        Excepciones:
            - Lanza una excepción si no hay espacio suficiente para colgar la prenda.
        """
        if self.espacio_disponible() < prenda.espacio:
            raise Exception('No hay espacio para colgar la prenda')
        self.prendas.append(prenda)

    def sacar(self, nombre):
        """
        Retira una prenda del perchero por su nombre.
        
        Parámetros:
            nombre (str): El nombre de la prenda a retirar.
        
        Returns:
            Prenda: La prenda que ha sido retirada.
        
        Excepciones:
            - Lanza una excepción si no se encuentra la prenda en el perchero.
        """
        for indice, prenda in enumerate(self.prendas):
            if prenda.nombre == nombre:
                return self.prendas.pop(indice)
        raise Exception('No se encontró la prenda')        