from _01 import a_hms, a_segs

def calcular_duracion_total():
    """
    Solicita al usuario dos intervalos de tiempo expresados en horas, minutos y segundos,
    suma sus duraciones y muestra el resultado en horas, minutos y segundos.

    El programa pide al usuario que ingrese dos intervalos de tiempo, los convierte a segundos,
    suma los segundos de ambos intervalos, y luego convierte el total de segundos a horas, minutos y segundos.
    Finalmente, muestra el resultado en pantalla.
    """
    
    print('Primer intervalo: ')
    horas_1 = int(input('Ingrese cantidad de horas: '))
    minutos_1 = int(input('Ingrese cantidad de minutos: '))
    segundos_1 = int(input('Ingrese cantidad de segundos: '))
    duracion_1 = a_segs(horas_1, minutos_1, segundos_1)

    print('Segundo intervalo: ')
    horas_2 = int(input('Ingrese cantidad de horas: '))
    minutos_2 = int(input('Ingrese cantidad de minutos: '))
    segundos_2 = int(input('Ingrese cantidad de segundos: '))
    duracion_2 = a_segs(horas_2, minutos_2, segundos_2)

    duracion_total_segs = duracion_1 + duracion_2
    horas_totales, minutos_totales, segundos_totales = a_hms(duracion_total_segs)

    print(f'La duración total es: {horas_totales} horas, {minutos_totales} minutos y {segundos_totales} segundos.')
