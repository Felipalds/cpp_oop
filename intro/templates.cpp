// Programa ExTempFunc.cpp
// Programa exemplo de templates (ou gabaritos) de função

#include <iostream>
using namespace std;

// Definição do  para a função soma.
// A função somatemplate qualquer tipo de número e retorna o resultado com o mesmo
// tipo da primeira variável passada como parâmetro.
template <class T1, class T2>
T1 soma(T1 v1, T2 v2)
{
   return T1(v1 + v2);
}

int main()
{
   // Usando o template com inteiros
   int int1, int2;
   cout << "digite dois valores inteiros separados por espaço: ";
   cin >> int1 >> int2;
   cout << "A soma dos valores é: " << soma(int1, int2) << endl;
   
   // Usando o template com floats
   float float1, float2;
   cout << "digite dois valores reais separados por espaço: ";
   cin >> float1 >> float2;
   cout << "A soma dos valores é: " << soma(float1, float2) << endl;
	cout << "Digite um inteiro e um float separados por espaço: ";
	cin >> int1 >> float1;
	cout << "A soma dos valores (resultado int) é: " << soma(int1, float1)
		<< endl;
	cout << "a soma dos valores (resultado float) é: " << soma(float1, int1)
		<< endl;
}
