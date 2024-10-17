# Debido a los recientes incidentes de público conocimiento, la ALGOBOL se vio obligada a reprogramar el clásico de la programación Argentina. La ALGOBOL tiene una lista de las posibles fechas para reprogramar el encuentro, pero debe garantizar que exista un operativo de seguridad adecuado para prevenir posibles incidentes.

# Dada la función hay_seguridad(fecha) que devuelve True si una fecha tiene suficiente seguridad; y una lista de Python con fechas, se pide: Escribir una función recursiva que elimine todas las fechas posibles donde la seguridad no es suficiente para cubrir el evento.

# Nota: La funcion debe ser in-place (no devolver una nueva lista) y se debe mantener el orden relativo de las fechas.

def hay_seguridad(fecha: str) -> bool:
    """
    Verifica si una fecha tiene suficiente seguridad para cubrir el evento.
    """
    pass  # Implementación de la lógica para verificar la seguridad


def eliminar_fechas_inseguras(fechas: list) -> None:
    """
    Elimina in-place todas las fechas en la lista proporcionada donde la seguridad no es suficiente.

    Modifica la lista original eliminando aquellas fechas que no cumplen con los requisitos de seguridad.
    El orden relativo de las fechas seguras se mantiene.
    """
    _eliminar_fechas_inseguras(fechas, len(fechas) - 1)


def _eliminar_fechas_inseguras(fechas: list, index: int) -> None:
    """
    Función auxiliar recursiva para eliminar las fechas inseguras de la lista.
    """
    if index == -1:
        return

    if not hay_seguridad(fechas[index]):
        fechas.pop(index)

    _eliminar_fechas_inseguras(fechas, index - 1)