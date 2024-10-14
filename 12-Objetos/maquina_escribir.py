# Implementar la clase MaquinaDeEscribir que nos ayude a acumular texto para luego volcarlo en diferentes archivos.

# __init__(ruta_base: str): recibe la ruta del archivo general para usar en el método de la clase persistir().
# escribir(texto: str): agrega la cadena texto al contenido a escribir para la próxima vez que se llame al método de la clase persistir(). Si el texto recibido es vacío, debe lanzar ValueError.
# persistir(): guarda el contenido acumulado por el método escribir en un nuevo archivo.
# El nombre del archivo estará compuesto por la ruta base, el número de archivo que se está persistiendo, y la extensión txt. Por ejemplo, si se creó el objeto de la forma MaquinaDeEscribir("hola_mundo") y ya se llamó a persistir() unas dos veces antes, el nuevo archivo creado se deberá llamar hola_mundo_3.txt
# Para el contenido del archivo, si previamente se llamó a escribir("buenas"), escribir("tardes"), el archivo generado por persistir() deberá contener únicamente "buenastardes". Una vez persistido, se debe eliminar de la máquina de escribir el texto acumulado hasta el momento pues ya se persistió en un archivo.
# Si no hay nada para escribir en el archivo (es decir, no se llamó a escribir() antes de persistir), debe lanzarse ValueError.

class MaquinaDeEscribir:
    def __init__(self, ruta_base: str):
        """
        Inicializa la máquina de escribir con una ruta base para los archivos y 
        variables para el contenido acumulado y el conteo de persistencias.
        
        Parámetros:
        - ruta_base (str): Ruta base del archivo para las persistencias.
        """
        self.ruta_base = ruta_base
        self.contenido = ''
        self.nro_persistencias = 0

    def escribir(self, texto: str):
        """
        Agrega el texto al contenido acumulado.
        
        Parámetros:
        - texto (str): Texto a agregar.
        
        Excepciones:
        - ValueError: Si el texto es vacío.
        """
        if not texto:
            raise ValueError('El texto no puede ser vacío.')
        self.contenido += texto

    def persistir(self):
        """
        Guarda el contenido acumulado en un archivo nuevo y limpia el contenido acumulado.
        
        Excepciones:
        - ValueError: Si no hay contenido para persistir.
        """
        if not self.contenido:
            raise ValueError('No hay contenido para persistir.')
        
        self.nro_persistencias += 1
        nombre_archivo = f'{self.ruta_base}_{self.nro_persistencias}.txt'
        
        with open(nombre_archivo, 'w') as archivo:
            archivo.write(self.contenido)
        
        self.contenido = ''
