#include "CapaDePresentacion.h"
#include <iostream>
#include <cstdlib> // Para utilizar el comando del sistema para borrar pantalla
#include "TxIniciSessio.h"

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void CapaPresentacio::ejecutar() {
    bool usuarioLoggeado = false;
    int opcion = 0;

    do {
        if (usuarioLoggeado) {
            OPCION_SALIR = 3;
            mostrarMenuUsuarioLoggeado();
        }
        else {
            OPCION_SALIR = 5;
            mostrarMenuUsuarioNoLoggeado();
        }
        std::cout << "Ingrese su eleccion: ";
        std::cin >> opcion;

        clearScreen(); 

        procesarOpcion(opcion, usuarioLoggeado);

        clearScreen();

    } while (opcion != OPCION_SALIR);
}

void CapaPresentacio::mostrarMenuUsuarioNoLoggeado() {
    std::cout << "Menu Principal (No Loggeado)" << std::endl;
    std::cout << "1. Iniciar sessio" << std::endl;
    std::cout << "2. Registrar usuari" << std::endl;
    std::cout << "3. Salir" << std::endl;
}

void CapaPresentacio::mostrarMenuUsuarioLoggeado() {
    std::cout << "Menu Principal (Loggeado)" << std::endl;
    std::cout << "1. Gestionar usuari" << std::endl;
    std::cout << "2. Gestionar compres" << std::endl;
    std::cout << "3. Consultar" << std::endl;
    std::cout << "4. Tancar Sessio" << std::endl;
    std::cout << "5. Sortir" << std::endl;
}

void CapaPresentacio::procesarOpcion(int opcion, bool& usuarioLoggeado) {
    switch (opcion) {
    case 1:
        if (!usuarioLoggeado) {
            iniciSessio();
        }
        else {
            gestioUsuari();
        }
        break;
    case 2:
        if (!usuarioLoggeado) {
            registrarUsuari();
        }
        else {
            gestioCompres();
        }
        break;
    case 3:
        if (!usuarioLoggeado) {
            // Logica para salir
            usuarioLoggeado = false;
        }
        else {
            consultar();
        }
        break;
    case 4:
        // Logica para salir
        usuarioLoggeado = false;
        break;
    case 5:
        usuarioLoggeado = false;
        break;
        // Agrega mas casos segun tus necesidades
    default:
        std::cout << "Opcion no valida. Intente nuevamente." << std::endl;
    }
}

void CapaPresentacio::iniciSessio() {
    // Logica para iniciar sesion
    // ...
    string sobrenom;
    string contrasenya;
    cout << " * *INICI SESSIO * * " << endl;
    cout << "Sobrenom: " ;
    cin >> sobrenom;
    cout << "Contrasenya: " ;
    cin >> contrasenya;
    TxIniciSessio txIniciSessio = TxIniciSessio::crear(sobrenom, contrasenya);
    txIniciSessio.executar();
    
}

void CapaPresentacio::registrarUsuari() {
    // Logica para registrar usuario
    // ...
    string sobrenom;
    string nomComplert;
    string contrasenya;
    string correu;
    string dateanaiexement;
    cout << "** Registrar usuari **" << endl;
    cout << "Omplir la informacio que es demana ..." << endl;
    cout << "Nom complert: " ;
    cin >> nomComplert;
    cout << "Sobrenom: " ;
    cin >> sobrenom;
    cout << "Contrasenya: ";
    cin >> contrasenya;
    cout << "Correu electronic: " ;
    cin >> correu;
    cout << "Data naixament (DD/MM/AAAA): ";
    cin >> dateanaiexement;

    std::cout << "Funcionalidad Registrar Usuario en desarrollo" << std::endl;
}

void CapaPresentacio::gestioUsuari() {
    // Logica para gestion de usuario
    // ...
    int opcio;
    cout << "**** Gestionar Usuari ****" << endl;
    cout << "1. Consultar usuari" << endl;
    cout << "2. Modificar usuari" << endl;
    cout << "3. Esborrar usuari" << endl;
    cout << "4. Tornar" << endl;
    cout << "Opcio: ";
    cin >> opcio;
    cout << "Funcionalidad Gestion de Usuario en desarrollo" << std::endl;
}

void CapaPresentacio::gestioCompres() {
    // Logica para gestion de compras
    // ...
    int opcio;
    cout << "**** Gestionar Compres ****" << endl;
    cout << "1. Comprar videojocs" << endl;
    cout << "2. Comprar paquet videojoc" << endl;
    cout << "3. Consultar compres" << endl;
    cout << "4. Tornar" << endl;
    cout << "Opcio: ";
    cin >> opcio;
    std::cout << "Funcionalidad Gestion de Compras en desarrollo" << std::endl;
}

void CapaPresentacio::consultar() {
    // Logica para consultas de videojuegos
    // ...
    int opcio;
    cout << "**** Consultar Videojocs ****" << endl;
    cout << "1. Consultar videojocs" << endl;
    cout << "2. Consultar videojocs" << endl;
    cout << "3. Consultar videojocs per edat" << endl;
    cout << "4. Consultar novetats videojocs" << endl;
    cout << "5. Consultar paquet videojoc" << endl;
    cout << "6. Consultar paquets videojoc" << endl;
    cout << "7. Tornar" << endl;
    cout << "Opcio: ";
    cin >> opcio;
    std::cout << "Funcionalidad Gestion de Compras en desarrollo" << std::endl;
}
