#include "LectorArchivo.cpp"
#include <string>

class LectorUsuarios : public LectorArchivo<Usuario> {
protected:
  Usuario *pasarDatos(Cola<string> *rawCola) const override {
    Usuario *datos;
    datos = new Usuario[rawCola->getTam()];
    string linea = "";
    Cola<string> *datos_separados;

    int pos = 0;
    // parsear el registro del archivo a un objeto usuario
    while (!rawCola->isEmpty()) {
      //Usuario *u = new Usuario;
      linea = rawCola->desencolar();
      // std::cout << linea << "Este es&&&&&" << endl;
      datos_separados = split(linea);
      if (datos_separados->colaVacia())
        cout << "La cola esta vacia \n";
      else {
        cout << "wenas\n"
             << stoi(datos_separados->desencolar()) << " "
             << datos_separados->desencolar() << " "
             << stoi(datos_separados->desencolar()) << " "
             << datos_separados->desencolar() << endl;
      }

      datos[pos].idUsuario = stoi(datos_separados->desencolar());
      // u->nombre = datos_separados->desencolar();
      // u->numeroDocumento = stoi(datos_separados->desencolar());
      // u->sexo = datos_separados->desencolar();
      // datos[pos++] = *u;
      // cout << datos[pos - 1].idUsuario << endl;
    }
    return datos;
  }
};