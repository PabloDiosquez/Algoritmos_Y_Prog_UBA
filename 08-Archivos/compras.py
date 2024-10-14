# Escribir una función que dada una lista de compras en un diccionario de la forma código:cantidad y una ruta a un archivo donde se encuentra la lista de precios en formato csv: código,nombre,precio,descripción, imprima un listado por pantalla de la forma <Nombre Producto> x <cantidad>: <precio total> (Precio unidad: <precio unitario>) de aquellos productos comprados.

# Nota: No se puede cargar todo el archivo en memoria ni leerlo más de una vez.

def imprimir_listado_compras(lista_compras: dict, ruta_archivo_precios: str):
    """
    Imprime un listado de los productos comprados a partir de una lista de compras y un archivo CSV con la información de precios.

    Parámetros:
        - lista_compras (dict): Diccionario que contiene los códigos de los productos como claves y las cantidades compradas como valores.
        - ruta_archivo_precios (str): Ruta al archivo CSV que contiene los datos de los productos en el formato "código, nombre, precio, descripción".

    Precondiciones:
        - El archivo CSV tiene el formato adecuado: "código, nombre, precio, descripción".
        - El archivo no se cargará completamente en memoria, se leerá línea por línea.
    """
    precios_productos = leer_precios_productos(ruta_archivo_precios)
    for codigo, cantidad in lista_compras.items():
        if codigo in precios_productos:
            nombre, precio_unitario, _ = precios_productos[codigo]
            precio_total = cantidad * precio_unitario
            print(f"{nombre} x {cantidad}: ${precio_total:.2f} (Precio unidad: ${precio_unitario:.2f})")
        else:
            print(f"Producto con código {codigo} no encontrado en la lista de precios.")


def leer_precios_productos(ruta_archivo_precios: str):
    """
    Lee un archivo CSV con información de precios de productos y devuelve un diccionario con los datos.
    Precondiciones:
        - Cada código de producto en el archivo es único.
    """
    precios = {}
    try:
        with open(ruta_archivo_precios, 'r') as archivo:
            for linea in archivo:
                campos = linea.strip().split(',')
                if len(campos) == 4:
                    codigo, nombre, precio, descripcion = campos
                    try:
                        precio_unitario = float(precio)
                        precios[codigo] = [nombre, precio_unitario, descripcion]
                    except ValueError:
                        print(f"Error de conversión de precio para el código {codigo}.")
    except FileNotFoundError:
        raise FileNotFoundError(f"No se encontró el archivo: {ruta_archivo_precios}")
    except IOError as e:
        raise IOError(f"Ocurrió un error de entrada/salida: {e}")
    
    return precios