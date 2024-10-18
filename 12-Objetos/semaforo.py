# Se pide implementar una clase Semáforo con tres luces (roja, amarilla y verde) 
# y el siguiente comportamiento:

# Al instanciar la clase se debe ver la luz roja encendida.

# Debe tener un método siguiente para apagar la luz actual y encender la siguiente
# (el orden de encendido de las luces es roja -> amarilla -> verde -> roja -> amarilla -> ...).

# Debe tener un método apagar que apague el semáforo. En un semáforo apagado, todas las luces
# están apagadas y no se puede encender ninguna. Si se intenta usar el método siguiente 
# mientras el semáforo está apagado, se debe lanzar una excepción del tipo ValueError.

# Debe tener un método encender que encienda el semáforo. Al encender el semáforo, el estado
# de las luces debe ser el mismo que tenía antes de apagarlo.

# Al imprimir una instancia de la clase Semáforo, debe mostrar qué luz está encendida.
# Si el semáforo está apagado, debe mostrar que está apagado.

# La representación interna de la clase es a criterio, pero debe ser acorde al comportamiento
# y no agregar complejidad.

class Semaforo:
    """
    La clase Semaforo simula un semáforo con tres luces: roja, amarilla y verde.
    
    Atributos:
        luces (list): Lista de colores de las luces en orden de encendido.
        luz_actual (int): Índice de la luz actualmente encendida en la lista.
        esta_encendido (bool): Estado del semáforo, True si está encendido, False si está apagado.
    """
    
    def __init__(self):
        """
        Inicializa un nuevo objeto Semaforo con la luz roja encendida.
        """
        self.luces = ['Rojo', 'Amarillo', 'Verde']
        self.luz_actual = 0
        self.esta_encendido = True

    def __str__(self):
        """
        Devuelve una representación en cadena del estado actual del semáforo.
        
        Returns:
            str: El color de la luz actualmente encendida, o 'Semáforo apagado' si está apagado.
        """
        if not self.esta_encendido:
            return 'Semáforo apagado'
        return self.luces[self.luz_actual]

    def encender(self):
        """
        Enciende el semáforo, manteniendo el estado previo de la luz que estaba encendida.
        """
        self.esta_encendido = True

    def apagar(self):
        """
        Apaga el semáforo, haciendo que todas las luces estén apagadas.
        """
        self.esta_encendido = False

    def siguiente(self):
        """
        Cambia a la siguiente luz en el orden de encendido.
        
        El orden de las luces es: roja -> amarilla -> verde -> roja ...
        
        Excepciones:
            - Lanza un ValueError si el semáforo está apagado.
        """
        if not self.esta_encendido:
            raise ValueError('El semáforo está apagado')
        self.luz_actual = (self.luz_actual + 1) % 3