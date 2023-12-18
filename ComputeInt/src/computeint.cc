#include <iostream>

class ComputeInt {
 public:
  ComputeInt(const int numero, const int numero2) : numero_{numero}, numero2_{numero2} {}
  int Factorial() {
    if (numero_ < 1) {
      return 1;
    }
    int resultado{1};
    for (int i{1}; i <= numero_; i++) {
      resultado *= i;
    }
    return resultado;
  }

  int SumSerie() {
    int resultado{0};
    for (int i{1}; i <= numero_; ++i ) {
      resultado += i;
    }
    return resultado;
  }

bool IsPrime() {
  for (int i{2}; i * i <= numero_; i++) {
    if (numero_ % i == 0) {
      return false;
    }
  }
  if (numero_ == 0 || numero_ == 1) {
    return false;
  }
  return true;
}

bool AreRelativePrimes() {
  bool n1;
  for (int i{2}; i * i <= numero_; i++) {
    if (numero_ % i == 0) {
      n1 = false;
    }
  }
  if (numero_ == 0 || numero_ == 1) {
    n1 = false;
  } else {
    n1 = true;
  }
  
  bool n2;
  for (int i{2}; i * i <= numero2_; i++) {
    if (numero2_ % i == 0) {
      n2 = false;
    }
  }
  if (numero2_ == 0 || numero2_ == 1) {
    n2 = false;
  } else {
    n2 = true;
  }
  if (n1 && n2) {
    return true;
  }
  return false;
}

 private:
  int numero_;
  int numero2_;
};

bool CheckCorrectParameters(const int argc, char* argv[], const int& kCorrectNumber) {
  if (argc != kCorrectNumber) {
    return false;
  }
  return true;
}

void Print(char *argv[]) {
  int n{std::stoi(argv[1])};
  int n2{std::stoi(argv[2])};
  ComputeInt numero{n, n2};
  std::cout << numero.Factorial() << std::endl;
  std::cout << numero.SumSerie() << std::endl;
  if (numero.IsPrime()) {
    std::cout << "Is prime" << std::endl;
  } else {
    std::cout << "Is not prime" << std::endl;
  }
  if (numero.AreRelativePrimes()) {
    std::cout << "They are relative primes" << std::endl;
  } else {
    std::cout << "They are not relative primes" << std::endl;
  }
}

int main(int argc, char* argv[]) {
  if (CheckCorrectParameters(argc, argv, 3)) {
    Print(argv);
  } else {
    std::cout << "El númeo de parámetros es erróneo" << std::endl;
  } 
  return 0;
}