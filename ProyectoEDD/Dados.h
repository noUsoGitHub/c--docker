#ifndef DADOS_H
#define DADOS_H

#include <string>
#include <vector>

class Dados {
public:
    // Constructor de la clase Dados que recibe un color y un vector de valores de dados.
    Dados(std::string color, std::vector<int> dados);

    // Tirar los dados y asignar valores aleatorios.
    void tirarDados();

    // Ordenar los valores de los dados en orden descendente.
    void ordenarDados();

    // Imprimir los valores de los dados.
    void imprimirDados();

    // Obtener el valor más alto de los dados.
    int obtenerMayor();

    // Obtener el segundo valor más alto de los dados.
    int obtenerSegundoMayor();

    // Tipo de dados.
    std::string tipo;

    // Vector que almacena los valores de los dados.
    std::vector<int> dados;
};

#endif // DADOS_H
