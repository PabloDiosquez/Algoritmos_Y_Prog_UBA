# 1. Alan, Bárbara y Grace juegan al ping-pong. El que gana un partido sigue jugando, mientras que el que lo pierde es reemplazado por el que no jugaba. El primer partido es entre Alan y Barbara. Se gana una cerveza el primero que gana tres partidos seguidos. Implementar una función recursiva que simule este juego y devuelva quien ganó. Suponer que la probabilidad de ganar un partido es igual para ambos.

# Nota: para simular el resultado de cada parido en forma aleaoria, utilizar la función random.choice

import random

def ping_pong(jugador1: str, jugador2: str, fuera: str, ganador_prev: str = None, partidos_ganados: int = 0) -> str:
    """
    Simula el juego de ping-pong recursivamente y devuelve el nombre del jugador que ganó tres partidos seguidos.
    """
    ganador = random.choice([jugador1, jugador2])

    if ganador == ganador_prev:
        partidos_ganados += 1
    else:
        partidos_ganados = 1 

    if partidos_ganados == 3:
        return ganador
   
    perdedor = jugador1 if ganador == jugador2 else jugador2
    return ping_pong(ganador, fuera, perdedor, ganador, partidos_ganados)