// PassarellaUsuari.cpp
#include "PassarellaUsuari.h"
#include "Connexio.h"
#include <iostream>
using namespace std;

// Constructor que toma un resultado de la base de datos
PassarellaUsuari::PassarellaUsuari(const pqxx::result& result) {
    contrasenya_ = result[0]["contrasenya"].as<std::string>();
    sobrenom_ = result[0]["sobrenom"].as<std::string>();
    nom_ = result[0]["nom"].as<std::string>();
    correuElectronic_ = result[0]["correu_electronic"].as<std::string>();
    dataNaixament_ = result[0]["data_naixament"].as<std::string>();
}

// Constructor por defecto
PassarellaUsuari::PassarellaUsuari() {
    // Puedes inicializar los elementos privados aquí si es necesario
}
// Constructor que toma parámetros
PassarellaUsuari::PassarellaUsuari(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixament)
    : nom_(nomU), sobrenom_(sobrenomU), contrasenya_(contrasenyaU), correuElectronic_(correuElectronicU), dataNaixament_(dataNaixament) {
    // Puedes realizar alguna lógica adicional aquí si es necesario
}

PassarellaUsuari PassarellaUsuari::crea(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixament) {
    return PassarellaUsuari(nomU, sobrenomU, contrasenyaU, correuElectronicU, dataNaixament);
}

// Función para obtener la contraseña del usuario
std::string PassarellaUsuari::obteContrasenya() const {
    return contrasenya_;
}

// Función para obtener el sobrenombre del usuario
std::string PassarellaUsuari::obteSobrenom() const {
    return sobrenom_;
}

// Función para obtener el nombre del usuario
std::string PassarellaUsuari::obteNom() const {
    return nom_;
}

// Función para obtener el correo electrónico del usuario
std::string PassarellaUsuari::obteCorreuElectronic() const {
    return correuElectronic_;
}

// Función para obtener la fecha de nacimiento del usuario
std::string PassarellaUsuari::obteDataNaixament() const {
    return dataNaixament_;
}

void PassarellaUsuari::insereix() {
    // Obtén la conexión
    Connexio instCon = Connexio();
    pqxx::work txn(instCon.ObtenirConnexio());

    // Ejecuta la consulta para insertar un nuevo usuario
    std::string query = "INSERT INTO public.usuari (nom, sobrenom, contrasenya, correu_electronic, data_naixament) VALUES ("
        + txn.quote(nom_) + ", "
        + txn.quote(sobrenom_) + ", "
        + txn.quote(contrasenya_) + ", "
        + txn.quote(correuElectronic_) + ", "
        + txn.quote(dataNaixament_) + ")";

    try {
        txn.exec(query);
        txn.commit();
    }
    catch (const exception& e) {
        cerr << "Error al insertar usuario: " << e.what() << endl;
        // También puedes agregar un throw aquí para propagar la excepción
    }
}
