# Existiendo la clase Persona, que posee el método obtener_hijos() -> List[Persona], se pide implementar una función contar_descendientes(persona: Persona) -> int que cuente cuántos descendientes tiene dicha persona (es decir, hijos + nietos + bisnietos + etc), utilizando recursión.

class Persona:
    def obtener_hijos(self):
        """
        Retorna la lista de hijos de la persona.
        """
        pass  # Implementación para obtener los hijos


def contar_descendientes(persona: Persona) -> int:
    """
    Cuenta el número total de descendientes de la persona dada, incluyendo hijos, 
    nietos, bisnietos, etc., de forma recursiva.
    """
    if not persona.obtener_hijos():
        return 0
    
    total_descendientes = 0
    for hijo in persona.obtener_hijos():
        total_descendientes += 1 + contar_descendientes(hijo)
    
    return total_descendientes