#include "Risk.h"
#include "Jugador.h"
#include "Pais.h" 
#include "Tablero.h" 
#include "Dados.h"
#include <string>

using namespace std;

Tablero::Tablero(std::vector<Jugador> jugadores, std::vector<Pais> paises)
    : jugadores(jugadores), paises(paises), turnoActual(0) {}

void Tablero::atacar_menu() {
    string atacante_nombre, defensor_nombre;

    cout << "Ingrese el nombre del país atacante: ";
    cin >> atacante_nombre;

    cout << "Ingrese el nombre del país defensor: ";
    cin >> defensor_nombre;

    // Buscar los países por nombre
    Pais* atacante = nullptr;
    Pais* defensor = nullptr;

    for (Pais& pais : paises) {
        if (pais.nombre == atacante_nombre) {
            atacante = &pais;
        } else if (pais.nombre == defensor_nombre) {
            defensor = &pais;
        }
    }

    if (atacante && defensor) {
        Atacar(*atacante, *defensor);
    } else {
        cout << "Países no encontrados." << endl;
    }
}
void Tablero::mostrar_menu() {
    cout << "1. Atacar" << endl;
    cout << "2. Terminar turno" << endl;
    cout << "Seleccione una opción: ";
}
void Tablero::empezar_turno() {
    distribuir_tropas();
    siguenteturno();

//Manera 1 de poder corregrlo
  
/*int opcion=3;
while (opcion != 2) {
        mostrar_menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                atacar_menu();
                break;
            case 2:
                cout << "\nTerminando Turno\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    }
}*/

//Manera 2 de poder corregirlo, pero no funcionan :(
while (true) {
        mostrar_menu();
        int opcion;
        cin>>opcion;
        
        switch (opcion) {
            case 1:
                atacar_menu();
                break;
            case 2:
                return;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    }
}
  
Jugador Tablero::obtenerJugadorTurno() {
        return jugadores[turnoActual];
    } 

void Tablero::distribuir_tropas() {
     int tropas = 0;
        for (int i = 0; i < jugadores.size(); i++) {
            tropas = jugadores[i].paisesj.size() / 2;
            jugadores[i].tropas += tropas;
        }
}

void Tablero::siguenteturno() {
     turnoActual++;
        if (turnoActual == jugadores.size()) {
            turnoActual = 0;
        }
}

std::pair<int, int> Tablero::comparar_dados(Dados atacante, Dados defensor) {
    // Devuelve el numero de tropas que se le quitan al atacante y el numero de ctropas que se le quitan al vendedor
    std::pair<int, int> resultado;
    int tropas_atacante = 0;
    int tropas_defensor = 0;
    int max_dados = std::min(atacante.dados.size(), defensor.dados.size());
    for (int i = 0; i < max_dados; i++) {
        if (atacante.dados[i] > defensor.dados[i]) {
            tropas_defensor++;
        } else {
            tropas_atacante++;
        }
    }
    resultado.first = tropas_atacante;
    resultado.second = tropas_defensor;
    return resultado;
}


void Tablero::Atacar(Pais atacante, Pais defensor) {
    bool dueno_correcto = false;

    // Revisar si el atacante es del jugador actual
    for (int j = 0; j < jugadores[turnoActual].paisesj.size(); j++) {
        if (jugadores[turnoActual].paisesj[j].nombre == atacante.nombre) {
            dueno_correcto = true;
            break;  // Salir del bucle una vez que se encuentra el país
        }
    }

    if (!dueno_correcto) {
        cout << "No es tu pais" << endl;
        return;
    }

    // Revisar si el defensor es del mismo jugador
    for (int j = 0; j < jugadores[turnoActual].paisesj.size(); j++) {
        if (jugadores[turnoActual].paisesj[j].nombre == defensor.nombre) {
            cout << "No puedes atacar a tu propio pais" << endl;
            return;
        }
    }

    // Definir cuántos dados usar para ataque y defensa
    int cantidad_dados_atacante = 0;
    int cantidad_dados_defensor = 0;

    if (atacante.tropas >= 3) {
        cantidad_dados_atacante = 3;
    } else if (atacante.tropas == 2) {
        cantidad_dados_atacante = 1;
    }

    if (defensor.tropas >= 2) {
        cantidad_dados_defensor = 2;
    } else if (defensor.tropas == 1) {
        cantidad_dados_defensor = 1;
    }

    // Crear objetos Dados para ataque y defensa
    std::vector<int> da(cantidad_dados_atacante);
    std::vector<int> dd(cantidad_dados_defensor);
    Dados dados_atacante("atacante", da);
    Dados dados_defensor("defensor", dd);

    // Realizar el combate de dados y actualizar tropas
    std::pair<int, int> resultado = comparar_dados(dados_atacante, dados_defensor);
    atacante.tropas -= resultado.first;
    defensor.tropas -= resultado.second;

    cout << "Tropas del atacante: " << atacante.tropas << endl;
    cout << "Tropas del defensor: " << defensor.tropas << endl;

    // Si el defensor perdió todas sus tropas, cambiar el dueño del país
    if (defensor.tropas <= 0) {
        cout << "Ganaste el pais" << endl;
        defensor.dueno = jugadores[turnoActual].nombre;
        jugadores[turnoActual].paisesj.push_back(defensor);

        // Preguntar cuántas tropas desea mover
        int tropas_mover;
        cout << "Cuantas tropas desea mover?" << endl;
        cin >> tropas_mover;

        // Revisar si el atacante tiene suficientes tropas
        if (tropas_mover > atacante.tropas) {
            cout << "No tienes suficientes tropas" << endl;
            return;
        }

        // Mover las tropas
        atacante.tropas -= tropas_mover;
        defensor.tropas += tropas_mover;
    }

    // Preguntar si desea parar de atacar
    string parar;
    cout << "Desea parar de atacar? (s/n)" << endl;
    cin >> parar;
    if (parar == "s") {
        return;
    }
}
