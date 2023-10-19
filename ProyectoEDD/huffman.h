#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "Risk.h"
#include "Jugador.h"
#include "Pais.h"
#include "Tablero.h"
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bitset>

struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}

    // Función de comparación para usar con la cola de prioridad
    bool operator>(const HuffmanNode& other) const {
        return frequency > other.frequency;
    }
};

void deleteHuffmanTree(HuffmanNode* root);

void generateHuffmanCodes(HuffmanNode* root, std::string code, std::map<char, std::string>& huffmanCodes);

void buildHuffmanTree(std::vector<HuffmanNode*>& nodes);

void encodeFile(const std::string& inputFileName, const std::string& outputFileName);

void decodeFile(const std::string& inputFileName, const std::string& outputFileName);





void guardar(const std::string& file, Risk& juego);
void guardar_comprimido(const std::string& nombre_archivo,Risk& juego);
void inicializar_archivo(const std::string& nombre_archivo,Risk& juego);
void detalles(const Risk& juego);
#endif //  HUFFMAN_H
