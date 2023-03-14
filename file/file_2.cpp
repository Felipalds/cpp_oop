
// Programa ExFileMan2
// Exemplifica entrada e saida em arquivos

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
   cout << "\nEste programa lê um conjunto de inteiros armazenados em um"
		<< " arquivo texto\ne imprime a sua soma em outro arquivo texto\n\n";
   cout << "Qual o nome do arquivo de entrada? > ";
   char InFile[256]; // Variável para armazenar o nome do arquivo de entrada
   cin >> InFile;
   cout << "Qual o nome do arquivo de saida? > ";
   char OutFile[256];
   cin >> OutFile;
   
   ifstream in;
   ofstream out;
   in.open(InFile);
   out.open(OutFile);
   int num = 0;
   int soma = 0;
	// Faz a primeira leitura fora do laço para verificar o fim de arquivo 
	// já na primeira iteração
	in >> num;
	while (!in.eof())
	{
		soma += num; // Se a leitura teve sucesso, calcula a soma
		in >> num;	 // tenta nova leitura
	}
   
   out << soma;
   cout << "\nProcessamento concluido.\n" ;
}
