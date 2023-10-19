#include "Aux.h"
#include "comandos.h"
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>


using namespace std;
void guardar() {
  cout << "comando: guardar <nombre_archivo>\n"
          "salida en pantalla:\n"
          "(Juego no inicializado) Esta partida no ha sido inicializada "
          "correctamente.\n"
          "(Comando correcto) La partida ha sido guardada correctamente.\n"
          "(Error al guardar) La partida no ha sido guardada correctamente.\n"
          "descripción: El estado actual del juego es guardado en un archivo "
          "de texto. El archivo debe contener la\n"
          "cantidad de jugadores, y para cada jugador debe almacenar su "
          "nombre, su color de jugador, la cantidad\n"
          "de países que ocupa, el identificador de cada país junto con la "
          "cantidad de unidades de ejército en él, la\n"
          "cantidad de tarjetas que posee y el identificador de cada tarjeta. "
          "Note que este comando guarda un archivo\n"
          "de texto plano, sin codificación.\n";

  return;
}
void guardar_comprimido() {
  cout << "comando: guardar_comprimido <nombre_archivo>\n"
          "salida en pantalla:\n"
          "(Juego no inicializado) Esta partida no ha sido inicializada "
          "correctamente.\n"
          "(Comando correcto) La partida ha sido codificada y guardada "
          "correctamente.\n"
          "(Error al codificar y/o guardar) La partida no ha sido codificada "
          "ni guardada correctamente.\n"
          "descripción: El estado actual del juego es guardado en un archivo "
          "binario (con extensión .bin) con la\n"
          "información (la misma que se almacenaría en un archivo de texto "
          "normal, ver comando guardar) comprimida,\n"
          "utilizando la codificación de Huffman en el formato descrito más "
          "arriba.\n";

  return;
}
void inicializar_archivo() {
  cout << "comando: inicializar <nombre_archivo>\n"
          "posibles salidas en pantalla:\n"
          "(Juego en curso) El juego ya ha sido inicializado.\n"
          "(Archivo vacío o incompleto) \""
       << "nombre_archivo"
       << "\" no contiene información válida para inicializar\n"
          "el juego.\n"
          "descripción: Inicializa el juego con los datos contenidos en el "
          "archivo identificado por <nombre_archivo>.\n"
          "El archivo debería contener la información descrita en el comando "
          "guardar. El comando debe poder inicializar el juego desde un "
          "archivo de juego normal (generado por el comando guardar) o un "
          "archivo binario\n"
          "con los datos comprimidos (generado por el comando "
          "guardar_comprimido).\n";

  return;
}
void costo_conquista() {
  cout << "comando: costo_conquista "
       << "territorio"
       << "\n"
          "salida en pantalla:\n"
          "(Juego no inicializado) Esta partida no ha sido inicializada "
          "correctamente.\n"
          "(Juego terminado) Esta partida ya tuvo un ganador.\n"
          "(Comando correcto) Para conquistar el territorio "
       << "territorio"
       << ", debe atacar desde <territorio_1>,\n"
          "pasando por los territorios <territorio_2>, <territorio_3>, ..., "
          "<territorio_m>. Debe\n"
          "conquistar <n> unidades de ejército.\n"
          "descripción: El programa debe calcular el costo y la secuencia de "
          "territorios a ser conquistados para lograr\n"
          "controlar el territorio dado por el usuario. El territorio desde "
          "donde debe atacar debe ser aquel que el jugador\n"
          "tenga controlado más cerca al dado por el jugador. Esta información "
          "se analiza desde el punto de vista del\n"
          "jugador que tiene el turno de juego.\n";
  return;
}
void conquista_mas_barata() {
  cout << "comando: conquista_mas_barata\n"
          "salida en pantalla:\n"
          "(Juego no inicializado) Esta partida no ha sido inicializada "
          "correctamente.\n"
          "(Juego terminado) Esta partida ya tuvo un ganador.\n"
          "(Jugador no válido) La conquista más barata es avanzar sobre el "
          "territorio <territorio_1>\n"
          "desde el territorio <territorio_2>. Para conquistar el territorio "
          "<territorio_1>, debe\n"
          "atacar desde <territorio_2>, pasando por los territorios "
          "<territorio_3>, <territorio_4>,\n"
          "..., <territorio_m>. Debe conquistar <n> unidades de ejército.\n"
          "descripción: De todos los territorios posibles, calcular aquel que "
          "pueda implicar un menor número de\n"
          "unidades de ejército perdidas. Esta información se analiza desde el "
          "punto de vista del jugador que tiene el\n"
          "turno de juego.\n";
  return;
}
void ayuda() {
  cout << "\n\nLista de comandos disponibles:\n";
  cout << "+--------------------------+----------------------------------------"
          "----------+\n";
  cout << "| Comando                  | Descripción                            "
          "          |\n";
  cout << "+--------------------------+----------------------------------------"
          "----------+\n";
  cout << "| inicializar              | Realiza las operaciones necesarias "
          "para          |\n";
  cout << "|                          | inicializar el juego.                  "
          "          |\n";
  cout << "+--------------------------+----------------------------------------"
          "----------+\n";
  cout << "| turno <id_jugador>       | Realiza las operaciones descritas "
          "dentro del     |\n";
  cout << "|                          | turno de un jugador. Por ejemplo, si "
          "se desea    |\n";
  cout << "|                          | acceder al turno del jugador 5, se "
          "debe digitar  |\n";
  cout << "|                          | el comando de esta manera: turno 5.    "
          "          |\n";
  cout << "+--------------------------+----------------------------------------"
          "----------+\n";
  cout << "| guardar <nombre_archivo> | Guarda el estado actual del juego en "
          "un archivo  |\n";
  cout << "|                          | de texto. Por ejemplo, si se desea "
          "guardar la    |\n";
  cout << "|                          | partida bajo el nombre de 'juego', se "
          "debe       |\n";
  cout << "|                          | digitar el comando de esta manera:     "
          "          |\n";
  cout << "|                          | guardar juego.                         "
          "          |\n";
  cout << "+--------------------------+----------------------------------------"
          "----------+\n";
  cout << "| guardar_comprimido       | Guarda el estado actual del juego en "
          "un archivo  |\n";
  cout << "| <nombre_archivo>         | binario comprimido. Por ejemplo, si se "
          "desea     |\n";
  cout << "|                          | guardar la partida bajo el nombre de "
          "'juego',    |\n";
  cout << "|                          | se debe digitar el comando de esta "
          "manera:       |\n";
  cout << "|                          | guardar_comprimido juego.              "
          "          |\n";
  cout << "+--------------------------+----------------------------------------"
          "----------+\n";
  cout << "| inicializar <nombre_archivo> | Inicializa el juego con los datos "
          "contenidos |\n";
  cout << "|                          | en el archivo identificado por "
          "<nombre_archivo>. |\n";
  cout << "|                          | Por ejemplo, si se desea leer el "
          "archivo         |\n";
  cout << "|                          | denominado 'juego' para continuar con "
          "la         |\n";
  cout << "|                          | partida guardada, se debe digitar:     "
          "          |\n";
  cout << "|                          | inicializar juego.                     "
          "          |\n";
  cout << "+--------------------------+----------------------------------------"
          "----------+\n";
  cout << "| costo_conquista <territorio> | Calcula el costo y la secuencia de "
          "          |\n";
  cout << "|                          | territorios a ser conquistados para "
          "lograr       |\n";
  cout << "|                          | controlar el territorio dado por el "
          "usuario.     |\n";
  cout << "|                          | Por ejemplo, para el territorio "
          "'colombia':      |\n";
  cout << "|                          | costo_conquista colombia.              "
          "          |\n";
  cout << "+--------------------------+----------------------------------------"
          "----------+\n";
  cout << "| conquista_mas_barata     | Calcula el territorio que implique un "
          "menor      |\n";
  cout << "|                          | número de unidades de ejército "
          "perdidas.         |\n";
  cout << "+--------------------------+----------------------------------------"
          "----------+\n";
  cout << "| ayuda                    | Muestra la lista de comandos "
          "disponibles.        |\n";
  cout << "+--------------------------+----------------------------------------"
          "----------+\n";
  cout << "| salir                    | Sale del juego Risk.                   "
          "          |\n";
  cout << "+--------------------------+----------------------------------------"
          "----------+\n";
}