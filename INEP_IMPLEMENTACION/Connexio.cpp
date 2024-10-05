// Connexio.cpp
#include "Connexio.h"
#include "ReadConnection.h"
#include <iostream>
using namespace std;
Connexio::Connexio(const std::string& path) {
    configFilePath = path;
    try {
        conn = pqxx::connection(ReadConnectionString(configFilePath));
    }
    catch (const std::exception& e) {
        cerr << "Error en obrir la connexió: " << e.what() << std::endl;
    }
}

pqxx::connection& Connexio::ObtenirConnexio() {
    return conn;
}
