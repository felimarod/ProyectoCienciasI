#!/bin/python
""" Script para los vuelos planeados """
import random as ran

# codigos bancarios
# for x in range(12):
# print(ran.randint( 1000000000, 9999999999))

RUTA_ARCHIVOS = "../../archivos/"
# RUTA_ARCHIVOS = ""

fl = open(RUTA_ARCHIVOS + "lugares.txt", "r", encoding="UTF-8")
lugares = []
for lugar in fl:
    lugares.append(lugar)
fl.close()

NUM_LUGARES = len(lugares)

nf = open(RUTA_ARCHIVOS + "vuelos_planeados.txt", "w", encoding="UTF-8")
id_vuelo_planeado = 1
# nf.write("id_vuelo_planeado;id_Aerolinea;origen;destino;dia;hora_salida;duracion;precio_adulto;precio_niño\n")
for codigo_aerolinea in range(1, 11):
    vuelos_semanales = []
    # print("Aerolinea " + str(codigo_aerolinea) + ":")
    for vuelo_semanal in range(1, 8):
        origen = ran.randint(1 + (codigo_aerolinea - 1) * 5, codigo_aerolinea * 5)
        destino = ran.randint(1 + (codigo_aerolinea - 1) * 5, codigo_aerolinea * 5)
        while origen == destino:
            origen = ran.randint(1 + (codigo_aerolinea - 1) * 5, codigo_aerolinea * 5)
            destino = ran.randint(1 + (codigo_aerolinea - 1) * 5, codigo_aerolinea * 5)
        num_dia = ran.randint(1, 7)

        hora_salida = ran.randint(0, 24)
        min_salida = ran.randint(0, 3) * 15

        duracion = ran.randint(1, 10) * 60 + ran.randint(0, 3) * 15

        precio_adulto = ran.randint(75, 300)
        precio_ninio = precio_adulto - ran.randint(20, 50)
        vuelo_planeado_ida = {"origen": origen, "destino": destino, "dia": num_dia}
        vuelo_planeado_vuelta = {
            "origen": destino,
            "destino": origen,
            "dia": (num_dia + 4 if num_dia + 4 <= 7 else num_dia - 3),
        }
        while vuelo_planeado_ida in vuelos_semanales:
            origen = ran.randint(1 + (codigo_aerolinea - 1) * 5, codigo_aerolinea * 5)
            destino = ran.randint(1 + (codigo_aerolinea - 1) * 5, codigo_aerolinea * 5)
            while origen == destino:
                origen = ran.randint(1, NUM_LUGARES)
                destino = ran.randint(1, NUM_LUGARES)
            vuelo_planeado_ida = {"origen": origen, "destino": destino, "dia": num_dia}
            vuelo_planeado_vuelta = {
                "origen": destino,
                "destino": origen,
                "dia": (num_dia + 4 if num_dia + 4 <= 7 else num_dia - 3),
            }

        vuelos_semanales.append(vuelo_planeado_ida)
        vuelos_semanales.append(vuelo_planeado_vuelta)

        # nf.write("id_vuelo_planeado;id_Aerolinea;origen;destino;dia;hora_salida;duracion;precio_adulto;precio_niño\n")
        nf.write(
            str(id_vuelo_planeado) + ";"
            + str(codigo_aerolinea) + ";"
            + str(vuelo_planeado_ida["origen"]) + ";"
            + str(vuelo_planeado_ida["destino"]) + ";"
            + str(vuelo_planeado_ida["dia"]) + ";"
            + str(hora_salida) + ":"
            + str(min_salida) + ";"
            + str(duracion) + ";"
            + str(precio_adulto) + ";"
            + str(precio_ninio) + "\n"
        )
        id_vuelo_planeado += 1
        nf.write(
            str(id_vuelo_planeado) + ";"
            + str(codigo_aerolinea) + ";"
            + str(vuelo_planeado_vuelta["origen"]) + ";"
            + str(vuelo_planeado_vuelta["destino"]) + ";"
            + str(vuelo_planeado_vuelta["dia"]) + ";"
            + str(hora_salida) + ":"
            + str(min_salida) + ";"
            + str(duracion) + ";"
            + str(precio_adulto) + ";"
            + str(precio_ninio) + "\n"
        )
        id_vuelo_planeado += 1

nf.close()
print("Creados en la carpeta: " + RUTA_ARCHIVOS)
