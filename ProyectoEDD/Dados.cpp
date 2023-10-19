#include "Risk.h"
#include "Jugador.h"
#include "Pais.h"
#include "Tablero.h"
#include <iostream>
#include <algorithm> // Para usar la función sort
#include <cstdlib>   // Para usar la función rand
#include <string>

// Constructor de la clase Dados que recibe un color y un vector de valores de dados.
Dados::Dados(std::string color, std::vector<int> dados)
    : tipo(color), dados(dados) {}

// Simula el lanzamiento de los dados y asigna valores aleatorios.
void Dados::tirarDados() {
    for (int i = 0; i < dados.size(); i++) {
        dados[i] = rand() % 6 + 1;  // Números aleatorios del 1 al 6 (inclusivo).
    }
}

// Ordena los valores de los dados en orden ascendente.
void Dados::ordenarDados() {
    std::sort(dados.begin(), dados.end());
}

// Imprime los valores de los dados.
void Dados::imprimirDados() {
    for (int i = 0; i < dados.size(); i++) {
        std::cout << dados[i] << " ";
    }
    std::cout << std::endl;
}

// Obtiene el valor más alto de los dados.
int Dados::obtenerMayor() {
    int mayor = dados[0];
    for (int i = 1; i < dados.size(); i++) {
        if (dados[i] > mayor) {
            mayor = dados[i];
        }
    }
    return mayor;
}

// Obtiene el segundo valor más alto de los dados.
int Dados::obtenerSegundoMayor() {
    int mayor = obtenerMayor();
    int segundoMayor = dados[0];
    for (int i = 1; i < dados.size(); i++) {
        if (dados[i] > segundoMayor && dados[i] < mayor) {
            segundoMayor = dados[i];
        }
    }
    return segundoMayor;
}
