
class Botella:
    """
    Representa una botella con una capacidad máxima, una etiqueta y su estado actual 
    de contenido y tapado/destapado.

    Atributos:
        capacidad (int): La capacidad máxima de la botella en centímetros cúbicos (cc).
        etiqueta (str): La etiqueta que identifica la botella.
        esta_tapada (bool): Indica si la botella está tapada o no.
        cantidad_de_liquido (int): La cantidad actual de líquido en la botella en cc.
    """

    def __init__(self, capacidad: int, etiqueta: str):
        """
        Inicializa una nueva instancia de la clase Botella.

        Args:
            capacidad (int): La capacidad máxima de la botella en cc.
            etiqueta (str): La etiqueta que identifica la botella.

        Raises:
            ValueError: Si la capacidad es negativa o cero.
        """
        if capacidad <= 0:
            raise ValueError('La capacidad debe ser un valor positivo mayor que cero.')

        self.capacidad = capacidad
        self.etiqueta = etiqueta
        self.esta_tapada = True
        self.cantidad_de_liquido = 0

    def __str__(self) -> str:
        """
        Retorna una representación en forma de cadena de la botella.

        Returns:
            str: La representación de la botella, incluyendo la etiqueta, la cantidad 
            actual de líquido y si está tapada o destapada.
        """
        estado = 'Tapada' if self.esta_tapada else 'Destapada'
        return f'{self.etiqueta}: {self.cantidad_de_liquido}/{self.capacidad}cc - {estado}'

    def esta_vacia(self) -> bool:
        """
        Verifica si la botella está vacía.

        Returns:
            bool: True si la botella está vacía, False en caso contrario.
        """
        return self.cantidad_de_liquido == 0

    def destapar(self):
        """
        Destapa la botella.

        Raises:
            ValueError: Si la botella ya está destapada.
        """
        if not self.esta_tapada:
            raise ValueError('La botella ya está destapada.')
        self.esta_tapada = False

    def tapar(self):
        """
        Tapa la botella.

        Raises:
            ValueError: Si la botella ya está tapada.
        """
        if self.esta_tapada:
            raise ValueError('La botella ya está tapada.')
        self.esta_tapada = True

    def cargar(self, cantidad: int):
        """
        Carga una cantidad de líquido en la botella.

        Args:
            cantidad (int): La cantidad de líquido a agregar en cc.

        Raises:
            ValueError: Si la botella está tapada o si la cantidad supera la capacidad disponible.
        """
        if self.esta_tapada:
            raise ValueError('La botella está tapada.')

        if cantidad <= 0:
            raise ValueError('La cantidad a cargar debe ser un valor positivo.')

        if self.cantidad_de_liquido + cantidad > self.capacidad:
            raise ValueError('No cuenta con capacidad suficiente.')

        self.cantidad_de_liquido += cantidad

    def servir(self, cantidad: int):
        """
        Sirve una cantidad de líquido de la botella.

        Args:
            cantidad (int): La cantidad de líquido a servir en cc.

        Raises:
            ValueError: Si la botella está tapada o si la cantidad a servir supera la cantidad disponible.
        """
        if self.esta_tapada:
            raise ValueError('La botella está tapada.')

        if cantidad <= 0:
            raise ValueError('La cantidad a servir debe ser un valor positivo.')

        if self.cantidad_de_liquido < cantidad:
            raise ValueError('No cuenta con suficiente líquido para servir.')

        self.cantidad_de_liquido -= cantidad