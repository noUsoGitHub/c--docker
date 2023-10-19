#include "Risk.h"
#include "Jugador.h"
#include "Pais.h" 
#include "Tablero.h" 

#include <iostream>

void Jugador::mover_tropas(Pais pais1, Pais pais2) {
    // verificar que el jugador sea dueño de los paises
    if (pais1.dueno != nombre || pais2.dueno != nombre) {
        std::cout << "No es dueño de los paises" << std::endl;
        return;
    }

    // preguntar cuantas tropas desea mover
    int tropas;
    std::cout << "¿Cuantas tropas desea mover?" << std::endl;
    std::cin >> tropas;

    // debe dejar al menos 1 unidad en cada uno de sus países
    if (pais1.tropas - tropas < 1) {
        std::cout << "Debe dejar minimo 1 tropa en el pais " << pais1.nombre << std::endl;
        return;
    }

    // verificar que los paises sean adyacentes
    bool adyacente = false;
    for (const std::string& ady : pais1.adyacentes) {
        if (ady == pais2.nombre) {
            adyacente = true;
            break;
        }
    }
    if (!adyacente) {
        std::cout << "Los paises no son adyacentes" << std::endl;
        return;
    }

    pais1.tropas -= tropas;
    pais2.tropas += tropas;
}
