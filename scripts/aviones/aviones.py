#!/bin/python
import random as ran


RUTA_ARCHIVOS = "../../archivos/"
tipos_aviones = []
num_modelos = 0
id_avion = 1

f = open(RUTA_ARCHIVOS + "modelos_aviones.txt", "r")
for modelo in f:
    linea = modelo.split(";")
    tipos_aviones.append({"nombre": linea[0], "capacidad": int(linea[1])})
f.close()

num_modelos = len(tipos_aviones)

nf = open(RUTA_ARCHIVOS + "aviones.txt", "w")
# nf.write("id_avion;tipo;capacidad; id_Aerolinea; sig_Aerolinea\n")
for codigo_aerolinea in range(1, 11):
    for num_avion in range(1, 16):
        # id_avion;id_modelo_avion(tipo;capacidad); id_Aerolinea; sig_Aerolinea
        avion = ran.choice(tipos_aviones)
        nf.write(
            str(id_avion) + ";" +
            str(ran.randint(1, num_modelos)) + ";" +
            # avion["nombre"] + ";" +
            # str(avion["capacidad"]) + ";" +
            str(codigo_aerolinea) +
            # ";" + str(0 if num_avion == 15 else id_avion + 1) +
            "\n"
        )
        id_avion += 1
nf.close()
