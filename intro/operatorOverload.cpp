// Programa ExOverMem.cpp
// Demonstra a sobrecarga de operadores utilizando funções membro 
// de classe

// Inclusão das bibliotecas
#include <iostream>
using namespace std;

// Declaração de classes

class Complexo
{
   private:
      double real;
      double imaginario;
   public:
      // declaração do construtor padrão para a classe
      Complexo(double r = 0, double i = 0);
      // declaração dos operadores sobrecarregados
      Complexo operator +(const Complexo &x);
      Complexo operator +(double x);
      void mostra();
};

// definição dos métodos da classe Complex
Complexo::Complexo(double r, double i)
{
   real = r;
   imaginario = i;
}

Complexo Complexo::operator +(const Complexo &x)
{  // implementa a sobrecarga do operador soma entre dois complexos
 
   // cria um objeto complexo auxiliar para armazenar a soma   
   Complexo aux;
   // o primeiro real é do objeto chamador (elemento à esquerda do 
   // operador). x.real refere-se ao objeto passado como parâmetro 
   // (elemento à direita do operador)
   aux.real = real + x.real;
   aux.imaginario = imaginario + x.imaginario;
   return aux;
}

Complexo Complexo::operator +(double x)
{
   Complexo aux;
   aux.real = real + x;
   aux.imaginario = imaginario;
   return aux;
}

void Complexo::mostra()
{
   cout << "(" << real << ((imaginario >=0)?" + " : " ") << imaginario << "i)";
}

// Programa principal
int main()
{
   Complexo a (1,-2); // inicia com valores determinados
   Complexo b (-3,4); 
   Complexo c; // utiliza os valores default (0, 0);
   double d = 5;
   
   cout << "Numero a: ";
   a.mostra();
   cout << endl;
   cout << "Numero b: ";
   b.mostra();
   cout << endl;
   c = a + b; // utiliza o operador sobrecarregado +
   cout << "a + b = ";
   c.mostra();
   cout << endl;
   c = c + d;
   cout << "c + " << d << " = ";
   c.mostra();
   cout << endl;
   return 0;
}
