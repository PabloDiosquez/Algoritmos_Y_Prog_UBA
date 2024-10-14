# Se cuenta con un archivo binario que contiene el registro de las entradas y las salidas del edificio para un día en particular. La información que se guarda en cada registro es la siguiente:

# El evento, 'ENT' si es entrada o 'SAL' si es salida.
# El DNI de la persona, representado como un entero sin signo de 4 bytes.
# El tiempo en segundos en el que ocurrió el evento (desde que abrió la facultad a las 7am), representado como un entero sin signo de 4 bytes.
# Como la información fue capturada por los molinetes se sabe que los registros están ordenados por tiempo.

# Escribir una función que, dada la ruta del archivo binario y un DNI de una persona, devuelva por cuánto tiempo en segundos estuvo dicha persona dentro de la facultad. Considerar el caso que dicha persona entre más de una vez a la facultad. Se puede asumir que si hay un registro de entrada, va a existir su registro de salida.

# Ayuda: el formato del módulo struct para enteros sin signo es 'I', y para secuencias de caracteres es 's'.

import struct

# Formato para la estructura de cada registro en el archivo binario:
# "<3sII" significa:
# - '3s': Cadena de 3 bytes para el evento ('ENT' o 'SAL').
# - 'I': Entero sin signo de 4 bytes para el DNI.
# - 'I': Entero sin signo de 4 bytes para el tiempo en segundos.
FORMATO = "<3sII"

def contar_tiempo(ruta_archivo: str, dni_buscado: int) -> int:
    """
    Calcula el tiempo total en segundos que una persona estuvo dentro de la facultad
    en un día, dado su DNI. Considera que los registros están ordenados cronológicamente
    y que siempre hay un registro de salida correspondiente para cada entrada.

    Args:
        ruta_archivo (str): La ruta del archivo binario que contiene los registros.
        dni_buscado (int): El DNI de la persona cuyo tiempo de permanencia se desea calcular.

    Returns:
        int: El tiempo total en segundos que la persona estuvo dentro de la facultad.
    """
    # Abre el archivo en modo de lectura binaria.
    with open(ruta_archivo, 'rb') as entrada:
        tiempo_total = 0  # Acumulador para el tiempo total dentro de la facultad.
        ultima_entrada = 0  # Almacena el tiempo del último evento de entrada.

        # Itera sobre el archivo leyendo cada registro hasta el final.
        while True:
            # Lee el tamaño de un registro según el formato especificado.
            datos = entrada.read(struct.calcsize(FORMATO))

            # Si no hay más datos, se sale del bucle.
            if not datos:
                break

            # Desempaqueta los datos leídos según el formato.
            accion, dni, tiempo = struct.unpack(FORMATO, datos)

            # Si el DNI no coincide con el buscado, continúa con el siguiente registro.
            if dni != dni_buscado:
                continue

            # Decodifica la acción (entrada o salida).
            accion = accion.decode()

            if accion == 'ENT':
                # Si es una entrada, guarda el tiempo para calcular luego.
                ultima_entrada = tiempo
            elif accion == 'SAL':
                # Si es una salida, calcula el tiempo transcurrido desde la última entrada.
                tiempo_total += tiempo - ultima_entrada

    # Devuelve el tiempo total calculado.
    return tiempo_total

def ingresar_registros(ruta_archivo: str, registros: list):
    """
    Escribe una lista de registros de eventos en un archivo binario.

    Args:
        ruta_archivo (str): La ruta del archivo binario donde se guardarán los registros.
        registros (list): Una lista de tuplas que representan los eventos, donde cada 
                          tupla es de la forma (accion, dni, tiempo), siendo:
                          - accion (str): 'ENT' o 'SAL', representando entrada o salida.
                          - dni (int): DNI de la persona.
                          - tiempo (int): Tiempo en segundos desde las 7am en que ocurrió el evento.

    Raises:
        ValueError: Si la acción no es 'ENT' o 'SAL'.
    """
    # Abre el archivo en modo de escritura binaria.
    with open(ruta_archivo, 'wb') as archivo:
        for accion, dni, tiempo in registros:
            # Valida que la acción sea 'ENT' o 'SAL'.
            if accion not in ('ENT', 'SAL'):
                raise ValueError("La acción debe ser 'ENT' o 'SAL'.")

            # Empaqueta los datos según el formato y los escribe en el archivo.
            datos = struct.pack(FORMATO, accion.encode(), dni, tiempo)
            archivo.write(datos)
