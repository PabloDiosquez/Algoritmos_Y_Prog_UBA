def a_segs(h: int, m: int, s: int) -> int:
    """
    Convierte un intervalo de tiempo dado en horas, minutos y segundos a su equivalente en segundos.

    Args:
        h (int): Horas.
        m (int): Minutos.
        s (int): Segundos.

    Returns:
        int: El tiempo total en segundos.
    """
    return 3600 * h + 60 * m + s


def a_hms(segs: int) -> tuple:
    """
    Convierte un intervalo de tiempo dado en segundos a su equivalente en horas, minutos y segundos.

    Args:
        segs (int): Tiempo total en segundos.

    Returns:
        tuple: Una tupla que contiene las horas, minutos y segundos (h, m, s).
    """
    h = segs // 3600
    m = (segs % 3600) // 60
    s = segs % 60  # Corregido para calcular correctamente los segundos restantes
    return h, m, s
