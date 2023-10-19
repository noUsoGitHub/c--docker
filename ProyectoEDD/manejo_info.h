#ifndef MANEJO_INFO_H
#define MANEJO_INFO_H

#include "Risk.h"
#include "Jugador.h"
#include "Pais.h"
#include "Tablero.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Inicializa el juego Risk con un objeto Risk dado.
void inicializar(Risk& Risk);

// Realiza un turno para el jugador con el ID proporcionado en el objeto Risk dado.
void turno(const std::string& JugadorId, Risk& Risk);

// Función para salir o finalizar el juego.
void salir();

#endif // MANEJO_INFO_H

