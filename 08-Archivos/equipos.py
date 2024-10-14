# Se tiene un archivo CSV de cuatro columnas con formato equipo,jugador,fecha,goles. Se pide implementar una función que reciba el nombre del archivo como parámetro y devuelva un diccionario con los goles por jugador por equipo. Por ejemplo: { equipo1: { jugador1: 3, jugador2: 1 }, equipo2: { ... } ... }

# Nota: al finalizar la ejecución de la función (haya ocurrido un error o no), todos los archivos abiertos deben quedar cerrados

def goles_por_jugador(ruta_equipos: str) -> dict:
    """
    Lee un archivo CSV y devuelve un diccionario con los goles por jugador de cada equipo.

    El archivo debe tener el formato: equipo,jugador,fecha,goles. La función procesará cada línea,
    acumulando los goles de cada jugador en su respectivo equipo. 
    """
    equipos = {}
    try:
        with open(ruta_equipos, 'r') as entrada:
            for linea in entrada:
                equipo, jugador, _, goles = linea.strip().split(',')
                actualizar_equipos(equipos, equipo, jugador, int(goles))
    
    except FileNotFoundError:
        raise(f"El archivo {ruta_equipos} no fue encontrado.")
    
    except ValueError:
        raise ValueError("Error al procesar el archivo. Asegúrese de que el formato es correcto.")
    
    return equipos


def actualizar_equipos(equipos: dict, equipo: str, jugador: str, goles: int) -> None:
    """
    Actualiza el diccionario de equipos con los goles del jugador.

    Si el equipo no existe en el diccionario, se agrega.
    Luego, se actualiza la cantidad de goles del jugador, sumándolos al valor existente si ya estaba en el diccionario.
    """
    if equipo not in equipos:
        equipos[equipo] = {}
    equipos[equipo][jugador] = equipos[equipo].get(jugador, 0) + goles
    