#pragma once

class CapaPresentacio {
public:
    void ejecutar();

private:
    
    void mostrarMenuUsuarioNoLoggeado();
    void mostrarMenuUsuarioLoggeado();
    void procesarOpcion(int opcion, bool& usuarioLoggeado);
    void iniciSessio();
    void registrarUsuari();
    void gestioUsuari();
    void gestioCompres();
    void consultar();

    int OPCION_SALIR = 3;
    
};
