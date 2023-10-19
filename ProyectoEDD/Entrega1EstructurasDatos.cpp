#include "comandos.h"
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>


using namespace std;

int main(int argc, char *argv[])
{
  
  //Ascii art para el nombre del juego
  
    cout << "+--------------------------------------------------------------------+\n";
    cout << "|                            BIENVENIDO A:                           |\n";
    cout << "+--------------------------------------------------------------------+\n";
   cout << "RRRRRRRRRRRRRRRRR   IIIIIIIIII   SSSSSSSSSSSSSSS KKKKKKKKK    KKKKKKK\n";
    cout << "R::::::::::::::::R  I::::::::I SS:::::::::::::::SK:::::::K    K:::::K\n";
    cout << "R::::::RRRRRR:::::R I::::::::IS:::::SSSSSS::::::SK:::::::K    K:::::K\n";
    cout << "RR:::::R     R:::::RII::::::IIS:::::S     SSSSSSSK:::::::K   K::::::K\n";
    cout << "  R::::R     R:::::R  I::::I  S:::::S            KK::::::K  K:::::KKK\n";
    cout << "  R::::R     R:::::R  I::::I  S:::::S              K:::::K K:::::K   \n";
    cout << "  R::::RRRRRR:::::R   I::::I   S::::SSSS           K::::::K:::::K    \n";
    cout << "  R:::::::::::::RR    I::::I    SS::::::SSSSS      K:::::::::::K     \n";
    cout << "  R::::RRRRRR:::::R   I::::I      SSS::::::::SS    K:::::::::::K     \n";
    cout << "  R::::R     R:::::R  I::::I         SSSSSS::::S   K::::::K:::::K    \n";
    cout << "  R::::R     R:::::R  I::::I              S:::::S  K:::::K K:::::K   \n";
    cout << "  R::::R     R:::::R  I::::I              S:::::SKK::::::K  K:::::KKK\n";
    cout << "RR:::::R     R:::::RII::::::IISSSSSSS     S:::::SK:::::::K   K::::::K\n";
    cout << "R::::::R     R:::::RI::::::::IS::::::SSSSSS:::::SK:::::::K    K:::::K\n";
    cout << "R::::::R     R:::::RI::::::::IS:::::::::::::::SS K:::::::K    K:::::K\n";
    cout << "RRRRRRRR     RRRRRRRIIIIIIIIII SSSSSSSSSSSSSSS   KKKKKKKKK    KKKKKKK\n";
    cout << "+--------------------------------------------------------------------+\n";
    cout << "|               Digite el comando 'ayuda' (sin comillas)             |\n";
    cout << "|       para obtener información de los comandos disponibles.        |\n";
    cout << "+--------------------------------------------------------------------+\n";

  //Función que carga los comandos (comnados.cpp)
  comandosDisponibles();
}

