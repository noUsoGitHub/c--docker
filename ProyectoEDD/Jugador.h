#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Pais.h"

class Jugador {
public:
    // Nombre del jugador.
    std::string nombre;
    
    // Color asociado al jugador.
    std::string color;
    
    // Cantidad de tropas que el jugador posee.
    int tropas;
    
    // Vector que almacena las cartas del jugador.
    std::vector<std::string> cartas;
    
    // Vector de países que pertenecen al jugador.
    std::vector<Pais> paisesj;
    
    // Mueve tropas desde un país origen a un país destino.
    void mover_tropas(Pais pais1, Pais pais2);
};

#endif // JUGADOR_H

