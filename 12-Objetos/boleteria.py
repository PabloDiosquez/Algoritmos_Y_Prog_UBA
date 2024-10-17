# Se pide implementar la clase Boleteria, que recibe en su constructor un evento y la cantidad de localidades para el mismo; de modo tal que cumpla el siguiente comportamiento:

# >>> b = Boleteria("Rush",500)                       
# >>> b.localidades_agotadas()
# False
# >>> print(b)                                        
# Evento: Rush - Localidades vendidas: 0 de 500       
# >>> b.vender_localidades(100)
# >>> b.vender_localidades(400)                       
# >>> b.localidades_agotadas()
# True
# >>> print(b)
# Evento: Rush - Localidades vendidas: 500 de 500
# >>> b.vender_localidades(200)                       
# Traceback (most recent call last):                  
# ...                                                 
# ValueError: No hay localidades suficientes