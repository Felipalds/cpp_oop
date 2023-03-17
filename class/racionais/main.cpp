#include <iostream>
#include "racionais.h"
using namespace std;

int main(){
    
  cout << "Teste da classe Racional! \n\n";
  cout << "1. Criação de um racional A com construtor default:\n";
  Racional A;
  cout << A; 


  cout << "2. Criação de um racional com construtor parametrizado: \n";
  Racional B(1, -2);
  cout << B;

  cout << "3. Criação de um racional com construtor por cópia\n";
  Racional C(B);
  cout << C;


    
  return 0;
}
