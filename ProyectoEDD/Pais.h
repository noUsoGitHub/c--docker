#ifndef PAIS_H
#define PAIS_H

#include <string>
#include <vector>

class Pais {
public:
    // Id
    short id;
    // Nombre del país.
    std::string nombre;
    
    // Continente al que pertenece el país.
    std::string continente;
    
    // Nombre del dueño (jugador) del país.
    std::string dueno;
    
    // Nombre de países vecinos (adyacentes).
    std::vector<std::string> adyacentes; // nombre de paises adyacentes
    
    // Número de tropas en el país.
    int tropas;
};

#endif
