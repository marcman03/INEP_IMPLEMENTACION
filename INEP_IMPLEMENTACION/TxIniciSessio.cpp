#include "TxIniciSessio.h"
#include <iostream>
#include "CercadoraUsuari.h"
#include <iostream>
#include "Connexio.h"
using namespace std;


// Implementaci�n de la funci�n est�tica crear
TxIniciSessio TxIniciSessio::crear(const std::string& sobrenom, const std::string& contrasenya) {
    return TxIniciSessio(sobrenom, contrasenya);
}

// Constructor privado
TxIniciSessio::TxIniciSessio(const std::string& sobrenom, const std::string& contrasenya)
    : sobrenom_(sobrenom), contrasenya_(contrasenya) {
    // Puedes realizar alguna l�gica de inicializaci�n aqu� si es necesario
}

// Funci�n para realizar la iniciaci�n de sesi�n
void TxIniciSessio::executar() {

    string configFilePath = "config.txt";
    Connexio instCon = Connexio(configFilePath);
    
}
