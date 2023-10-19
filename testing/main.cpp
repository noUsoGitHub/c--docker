#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
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
        
        std::cout <<"Symbol: " <<pair.first<<" Code: " << pair.second << '\n';
        char symbol = pair.first;
        if(symbol=='\n')
        outputFile <<"?"<< pair.second << '\n';
        else
        outputFile << pair.first << pair.second << '\n';
    }

    // Reiniciar el archivo de entrada para codificar los datos reales
    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);

    std::string encodedBits="#";
    while (inputFile.get(c)) {
        encodedBits += huffmanCodes[c];
    }

    // Rellenar los bits finales con ceros para que la longitud sea un múltiplo de 8
    while (encodedBits.length() % 8 != 0) {
        encodedBits += "0";
    }
    std::cout<<"BITS: "<<encodedBits<<std::endl;
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
            if (symbol!='#'){
            std::string code = line.substr(1);
            std::cout<<"Symbol: "<<symbol << " CODE: "<<code<<std::endl;
            if (symbol=='?')
                symbol='\n';
            huffmanCodes[code] = symbol;}
            else
                line = line.substr(1);
        }
    }

    std::string encodedBits=line;
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

int main() {
    std::string inputFileName = "input.txt";
    std::string compressedFileName = "compressed.txt";
    std::string decompressedFileName = "decompressed.txt";

    // Comprimir el archivo de entrada
    encodeFile(inputFileName, compressedFileName);

    // Descomprimir el archivo comprimido
    decodeFile(compressedFileName, decompressedFileName);

    return 0;
}
