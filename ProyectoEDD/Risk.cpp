#include "Risk.h"
#include "Jugador.h"
#include "Pais.h" 
#include "Tablero.h" 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


Risk::Risk() : tablero(nullptr) {
    crear_paises();
    tablero = new Tablero(jugadores, paises);
}

void Risk::crear_paises() {
    std::string paisesF = "paises.txt";
        std::ifstream file(paisesF);
        if (!file) {
            std::cerr << "No se pudo abrir el archivo: " << paisesF << std::endl;
            return;
        }

        int id_counter = 1; // Inicializar un contador

        std::string linea;
        while (std::getline(file, linea)) {
            std::istringstream iss(linea);
            Pais pais;
            pais.id = id_counter++;
            std::getline(iss, pais.nombre, ',');
            std::getline(iss, pais.continente, ',');
            std::getline(iss, pais.dueno, ',');
            paises.push_back(pais);
        }
        file.close();
    }