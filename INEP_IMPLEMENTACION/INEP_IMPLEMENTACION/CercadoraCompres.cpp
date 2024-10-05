#include "CercadoraCompres.h"
#include "Connexio.h"
CercadoraCompres::CercadoraCompres() {}
pqxx::result CercadoraCompres::cercarCompres(const std::string& sobrenom) {
    Connexio instCon = Connexio();
    pqxx::work txn(instCon.ObtenirConnexio());

    // Ejemplo de consulta SQL (ajusta según tu esquema de base de datos)
    std::string query = "SELECT * FROM public.compra WHERE usuari = " + txn.quote(sobrenom);

    // Ejecuta la consulta
    pqxx::result resultatConsulta = txn.exec(query);

    // Guarda el resultado en un vector


    // Realiza el commit para aplicar los cambios
    txn.commit();

    // Devuelve el vector de resultados
    return resultatConsulta;
}
