// Connexio.h
#pragma once

#include <pqxx/pqxx>

class Connexio {
public:
    Connexio(const std::string& configFilePath);

    pqxx::connection& ObtenirConnexio();

private:
    pqxx::connection conn;
    std::string configFilePath;
};
