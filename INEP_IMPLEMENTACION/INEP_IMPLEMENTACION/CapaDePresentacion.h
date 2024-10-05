#pragma once

class CapaPresentacio {
public:
    void ejecutar();

private:
    
    void mostrarMenuUsuarioNoLoggeado();
    void mostrarMenuUsuarioLoggeado();
    void procesarOpcion(int opcion);
    void iniciSessio();
    void registrarUsuari();
    void gestionarUsuari();
    void gestionarCompres();
    void consultar();
    void tancaSessio();
    void consultarUsuari();
    void modificarUsuari();
    void esborrarUsuari();

    int OPCION_SALIR = 3;
    bool usuarioLoggeado = false;
};
