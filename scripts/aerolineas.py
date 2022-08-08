#!/usr/bin/env python
import random as ran

RUTA_ARCHIVOS = "../archivos/"
AEROLINEAS = ["Aeroméxico",
              "LATAM Airlines Group",
              "Avianca",
              "Copa Airlines Colombia",
              "Sky Airline",
              "SATENA",
              "Qatar Airways",
              "Cathay Pacific Airways",
              "Singapore Airlines",
              "Emirates"]

nf = open(RUTA_ARCHIVOS + "aerolineas.txt", "w")
id_vuelo_planeado = 1
# nf.write("id_vuelo_planeado;id_Aerolinea;origen;destino;dia;hora_salida;duracion;precio_adulto;precio_niño\n")
for codigo_aerolinea in range(1, 11):
    nf.write(
        str(codigo_aerolinea) + ";" +
        AEROLINEAS[codigo_aerolinea - 1] + ";" +
        str(ran.randint(1000000000, 9999999999)) + "\n"
    )
