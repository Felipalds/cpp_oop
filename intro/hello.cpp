#include <iostream> 
#include <stdio.h> // usar lib antiga do C original
// #include <cstdio> // lib antiga da nova forma
using namespace std; //usamos espaços de nomes padrão, para evitar colocar :: toda vez
// cin e cout são mais lentos que stdio.h
int main()
{
	char Nome[10];
	int idade;
	
    //std::cout << "Hello World!\n"; sem espaços de nomes
    cout << "Hello World!\n";
	// Utiliza o objeto cout para dar saída no vídeo
    cout << "Qual o seu nome? \n";
	cin >> Nome;
	cout << "Olá " << Nome << "!\n";
	cout << "Qual sua idade?" << endl;
	cin >> idade;
	cout << "Você tem " << idade << " anos!" << endl;
	return 0;
}
