// Programa ExRef.cpp
// Compara chamadas por valor e chamadas por referência

#include <iostream>
using namespace std;

int SquareByValue(int a) // a é passado por valor para esta função
{
	return (a *= a); // O argumento passado não é modificado
	// a é uma variável LOCAL!
}

void SquareByReference(int &cRef) // O argumento é passado por referência (estou pegando o endereço de uma variável)
{
	cRef *= cRef; // O argumento foi modificado!
	// Afinal estamos modificando a variável declarada neste endereço.

	cout << "Dentro de SquareByReference: cRef = " << cRef << endl;
}

int main()
{
	int x = 2, z = 4;
	cout << "x = " << x << " antes de SquareByValue\n"
	     << "valor retornado por SquareByValue: "
	     << SquareByValue(x) << endl
	     << "x = " << x << " depois de SquareByValue\n" << endl;
	cout << "z = " << z << " antes de SquareByReference" << endl;
	SquareByReference(z);
	cout << "z = " << z << " depois de SquareByReference" << endl;
	return 0;
}