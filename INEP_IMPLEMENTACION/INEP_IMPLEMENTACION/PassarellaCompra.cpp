#include "PassarellaCompra.h"

// Implementación del constructor
PassarellaCompra::PassarellaCompra(const std::string& usuari, const std::string& elementComprat, const std::string& data, float preuPagat)
    : usuari_(usuari), elementComprat_(elementComprat), data_(data), preuPagat_(preuPagat) {
    // Puedes realizar alguna lógica adicional aquí si es necesario
}

// Implementación de los getters
float PassarellaCompra::obtePreuPagat() const {
    return preuPagat_;
}

std::string PassarellaCompra::obteElementCompra() const {
    return elementComprat_;
}

std::string PassarellaCompra::obteUsuari() const {
    return usuari_;
}

std::string PassarellaCompra::obteData() const {
    return data_;
}
