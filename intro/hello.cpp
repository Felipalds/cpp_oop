#include <iostream> // in out cpp
using namespace std; // default libs of cpp

/*
    #include <cstdio> for using stdio of C    
*/

int main()
{
	char Nome[10];
	int idade;
	
	cout << "Qual o seu nome? \n";
	cin >> Nome;
	cout << "Olá " << Nome << "!\n";
	cout << "Qual sua idade?" << endl;
	cin >> idade;
	cout << "Você tem " << idade << " anos!" << endl;
	return 0;
}
