#ifndef RACIONAL_H
#define RACIONAL_H
#include <iostream>

class Racional {
 public: 
  Racional();
  Racional(const int numerador, const int denominador);
  int numerador() const;
  int denominador() const;
  Racional operator+(const Racional& other) const;
  Racional operator-(const Racional& other) const;
  Racional operator*(const Racional& other) const;
  Racional operator/(const Racional& other) const;
  friend std::istream& operator>>(std::istream& is, Racional& racional);
 private:
  int numerador_;
  int denominador_;
};

std::ostream& operator<<(std::ostream& os, const Racional& racional);

#endif