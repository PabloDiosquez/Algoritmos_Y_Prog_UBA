# Escribir un programa que abra un archivo separado por comas y le pida al usuario dos números.
#  El programa debe escribir en otro archivo el contenido del primero con las columnas del archivo
#  CSV intercambiadas según los números del usuario. Por ejemplo, si una línea del archivo es
#  "lunes, martes, miércoles, jueves" y los números del usuario son 1 y 3, el archivo de destino
#  será "miércoles, martes, lunes, jueves" (las columnas 1 y 3 están intercambiadas).

def intercambiar(ruta_origen, ruta_destino, col1, col2):
    """
    Intercambia las columnas especificadas en cada línea de un archivo CSV y escribe el resultado en otro archivo.
    """
    
    with open(ruta_origen, 'r') as origen, open(ruta_destino, 'w') as destino:
        for linea in origen:
            linea = linea.strip()
            campos = linea.split(',')
            swap(campos, col1, col2)
            destino.write(','.join(campos) + '\n')

def swap(lista, col1, col2):
    """
    Intercambia dos elementos en la lista basándose en los índices de las columnas.
    """
    lista[col1 - 1], lista[col2 - 1] = lista[col2 - 1], lista[col1 - 1]

def main():
    """
    Función principal que solicita al usuario las rutas de los archivos de origen y destino, 
    así como los números de las columnas que desea intercambiar. Luego, llama a la función
    'intercambiar' para realizar el proceso.
    """
    ruta_origen = input('Ingrese ruta de origen: ')
    ruta_destino = input('Ingrese ruta de destino: ')
    
    try:
        columna1 = int(input('Ingrese la primera columna: '))
        columna2 = int(input('Ingrese la segunda columna: '))
        intercambiar(ruta_origen, ruta_destino, columna1, columna2)
        print(f"El archivo se ha procesado correctamente y se ha guardado en '{ruta_destino}'.")
    except ValueError:
        print("Error: Las columnas deben ser números enteros.")

if __name__ == "__main__":
    main()