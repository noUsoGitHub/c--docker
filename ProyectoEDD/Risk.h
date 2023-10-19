#ifndef RISK_H
#define RISK_H

#include <vector>
#include "Jugador.h"
#include "Pais.h"
#include "Tablero.h"

class Risk {
public:
    Risk();
    void crear_paises();
    std::vector<Jugador> jugadores;
    std::vector<Pais> paises;
    Tablero* tablero;
};

#endif // RISK_H

