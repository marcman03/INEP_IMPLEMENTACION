#include "Videoconsola.h"
#include "PassarellaUsuari.h"

Videoconsola::Videoconsola(){}

void Videoconsola::iniciaSessio(pqxx::result u) {
	passarellaUsuari = PassarellaUsuari(u);

}


void Videoconsola::tancaSessio()
{
	passarellaUsuari = PassarellaUsuari();

}

PassarellaUsuari Videoconsola::obteUsuari()
{
	return passarellaUsuari;
}


