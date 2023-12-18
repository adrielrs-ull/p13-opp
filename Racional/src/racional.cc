#include <iostream>
#include "racional.h"

Racional::Racional() : numerador_{1}, denominador_{1} {};
Racional::Racional(const int numerador, const int denominador) : numerador_{numerador}, denominador_{denominador} {};
int Racional::numerador() const {return numerador_;}
int Racional::denominador() const {return denominador_;}
Racional Racional::operator+(const Racional& other) const {return Racional(numerador() * other.denominador() + other.numerador() * denominador(), denominador() * other.denominador());}
Racional Racional::operator-(const Racional& other) const {return Racional(numerador() * other.denominador() - other.numerador() * denominador(), denominador() * other.denominador());}
Racional Racional::operator*(const Racional& other) const {return Racional(numerador() * other.numerador(), denominador() * other.denominador());}
Racional Racional::operator/(const Racional& other) const {return Racional(numerador() * other.denominador(), denominador() * other.numerador());}

std::istream& operator>>(std::istream& is, Racional& racional) {
  char slash;
  is >> racional.numerador_ >> slash >> racional.denominador_;
  return is;
}

std::ostream& operator<<(std::ostream& os, const Racional& racional) {
  os << racional.numerador() << "/" << racional.denominador();
  return os;
}

