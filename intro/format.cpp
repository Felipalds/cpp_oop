// Programa ExFormatNum.cpp
// Demonstra a formatação de números em ponto flutuante

#include <iostream>
using namespace std;

int main()
{
	float a = 0; 
	float b = 0;  
	float c = 0;
	
	// Estabelece o padrão de exibição como fixo com ponto exibido
	cout.setf(ios::fixed); //representação fixa de casas demais, não vou poder variar isso
	cout.setf(ios::showpoint); //mostrar o ponto, mesmo caso não possua casa decimal.
	
	cout << "Entre com o valor de A: ";
	cin >> a;
	cout << "Entre com o valor de B: ";
	cin >> b;
	c = a/b;
	cout.precision(1);
	cout << "O valor de C = A/B com uma casa decimal é: " << a << endl;
	cout.precision(2);
	cout << "O valor de C = A/B com duas casas decimais é: " << c << endl;
	cout.precision(3);
	cout << "O valor de C = A/B com três casas decimais é: " << c << endl;
}
