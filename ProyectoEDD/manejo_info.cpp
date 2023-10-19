#include "manejo_info.h"
#include "Risk.h"
#include "Jugador.h"
#include "Pais.h" 
#include "Tablero.h" 

#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>
#include <random>
#include <algorithm>

using namespace std;

// Función para imprimir los países sin dueño
void imprimirPaisesSinDueno(const Risk& Risk) {
  std::cout << "Paises sin dueño:" << std::endl;
  for (const Pais& pais : Risk.paises) {
    if (pais.dueno == "vacio") {
      std::cout << pais.nombre << std::endl;
    }
  }
}

// Función para inicializar el juego
void inicializar(Risk& Risk) {
  std::string modo = "auto";
  int numjugadores;
  std::string input;

  std::cout << "Ingrese el numero de jugadores: ";
  std::getline(std::cin, input);

  try {
      numjugadores = std::stoi(input);

      while (numjugadores < 3 || numjugadores > 6) {
          std::cout << "Numero de jugadores incorrecto. Por favor, ingrese un numero entre 3 y 6: ";
          std::getline(std::cin, input);
          numjugadores = std::stoi(input);
      }
  } catch (std::invalid_argument const &e) {
      std::cerr << "Entrada no válida. Por favor, ingrese un número válido." << std::endl;
  } catch (std::out_of_range const &e) {
      std::cerr << "Número fuera de rango. Por favor, ingrese un número entre 3 y 6." << std::endl;
  }


// Calcular las tropas iniciales en función del número de jugadores
int tropasIniciales = 35 - 5 * (numjugadores - 3);

for (int i = 0; i < numjugadores; ++i) 
{
  Jugador Jugador;
  std::cout << "Ingrese el nombre del Jugador " << (i + 1) << ": ";
  std::getline(std::cin, Jugador.nombre);
  Jugador.tropas = tropasIniciales;
  Risk.jugadores.push_back(Jugador);
}

  // Repartir los países entre los jugadores
  if (modo == "auto")
  {
   std::vector<std::string> nombres_paises; // Lista de nombres de países
    for (const Pais& pais : Risk.paises) {
      nombres_paises.push_back(pais.nombre);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(nombres_paises.begin(), nombres_paises.end(), g);

    int num_paises = Risk.paises.size();
    int num_jugadores = Risk.jugadores.size();
    if (num_paises >= num_jugadores && numjugadores <= num_paises) {
      for (int j = 0; j < num_paises; j++) {
        int jugador_index = j % num_jugadores;
        if (jugador_index < num_jugadores) {
          Risk.paises[j].dueno = Risk.jugadores[jugador_index].nombre;
          Risk.paises[j].tropas = 1;
          Risk.jugadores[jugador_index].tropas -= 1;
          Risk.jugadores[jugador_index].paisesj.push_back(Risk.paises[j]);
        }
      }
    } else {
      std::cerr << "Número de jugadores o países incorrecto" << std::endl;
    }
  } 
  else {
    // Asignación manual de países
    for (int j = 0; j < Risk.paises.size(); j++) {
      imprimirPaisesSinDueno(Risk);
      std::cout << Risk.jugadores[j % numjugadores].nombre
                << " Seleccione el pais donde quiere poner tropas:" << std::endl;
      std::string x;
      std::getline(std::cin, x);
      int i = 0;
      while (i < Risk.paises.size() && Risk.paises[i].nombre != x) {
        i++;
      }
      if (i >= Risk.paises.size()) {
        std::cout << "No se encontro el pais. Verifique si tiene errores de ortografia." << std::endl;
        j--;
      } else if (Risk.paises[i].dueno == "vacio") {
        Risk.paises[i].dueno = Risk.jugadores[j % numjugadores].nombre;
        Risk.paises[i].tropas = 1;
        Risk.jugadores[j % numjugadores].tropas -= 1;
        Risk.jugadores[j % numjugadores].paisesj.push_back(Risk.paises[i]);
      } else {
        std::cout << "Ya hay tropas en este pais. Seleccione otro." << std::endl;
        j--;
      }
    }
  }
  
  Risk.tablero->jugadores = Risk.jugadores;
  Risk.tablero->paises = Risk.paises;
  return;
}

void turno(const std::string& JugadorId, Risk& Risk) {
    try {
        int jugadorTurno = std::stoi(JugadorId);
        if (jugadorTurno < 0 || jugadorTurno >= Risk.jugadores.size()) {
            std::cout << "Se esperaba un ID de jugador válido" << std::endl;
            return;
        }

        if (Risk.tablero->turnoActual != jugadorTurno) {
            std::cout << "No es el turno de este jugador" << std::endl;
            return;
        }

        Risk.tablero->empezar_turno();
        return;
    } catch (const std::invalid_argument& e) {
        std::cout << "Se esperaba un ID de jugador válido" << std::endl;
        return;
    }
}


void salir() { cout << "Juego Terminado.\n"; }


