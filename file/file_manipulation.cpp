// Programa ExFileMan
// Exemplifica o processamento de arquivos em C++
// Autor: Prof. JosuŽ Pereira de Castro

// inclus‹o das bibliotecas necess‡rias
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
   char filename[256];
   char line[256];
   cout << "\n\n\n\n\t\t\tPrograma ExFileMan\n\n\n";
   cout << "\n\n\n\t\tExemplifica a manipula‹o de arquivos em C++\n\n";
   cout << "Qual o nome do arquivo que deseja criar? > ";
   cin.get(filename, 256);
   cout << "Criando o arquivo " << filename << "...\n";
   
   // exemplifica a abertura de um arquivo para gravação com aclasse ofstream
   ofstream MyOutFile;
   MyOutFile.open(filename);
   if (MyOutFile.fail())
   {
      cout << "\nErro: Arquivo n‹o pode ser aberto.\n";
      exit(0);
   }
   MyOutFile << "Esta frase sera gravada no arquivo " << filename << endl;
   cout << "Esta frase sera gravada no arquivo " << filename << endl;
   MyOutFile.close();
   
   // exemplifica a abertura de arquivo para leitura com a classe ifstream
   ifstream MyInFile;
   MyInFile.open(filename);
   if (MyInFile.fail())
   {
      cout << "\nErro: Arquivo n‹o pode ser aberto.";
      exit(0);
   }
   MyInFile.get(line, 256);
   cout << "A seguinte frase foi lida do arquivo:\n" << line << endl;
   MyInFile.close();
   
   // Exemplifica a abertura de arquivos para leitura e escrita com a classe ofstream
   MyOutFile.open(filename, ios::app);
   if (MyOutFile.fail())
   {
      cout << "\nErro: Arquivo n‹o pode ser aberto.";
      exit(0);
   }
   MyOutFile << "Esta frase sera colocada no final do arquivo." << endl;
   cout << "Esta frase sera colocada no final do arquivo." << endl;
   MyOutFile.close();
   cout << endl;
   return 0;
}
