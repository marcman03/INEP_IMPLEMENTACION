#include "TxIniciSessio.h"
#include <iostream>
#include "CercadoraUsuari.h"
#include <iostream>
#include "Connexio.h"
using namespace std;


// Implementación de la función estática crear
TxIniciSessio TxIniciSessio::crear(const std::string& sobrenom, const std::string& contrasenya) {
    return TxIniciSessio(sobrenom, contrasenya);
}

// Constructor privado
TxIniciSessio::TxIniciSessio(const std::string& sobrenom, const std::string& contrasenya)
    : sobrenom_(sobrenom), contrasenya_(contrasenya) {
    // Puedes realizar alguna lógica de inicialización aquí si es necesario
}

// Función para realizar la iniciación de sesión
void TxIniciSessio::executar() {

    string configFilePath = "config.txt";
    Connexio instCon = Connexio(configFilePath);
    
}
