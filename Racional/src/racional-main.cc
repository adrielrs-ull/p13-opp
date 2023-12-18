#include <iostream>
#include "racional.h"
#include <vector>
#include <fstream>

bool CheckCorrectParameters(const int argc, char* argv[], const int& kCorrectNumber) {
  if (argc != kCorrectNumber) {
    return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  if (CheckCorrectParameters(argc, argv, 2)) {
    std::string kArchivo {argv[1]};
    std::vector<std::pair<Racional, Racional>> paresRacionales;
    std::ifstream input_file{kArchivo, std::ios_base::in};
    if (!input_file.is_open()) {
      std::cout << "Ha habido un problema al abrir el archivo" << std::endl;
      return 1;
    }
    Racional racional1, racional2;
    while (input_file >> racional1 >> racional2) {
      paresRacionales.emplace_back(std::make_pair(racional1, racional2));
    }
    input_file.close();
    std::ofstream output_file{"archivo_salida.txt", std::ios::app};
    for (const auto& pair : paresRacionales) {
      output_file << pair.first + pair.second << std::endl;
      output_file << pair.first - pair.second << std::endl;
      output_file << pair.first * pair.second << std::endl;
      output_file << pair.first / pair.second << std::endl;
    }
    output_file.close();

  } else if (argc == 2) {
    std::cout << "./racionales -- Números Racionales" << std::endl;
    std::cout << "Modo de uso: ./racionales fichero_entrada fichero_salida" << std::endl;
    std::cout << "Pruebe ./racionales --help para más información" << std::endl;
    std::cout << "Si el programa se ejecuta pasando como parámetro la opción --help se ha de obtener:" << std::endl;
    std::cout << "./racionales -- Números Racionales" << std::endl;
    std::cout << "Modo de uso: ./racionales fichero_entrada fichero_salida" << std::endl;
    std::cout << "fichero_entrada: Fichero de texto conteniendo líneas con un par de números racionales: a/b c/d separados por un espacio" << std::endl;
    std::cout << "fichero_salida: Fichero de texto que contendrá líneas con las operaciones realizadas: a/b + c/d = n/m" << std::endl;
  } else {
    std::cout << "El número de parámetros es erróneo" << std::endl;
  }
  return 0;
}