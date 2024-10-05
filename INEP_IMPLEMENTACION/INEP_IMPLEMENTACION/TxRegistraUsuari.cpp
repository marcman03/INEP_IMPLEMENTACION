#include "TxRegistraUsuari.h"
#include "PassarellaUsuari.h"

TxRegistraUsuari::TxRegistraUsuari(const std::string& nomComplert, const std::string& sobrenom,
    const std::string& contrasenya, const std::string& correu,
    const std::string& dataNaixement)
    : nomComplertU(nomComplert), sobrenomU(sobrenom), contrasenyaU(contrasenya),
    correuU(correu), dataNaixementU(dataNaixement) {}

TxRegistraUsuari TxRegistraUsuari::crear(const std::string& nomComplert, const std::string& sobrenom,
    const std::string& contrasenya, const std::string& correu,
    const std::string& dataNaixement) {
    return TxRegistraUsuari(nomComplert, sobrenom, contrasenya, correu, dataNaixement);
}

void TxRegistraUsuari::executar() {
    PassarellaUsuari u = PassarellaUsuari::crea(nomComplertU, sobrenomU, contrasenyaU, correuU, dataNaixementU);
    u.insereix();
    
}