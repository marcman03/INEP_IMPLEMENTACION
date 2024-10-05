#include "CapaDePresentacion.h"
#include <iostream>
#include <cstdlib> 
#include "TxIniciSessio.h"
#include <algorithm>
#include "TxTancaSessio.h"
#include "TxRegistraUsuari.h"
#include "TxConsultaUsuari.h"
#include "TxInfoCompres.h"

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void CapaPresentacio::ejecutar() {
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

        procesarOpcion(opcion);

       

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

void CapaPresentacio::procesarOpcion(int opcion) {
    switch (opcion) {
    case 1:
        if (!usuarioLoggeado) {
            iniciSessio();
        }
        else {
            gestionarUsuari(); 
        }
        break;
    case 2:
        if (!usuarioLoggeado) {
            registrarUsuari();
        }
        else {
            gestionarCompres();
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
        // Logica para tancaSessio;
        tancaSessio();
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
    cout << "Sobrenom: ";
    cin >> sobrenom;
    cout << "Contrasenya: ";
    cin >> contrasenya;
    
    try {

        TxIniciSessio txIniciSessio = TxIniciSessio::crear(sobrenom, contrasenya);
        txIniciSessio.executar();
        usuarioLoggeado = true;
        clearScreen();
        cout << "Sessio Iniciada correctament!" << endl;
        
    }
    catch (const exception& e) {
        clearScreen();
        cerr<<  e.what() << endl;
        
    }

}
void CapaPresentacio::tancaSessio() {
    cout << "Vols tancar la sessio(S/N): ";
    string opcio;
    cin >> opcio;
    clearScreen();
    transform(opcio.begin(), opcio.end(), opcio.begin(), ::tolower);//minusculas la opcio
    if (opcio == "s") {
        
        TxTancaSessio txTancaSessio =TxTancaSessio::crear();
        cout << "Sessio tancada Correctament" << endl;
        usuarioLoggeado = false;
    }

}
void CapaPresentacio::registrarUsuari() {
    // Logica para registrar usuario
    // ...
    string sU;
    string nU;
    string cU;
    string ceU;
    string dnU;
    cout << "** Registrar usuari **" << endl;
    cout << "Omplir la informacio que es demana ..." << endl;
    cout << "Nom complert: ";
    cin >> nU;
    cout << "Sobrenom: ";
    cin >> sU;
    cout << "Contrasenya: ";
    cin >> cU;
    cout << "Correu electronic: ";
    cin >> ceU;
    cout << "Data naixament (DD/MM/AAAA): ";
    cin >> dnU;

   
    TxRegistraUsuari txRu = TxRegistraUsuari::crear(sU,nU,cU,ceU,dnU);
    clearScreen();
    try
    {
        txRu.executar();
        cout << "Nou usuari registrat correctament!!" << endl;
    }
    catch (const std::exception&e)
    {
        cerr <<e.what() << endl;
    }
}

void CapaPresentacio::gestionarUsuari() {
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
    clearScreen();
    switch (opcio) {
    case 1:
        consultarUsuari();
        break;
    case 2:
        modificarUsuari();
        break;
    case 3:
        esborrarUsuari();
        break;
    case 4:
        // No es necesario hacer nada, ya que "Tornar" simplemente termina la función
        break;
    default:
        cout << "Opcio no valida. Intente nuevamente." << endl;
    }

}

void CapaPresentacio::gestionarCompres() {
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
void CapaPresentacio::consultarUsuari() {
    // Lógica para consultar usuario
    // ... b n
    TxConsultaUsuari txconsultausuari = TxConsultaUsuari::crear();
    txconsultausuari.executar();
    TxConsultaUsuari::Resultat infoUsuari = txconsultausuari.obteResultat();
    TxInfoCompres txInfoCompres = TxInfoCompres::crear();
    txInfoCompres.executar();
    TxInfoCompres::Resultat infoCompres = txInfoCompres.obteResultat();
    cout << "**** Informacion del Usuario ****" << endl;
    cout << "Nom: " << infoUsuari.nomComplertU << endl;
    cout << "Sobrenom: " << infoUsuari.sobrenomU << endl;
    cout << "Correu: " << infoUsuari.correuU << endl;
    cout << "Data Naixement: " << infoUsuari.dataNaixementU << endl;

    cout << "**** Informacion de Compras ****" << endl;
    cout << "Total Paquets: " << infoCompres.totalPaquets << endl;
    cout << "Total Videojocs: " << infoCompres.totalVideojocs << endl;
    cout << "Total Euros: " << infoCompres.totalEuros << endl;

    


   
}

void CapaPresentacio::modificarUsuari() {
    // Lógica para modificar usuario
    // ...
    cout << "Funcionalidad Modificar Usuario en desarrollo" << std::endl;
}

void CapaPresentacio::esborrarUsuari() {
    // Lógica para esborrar usuario
    // ...
    cout << "Funcionalidad Esborrar Usuario en desarrollo" << std::endl;
}