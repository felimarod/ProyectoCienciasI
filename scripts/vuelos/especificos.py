""" Script para generar vuelos especificos """
# import random as ran
import datetime as date

# x = date.datetime.now()
# while int(x.strftime("%Y")) < 2024:
    # print(x.strftime("%d,%m,%Y")) # Devuelve día mes y año con ese formato
    # x = x + date.timedelta(days=7)
# print(x.strftime("%j"))

RUTA_ARCHIVOS = "../../src/persistencia/archivos/"
planeados = []
aviones = []

fl = open(RUTA_ARCHIVOS + "vuelos_planeados.txt", "r", encoding="UTF-8")
cabeceras_vuelos = {}
centinelas_vuelos = {}
pos_vuelo = 0
for vuelo in fl:
    info = vuelo.split(";")
    vuelo = {
        "id": int(info[0]),
        "aerolinea": int(info[1]),
        "origen": int(info[2]),
        "destino": int(info[3]),
        "dia": int(info[4]),
        "hora": info[5],
        "duracion": int(info[6]),
        "sig_aero": 0,
    }
    if vuelo["aerolinea"] not in cabeceras_vuelos.keys():
        cabeceras_vuelos[vuelo["aerolinea"]] = pos_vuelo
    else:
        planeados[centinelas_vuelos[vuelo["aerolinea"]]
                  ]["sig_aero"] = pos_vuelo
    centinelas_vuelos[vuelo["aerolinea"]] = pos_vuelo

    planeados.append(vuelo)
    pos_vuelo += 1

fl.close()

# for vuelo in planeados:
    # print(vuelo)

# print(cabeceras)
# print(centinelas)
modelos = []
fl = open(RUTA_ARCHIVOS + "modelos_aviones.txt", "r", encoding="UTF-8")
for tipo_avion in fl:
    info = tipo_avion.split(";")
    tipo_avion = {
        "id": int(info[0]),
        "nombre": info[1],
        "capacidad": int(info[2]),
    }
    modelos.append(tipo_avion)

# for mod in modelos:
    # print(mod)


aviones = []
cabeceras_aviones = {}
centinelas_aviones = {}
pos_avion = 0
fl = open(RUTA_ARCHIVOS + "aviones.txt", "r", encoding="UTF-8")
for avion in fl:
    info = avion.split(";")
    avion = {
        "id": int(info[0]),
        "id_modelo": int(info[1]),
        "aerolinea": int(info[2]),
        "sig_aero": 0,
        "ocupado": False,
    }
    if avion["aerolinea"] not in cabeceras_aviones.keys():
        cabeceras_aviones[avion["aerolinea"]] = pos_avion
    else:
        aviones[centinelas_aviones[avion["aerolinea"]]]["sig_aero"] = pos_avion
    centinelas_aviones[avion["aerolinea"]] = pos_avion
    aviones.append(avion)
    pos_avion += 1
fl.close()

# for avion in aviones:
    # print(avion)

# print(cabeceras)
# print(centinelas)
# RUTA_ARCHIVOS = ""
nf = open(RUTA_ARCHIVOS + "vuelos_especificos.txt", "w", encoding="UTF-8")
id_vuelo_especifico = 1
viajes_por_avion = 0
for aerolinea in range(1, 11):
    pos_avion = cabeceras_aviones[aerolinea]
    avion_asignado = aviones[pos_avion]
    pos_vuelo_planeado = cabeceras_vuelos[aerolinea]
    vuelo_planeado = planeados[pos_vuelo_planeado]
    while True:
        fecha = date.datetime.now()
        print(vuelo_planeado["sig_aero"], end= "\t")
        num_dia = int(fecha.strftime("%u"))
        num_dia = 7 if num_dia == 1 else num_dia - 1
        num_dia_vuelo = vuelo_planeado["dia"]
        if num_dia < num_dia_vuelo:
            fecha = fecha + date.timedelta(days=num_dia_vuelo - num_dia)
        elif num_dia > num_dia_vuelo:
            fecha = fecha - date.timedelta(days=num_dia - num_dia_vuelo)
        while int(fecha.strftime("%Y")) < 2024:
            # print(fecha.strftime("%d,%m,%Y")) # Devuelve día mes y año con ese formato
            fecha = fecha + date.timedelta(days=7)
            vuelo_especifico = {
                "id": id_vuelo_especifico,
                "id_vuelo_planeado": vuelo_planeado["id"],
                "id_avion": avion_asignado["id"],
                #"id_modelo_avion": avion_asignado[""],
                "fecha":fecha.strftime("%m/%d/%Y"),
            }
            nf.write(
                str(vuelo_especifico["id"]) + ";"
                + str(vuelo_especifico["id_vuelo_planeado"]) + ";"
                # + str(vuelo_especifico["id_avion"]) + ";"
                + str(vuelo_especifico["id_avion"]) + ";"
                + str(vuelo_especifico["fecha"]) + "\n"
            )
            id_vuelo_especifico += 1

        viajes_por_avion +=1
        if viajes_por_avion == 2:
            viajes_por_avion = 0
            pos_avion = avion_asignado["sig_aero"]
            # print("hi" + str(pos_avion))
            avion_asignado = aviones[pos_avion]
        if vuelo_planeado["sig_aero"] == 0:
            break
        pos_vuelo_planeado = vuelo_planeado["sig_aero"]
        vuelo_planeado = planeados[pos_vuelo_planeado]

nf.close()
# nf.write("id_vuelo_planeado;id_Aerolinea;origen;destino;dia;hora_salida;duracion;precio_adulto;precio_niño\n")
# for codigo_aerolinea in range(1, 11):
