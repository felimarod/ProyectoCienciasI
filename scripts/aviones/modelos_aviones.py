#!/bin/python
""" Script para generar los modelos de los aviones """
CARPETA_ARCHIVOS = "../../archivos/"
# CARPETA_ARCHIVOS = ""
TIPOS_AVIONES = [
    {"nombre": "Boeing 747", "cantidad": 584},
    {"nombre": "Boeing 777", "cantidad": 550},
    {"nombre": "Boeing 737", "cantidad": 130},
    {"nombre": "Boeing 787 Dreamliner", "cantidad": 323},
    {"nombre": "Boeing 757", "cantidad": 289},
    {"nombre": "Boeing 767", "cantidad": 375},
    {"nombre": "Boeing 727", "cantidad": 189},
    {"nombre": "A320", "cantidad": 220},
    {"nombre": "A380", "cantidad": 407}
]

fta = open(CARPETA_ARCHIVOS + "modelos_aviones.txt", "w", encoding="UTF-8")
""" Crear las sillas de ese avión "file sillas tipo avion" """
fsta = open(CARPETA_ARCHIVOS + "sillas.txt", "w", encoding="UTF-8")
id_silla = 1
for i in range(1, len(TIPOS_AVIONES) + 1):
    avion_tipo = TIPOS_AVIONES[i - 1]
    fta.write(
        str(i) + ";" +
        avion_tipo["nombre"] + ";" +
        str(avion_tipo["cantidad"])
        + "\n"
    )
    # Las sillas ubicadas comienzan en 8 dado a los asientos de los pilotos, copilotos y azafatas
    # La columna empieza en 4 dado que las primeras columnas son la ubicación de los encargados del vuelo
    sillas_ubicadas = 8
    columna_actual = 4
    fila_actual = 1

    while sillas_ubicadas < avion_tipo["cantidad"]:
        # Primera Clase
        posicion = ""
        if columna_actual <= 11:
            if fila_actual == 1:
                posicion = "A" + str(columna_actual)
            elif fila_actual == 2:
                posicion = "C" + str(columna_actual)
            elif fila_actual == 3:
                posicion = "D" + str(columna_actual)
            elif fila_actual == 4:
                posicion = "G" + str(columna_actual)
            elif fila_actual == 5:
                posicion = "H" + str(columna_actual)
            elif fila_actual == 6:
                posicion = "K" + str(columna_actual)

            if fila_actual == 6:
                fila_actual = 1
                columna_actual += 1
            else:
                fila_actual += 1
        else:
            if fila_actual == 1:
                posicion = "A" + str(columna_actual)
            elif fila_actual == 2:
                posicion = "B" + str(columna_actual)
            elif fila_actual == 3:
                posicion = "C" + str(columna_actual)
            elif fila_actual == 4:
                posicion = "D" + str(columna_actual)
            elif fila_actual == 5:
                posicion = "E" + str(columna_actual)
            elif fila_actual == 6:
                posicion = "F" + str(columna_actual)
            elif fila_actual == 7:
                posicion = "G" + str(columna_actual)
            elif fila_actual == 8:
                posicion = "H" + str(columna_actual)
            elif fila_actual == 9:
                posicion = "J" + str(columna_actual)
            elif fila_actual == 10:
                posicion = "K" + str(columna_actual)

            if fila_actual == 10:
                columna_actual += 1
                fila_actual = 1
            else:
                fila_actual += 1
        fsta.write(
            str(id_silla) + ";" + # id_silla
            str(i) + ";" + # id_avion_modelo
            posicion + # posicion
            "\n"
        )
        sillas_ubicadas += 1
        id_silla += 1

fta.close()



fsta.close()
