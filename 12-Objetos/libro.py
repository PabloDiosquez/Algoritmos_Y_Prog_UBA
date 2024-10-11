class Libro:
    """
    Clase que representa un libro con métodos para obtener el autor y el título del libro.
    """
    def __init__(self, titulo: str, autor: str) -> None:
        """
        Inicializa un libro con un título y un autor.

        Parameters:
        titulo (str): El título del libro.
        autor (str): El autor del libro.
        """
        self._titulo = titulo
        self._autor = autor

    def obtener_autor(self) -> str:
        """
        Devuelve el autor del libro.

        Returns:
        str: El nombre del autor del libro.
        """
        return self._autor

    def obtener_titulo(self) -> str:
        """
        Devuelve el título del libro.

        Returns:
        str: El título del libro.
        """
        return self._titulo


class Biblioteca:
    """
    Clase que representa una biblioteca, permitiendo agregar, sacar y verificar la existencia de libros.
    """
    def __init__(self) -> None:
        """
        Inicializa una biblioteca vacía.
        """
        self.coleccion = []

    def agregar_libro(self, libro: Libro) -> None:
        """
        Agrega un libro a la colección de la biblioteca.

        Parameters:
        libro (Libro): El libro a agregar a la biblioteca.
        """
        self.coleccion.append(libro)

    def sacar_libro(self, titulo: str, autor: str) -> Libro:
        """
        Saca un libro de la biblioteca que coincida con el título y el autor dados. Si no se encuentra,
        levanta una excepción.

        Parameters:
        titulo (str): El título del libro que se quiere sacar.
        autor (str): El autor del libro que se quiere sacar.

        Returns:
        Libro: El libro removido de la biblioteca.

        Raises:
        ValueError: Si no se encuentra un libro que coincida con el título y autor proporcionados.
        """
        for i, libro in enumerate(self.coleccion):
            if libro.obtener_titulo() == titulo and libro.obtener_autor() == autor:
                return self.coleccion.pop(i)
        
        raise ValueError('No hay ningún libro con los datos brindados')

    def contiene_libro(self, titulo: str, autor: str) -> bool:
        """
        Verifica si un libro con el título y autor dados está en la colección de la biblioteca.

        Parameters:
        titulo (str): El título del libro a verificar.
        autor (str): El autor del libro a verificar.

        Returns:
        bool: `True` si el libro está en la colección, `False` en caso contrario.
        """
        for libro in self.coleccion:
            if libro.obtener_titulo() == titulo and libro.obtener_autor() == autor:
                return True
        return False