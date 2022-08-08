#!/bin/python
LUGARES = [
    "Ras al-Jaima, Emiratos Árabes Unidos",
    "Park City, Utah, Estados Unidos",
    "Islas Galápagos, Ecuador",
    "Dolní Morava, República Checa",
    "Seúl, Corea del Sur",
    "Gran Barrera de Coral, Australia",
    "Doha, Catar",
    "Detroit, Estados Unidos",
    "Kerala, India",
    "El Ártico",
    "Ahmedabad, India",
    "Nairobi, Kenobi",
    "Valencia, España",
    "Queenstown, Nueva Zelanda",
    "Parque Nacional Hwange, Zimbabue",
    "Sitios históricos de la Ruta de la Seda, Uzbekistán",
    "San Pablo, Brasil",
    "Sendero Trans Bután, Bután",
    "Devon, Inglaterra",
    "Bali, Indonesia",
    "Estación Espacial Internacional",
    "Kyūshū, Japón",
    "Rapa Nui, Chile",
    "Salta, Argentina",
    "Portree, Escocia",
    "Tofino, Columbia Británica, Canadá",
    "Borácay, Filipinas",
    "Madeira, Portugal",
    "Franschhoek, Sudáfrica",
    "Miami, Estados Unidos",
    "El Chaltén, Argentina",
    "Bogotá, Colombia",
    "El Alentejo, Portugal",
    "Parque Nacional del Bajo Zambeze, Zambia",
    "Kaunas, Lituania",
    "Islas Setouchi, Japón",
    "Calabria, Italia",
    "San Francisco, Estados Unidos",
    "Skellefteå, Suecia",
    "Copenhague, Dinamarca",
    "Marsella, Francia",
    "Salónica, Grecia",
    "Estambul, Turquía",
    "Ilulissat, Groenlandia",
    "Jamaica",
    "Fremantle, Australia",
    "Toronto, Canadá",
    "Kigali, Ruanda",
    "Riviera Nayarit, México",
    "Portland, Estados Unidos"
]
CARPETA_ARCHIVOS = "../archivos/"
# CARPETA_ARCHIVOS = ""
NOMBRE_DOC = "lugares.txt"

nf = open(CARPETA_ARCHIVOS + NOMBRE_DOC, "w")
for id_lugar in range(1, len(LUGARES)+ 1):
    nf.write(
			str(id_lugar) + ";"
			+ LUGARES[id_lugar - 1] + "\n"
		)
nf.close()
