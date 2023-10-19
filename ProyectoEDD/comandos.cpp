#include "comandos.h"
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>
#include <vector>
#include "manejo_info.h"
#include "Risk.h"
#include "Jugador.h"
#include "Pais.h" 
#include "Tablero.h" 
#include "Aux.h"
#include "huffman.h"

using namespace std;

Risk Risk;
void comandosDisponibles() {
  
  string command="";
  string lastCommand="ayuda";
  bool a = true;
  
  do {
    command="";
    while (command==""||command=="\n")
    {
    // Imprimir el indicador de línea de comando
    cout << "$ ";
    // Leer la entrada del usuario
    getline(cin, command);
    }
    vector<string> tokens;
    istringstream iss(command);
    string s;
    
    while (iss >> s) {
      tokens.push_back(s);
    }
    command = tokens[0];
    if (command=="lc")
      command = lastCommand;
    else
      lastCommand=command;
    if (command == "inicializar") {
      if (tokens.size() != 1) {
        cout << "Cantidad de parametros incorrecto.\n";
      }else {
        inicializar(Risk);
        cout <<"Paso";
      }
    } 
    else if (command == "turno") {
      if (tokens.size() != 2) {
        cout << "Cantidad de parametros incorrecto.\n";
      } else {
        turno(tokens[1],Risk);
      }
    } 
    else if (command == "salir") {
      if (tokens.size() != 1) {
        cout << "Cantidad de parametros incorrecto.\n";
      } else {
        salir();
        a = false;
      }
    } 
    else if (command == "guardar") {
      if (tokens.size() != 2) {
        cout << "Cantidad de parametros incorrecto.\n";
      } else {
        guardar(tokens[1],Risk);
      }
    } 
    else if (command == "guardar_comprimido") {
      if (tokens.size() != 2) {
        cout << "Cantidad de parametros incorrecto.\n";
      } else {
        guardar_comprimido(tokens[1],Risk);
      }
    } 
    else if (command == "inicializar_archivo") {
      if (tokens.size() != 2) {
        cout << "Cantidad de parametros incorrecto.\n";
      } else {
        inicializar_archivo(tokens[1],Risk);
      }
    }else if (command == "detalles") {
      if (tokens.size() != 1) {
        cout << "Cantidad de parametros incorrecto.\n";
      } else {
        detalles(Risk);
      }
    } 
    else if (command == "ayuda") {
      if (tokens.size() != 1) {
        cout << "Cantidad de parametros incorrecto.\n";
      } else {
        ayuda();
      }
    } 
    else if (command == "costo_conquista") {
      if (tokens.size() != 2) {
        cout << "Cantidad de parametros incorrecto.\n";
      } else {
        costo_conquista();
      }
    } 
    else if (command == "conquista_mas_barata") {
      if (tokens.size() != 1) {
        cout << "Cantidad de parametros incorrecto.\n";
      } else {
        conquista_mas_barata();
      }
    } 
    else
      cout<<"Comando no reconocido"<<endl;

  } while (a == true);
}
