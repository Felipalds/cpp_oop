// Programa ExArgDef.cpp
// Exemplifica o uso de valores default para argumentos 
// e protótipos de funções

//Inclusão das bibliotecas
#include <iostream>
using namespace std;

//Definição das funções
float VolCubo(float length = 1, float width = 1, float height = 1)
{
	return(length * width * height);
}

int main()
{
	float length = 0;
	float width = 0;
	float height = 0;
	float VolPadrao = 0;
	float Vol = 0;
	
	cout << "\nCálculo de volume\n";
	cout << "Qual o comprimento? >> ";
	cin >> length;
	cout << "Qual a largura? >> ";
	cin >> width;
	cout << "Qual a altura? >> ";
	cin >> height;
	Vol = VolCubo(length, width, height);
	cout << "Volume desejado = " << Vol << endl;
	
	VolPadrao = VolCubo(2);
	cout << "Volume Padrão   = " << VolPadrao << endl;
	return 0;
}
