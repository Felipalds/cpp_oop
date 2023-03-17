#include <iostream>
#include "racionais.h"
using namespace std;


Racional::Racional(){
    this->numerator = 0;
    this->denominator = 1;
}

Racional::Racional(int num, int den){

    if( den == 0 ){
      cerr << "\nErro: o valor do denominador não pode ser 0.\n";
      cerr << "Valor do denominador ajustado para 1.\n";
      this->numerator = num;
      this->denominator = 1;
    }
    else if(den < 0){
      this->numerator = -num;
      this->denominator = -den;
    }
    else{
      this->numerator = num;
      this->denominator = den;
    }
}

Racional::Racional(const Racional &R){
    this->numerator = R.numerator;
    this->denominator = R.denominator;
}

istream &operator >>(istream &input, Racional &R){
  input >> R.numerator;
  input.ignore();
  input >> R.denominator;
  return input;
}

ostream &operator <<(ostream &output, const Racional &R){
  output << R.numerator << "/" << R.denominator;
  return output;
}

Racional operator +(const Racional &L, const Racional &R){
  Racional aux;
  aux.numerator = L.numerator * R.denominator + L.denominator * R.numerator;
  aux.denominator = L.denominator * R.denominator;
  return aux;
}



