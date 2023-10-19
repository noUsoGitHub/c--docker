#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <string>
#include <vector>
#include "Risk.h"
#include "Jugador.h"
#include "Pais.h"
#include "Dados.h"

class Tablero {
public:
    // Constructor por defecto de la clase Tablero.
    Tablero();
    
    // Constructor de la clase Tablero que recibe un vector de jugadores y un vector de países.
    Tablero(std::vector<Jugador> jugadores, std::vector<Pais> paises);
    
    // Iniciar el turno actual en el tablero.
    void empezar_turno();
    
    // Vector de jugadores en el juego.
    std::vector<Jugador> jugadores;
    
    // Vector de países en el juego.
    std::vector<Pais> paises;
    
    // Número que representa el turno actual en el juego.
    int turnoActual;
    
    // Distribuir tropas entre los jugadores al inicio de un turno.
    void distribuir_tropas();
    
    // Pasar al siguiente turno en el juego.
    void siguenteturno();
    
    // Comparar los resultados de los dados de un atacante y un defensor.
    std::pair<int, int> comparar_dados(Dados atacante, Dados defensor);
    
    // Realizar un ataque entre dos países.
    void Atacar(Pais atacante, Pais defensor);
    
    // Obtener el jugador cuyo turno está en curso.
    Jugador obtenerJugadorTurno();
    
    // Mostrar el menú principal del juego.
    void mostrar_menu();
    
    // Mostrar el menú para realizar ataques.
    void atacar_menu();
};

#endif // TABLERO_H

