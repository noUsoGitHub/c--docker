#include "huffman.h"
#include "comandos.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "Risk.h"
#include "Jugador.h"
#include "Pais.h"
#include "Tablero.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <bitset>
#include <cstdio> // Incluye la cabecera para std::remove

using namespace std;

void guardar(const std::string& nombre_archivo, Risk& juego) {
    // Abre el archivo de texto para guardar el juego
    std::ofstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para guardar el juego." << std::endl;
        return;
    }

    // Escribe la información del juego en el archivo de texto
    archivo << "Información del juego:\n";
    archivo << "Cantidad de jugadores: " << juego.jugadores.size() << "\n";

    // Recorre y guarda la información de cada jugador
    for (const Jugador& jugador : juego.jugadores) {
        archivo << "Jugador: " << jugador.nombre << "\n";
        archivo << "Color: " << jugador.color << "\n";
        archivo << "Tropas: " << jugador.tropas << "\n";

        archivo << "Países del jugador:\n";
        for (const Pais& pais : jugador.paisesj) {
            archivo << "Nombre del país: " << pais.nombre << "\n";
            archivo << "Continente: " << pais.continente << "\n";
            archivo << "Dueño: " << pais.dueno << "\n";
            archivo << "Tropas en el país: " << pais.tropas << "\n";
            archivo << "Países vecinos:\n";
            for (const std::string& vecino : pais.adyacentes) {
                archivo << " - " << vecino << "\n";
            }
        }

        // Guarda las cartas del jugador
        archivo << "Cartas del jugador:\n";
        for (const std::string& carta : jugador.cartas) {
            archivo << " - " << carta << "\n";
        }

        archivo << "-----------------------------------\n";
    }

    archivo.close();
    std::cout << "La partida ha sido guardada correctamente." << std::endl;
}
void guardar_comprimido(const std::string& nombre_archivo, Risk& juego) {
    guardar(nombre_archivo, juego);
    
    // Borra el archivo original
    if (std::remove(nombre_archivo.c_str()) != 0) {
        std::cerr << "Error al borrar el archivo original." << std::endl;
    }
    
    // Renombra el archivo comprimido
    std::string nuevo_nombre = nombre_archivo + ".bin";
    if (std::rename(nuevo_nombre.c_str(), nombre_archivo.c_str()) != 0) {
        std::cerr << "Error al renombrar el archivo comprimido." << std::endl;
    }

    return;
}

void inicializar_archivo(const std::string& nombre_archivo,Risk& juego) {
    // Abre el archivo de texto para cargar el juego
    std::ifstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para cargar el juego." << std::endl;
        return;
    }

    // Variables temporales para almacenar datos mientras se lee el archivo
    int num_jugadores = 0;
    std::string linea;
    Jugador jugador_actual;
    bool leyendo_jugador = false;

    // Lee el archivo línea por línea
    while (std::getline(archivo, linea)) {
        if (linea.empty()) {
            continue;
        }

        // Procesa la línea actual
        try {
            if (leyendo_jugador) {
                // Si estamos leyendo datos de un jugador
                if (linea.find("Jugador: ") == 0) {
                    // Nueva sección de jugador, finaliza el jugador actual
                    if (!jugador_actual.nombre.empty()) {
                        juego.jugadores.push_back(jugador_actual);
                    }
                    jugador_actual = Jugador();
                    jugador_actual.nombre = linea.substr(9);  // 9 es la longitud de "Jugador: "
                } else if (linea.find("Color: ") == 0) {
                    jugador_actual.color = linea.substr(7);  // 7 es la longitud de "Color: "
                } else if (linea.find("Tropas: ") == 0) {
                    jugador_actual.tropas = std::stoi(linea.substr(8));  // 8 es la longitud de "Tropas: "
                } else if (linea.find("Nombre del país: ") == 0) {
                    Pais pais;
                    pais.nombre = linea.substr(17);  // 18 es la longitud de "Nombre del país: "
                    std::getline(archivo, linea); // Lee la siguiente línea para obtener el continente
                    pais.continente = linea.substr(12);  // 13 es la longitud de "Continente: "
                    std::getline(archivo, linea); // Lee la siguiente línea para obtener el dueño
                    pais.dueno = linea.substr(7);  // 8 es la longitud de "Dueño: "
                    std::getline(archivo, linea); // Lee la siguiente línea para obtener las tropas
                    pais.tropas = std::stoi(linea.substr(19));  // 16 es la longitud de "Tropas en el país: "
                    jugador_actual.paisesj.push_back(pais);
                }
            } else {
                // Si no estamos leyendo datos de un jugador, buscamos información general
                if (linea.find("Cantidad de jugadores: ") == 0) {
                    num_jugadores = std::stoi(linea.substr(23));  // 24 es la longitud de "Cantidad de jugadores: "
                    // Comienza la lectura de un jugador
                    leyendo_jugador = true;
                }
            }
        } catch (const std::invalid_argument& e) {
            // Maneja la excepción de valor no válido
            std::cerr << "Error al procesar una línea: " << e.what() << std::endl;
        }
    }

    // Asegura que el último jugador se añada a la lista
    if (!jugador_actual.nombre.empty()) {
        juego.jugadores.push_back(jugador_actual);
    }

    archivo.close();
    std::cout << "El juego ha sido cargado correctamente." << std::endl;
}
void detalles(const Risk& juego) {
    std::cout << "Información del juego:\n";
    std::cout << "Cantidad de jugadores: " << juego.jugadores.size() << "\n";

    // Recorre y muestra la información de cada jugador
    for (const Jugador& jugador : juego.jugadores) {
        std::cout << "Jugador: " << jugador.nombre << "\n";
        std::cout << "Color: " << jugador.color << "\n";
        std::cout << "Tropas: " << jugador.tropas << "\n";

        std::cout << "Países del jugador:\n";
        for (const Pais& pais : jugador.paisesj) {
            std::cout << "Nombre del país: " << pais.nombre << "\n";
            std::cout << "Continente: " << pais.continente << "\n";
            std::cout << "Dueño: " << pais.dueno << "\n";
            std::cout << "Tropas en el país: " << pais.tropas << "\n";
            std::cout << "Países vecinos:\n";
            for (const std::string& vecino : pais.adyacentes) {
                std::cout << " - " << vecino << "\n";
            }
        }

        // Muestra las cartas del jugador
        std::cout << "Cartas del jugador:\n";
        for (const std::string& carta : jugador.cartas) {
            std::cout << " - " << carta << "\n";
        }

        std::cout << "-----------------------------------\n";
    }
}

void deleteHuffmanTree(HuffmanNode* root) {
    if (root) {
        deleteHuffmanTree(root->left);
        deleteHuffmanTree(root->right);
        delete root;
    }
}

void generateHuffmanCodes(HuffmanNode* root, std::string code, std::map<char, std::string>& huffmanCodes) {
    if (!root)
        return;
    if (!root->left && !root->right)
        huffmanCodes[root->data] = code;
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

void buildHuffmanTree(std::vector<HuffmanNode*>& nodes) {
    std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, std::greater<HuffmanNode>> pq;

    for (auto node : nodes) {
        pq.push(*node);
    }

    while (pq.size() > 1) {
        HuffmanNode* left = new HuffmanNode(0, 0);
        *left = pq.top();
        pq.pop();
        HuffmanNode* right = new HuffmanNode(0, 0);
        *right = pq.top();
        pq.pop();

        HuffmanNode* parent = new HuffmanNode(0, left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        pq.push(*parent);
    }

    if (!pq.empty()) {
        nodes[0] = new HuffmanNode(0, 0);
        *nodes[0] = pq.top();
    }
}

void encodeFile(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inputFile(inputFileName, std::ios::in | std::ios::binary);
    std::ofstream outputFile(outputFileName, std::ios::out | std::ios::binary);

    std::map<char, int> frequencyMap;
    char c;
    while (inputFile.get(c)) {
        frequencyMap[c]++;
    }

    std::vector<HuffmanNode*> nodes;
    for (auto pair : frequencyMap) {
        HuffmanNode* node = new HuffmanNode(pair.first, pair.second);
        nodes.push_back(node);
    }

    buildHuffmanTree(nodes);
    std::map<char, std::string> huffmanCodes;
    generateHuffmanCodes(nodes[0], "", huffmanCodes);
    // Escribir la tabla de códigos Huffman en el archivo de salida
    for (auto pair : huffmanCodes) {
        std::cout << pair.first << pair.second << '\n';
        outputFile << pair.first << pair.second << '\n';
    }

    // Reiniciar el archivo de entrada para codificar los datos reales
    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);

    std::string encodedBits="";
    while (inputFile.get(c)) {
        encodedBits += huffmanCodes[c];
    }

    // Rellenar los bits finales con ceros para que la longitud sea un múltiplo de 8
    while (encodedBits.length() % 8 != 0) {
        encodedBits += "0";
    }
    std::cout<<encodedBits<<std::endl;
    // Convertir la cadena de bits en bytes y escribirlos en el archivo de salida
    outputFile<<encodedBits;
    inputFile.close();
    outputFile.close();

    // Liberar la memoria utilizada por los nodos
    for (auto node : nodes) {
        delete node;
    }
}

void decodeFile(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inputFile(inputFileName, std::ios::in | std::ios::binary);
    std::ofstream outputFile(outputFileName, std::ios::out | std::ios::binary);
    std::map<std::string, char> huffmanCodes;
    std::string line="";
    std::cout << line<<std::endl;
    while (std::getline(inputFile, line)) {
        if (!line.empty()) {
            char symbol = line[0];
            std::string code = line.substr(1);
            std::cout << "CODE: "<<code<<std::endl;
            huffmanCodes[code] = symbol;
        }
    }

    std::string encodedBits="";
    char c;
    while (inputFile.get(c)) {
        std::bitset<8> byte(c);
        encodedBits += byte.to_string();
    }
    std::cout << "BITS: "<<encodedBits<<std::endl;
    std::string decodedText;
    std::string currentCode;
    for (char bit : encodedBits) {
        currentCode += bit;
        if (huffmanCodes.find(currentCode) != huffmanCodes.end()) {
            decodedText += huffmanCodes[currentCode];
            currentCode = "";
        }
    }

    std::cout << "DECODE: "<<decodedText<<std::endl;
    // Write the decoded text as binary data to the output file
    outputFile<<decodedText;
    inputFile.close();
    outputFile.close();
}