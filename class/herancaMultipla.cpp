// ExHeraMult.cpp
// Exemplo de herana Mœltipla em C++

// Bibliotecas
#include <iostream>
using namespace std;

// Declara‹o de classes

// A classe pessoa Ž a classe-base (ou classe m‹e) 
// da qual outra ser‡ derivada

//--------------------------------------------------
// Classe Pessoa
//--------------------------------------------------

class Pessoa{
   protected:
      int RG;
      int CPF;
      char Nome[31];
      char Endereco[41];
      char Telefone[13];
   public:
      Pessoa(); // Construtor default definido pelo programador
      Pessoa(Pessoa &P); // Construtor de c—pia
      ~Pessoa(); // destrutor da classe Pessoa
      int getRG();
      int getCPF();
      char* getNome();
      char* getEndereco();
      char* getTelefone();
      void setRG();
      void setCPF();
      void setNome();
      void setEndereco();
      void setTelefone();
  };

//---------------------------------------------------------
// Classe Lobo
//---------------------------------------------------------
    
  class Lobo
  {
     protected:
        char Cor[31];
        float TamCauda;
        float TamCaninos;
     public:
        Lobo();   // Construtor default
        ~Lobo(); // Destruidor
        char* getCor();
        float getCauda();
        float getCaninos();
        void setCor(char* cor);
        void setCauda(float cauda);
        void setCaninos(float caninos);
  };
  
//---------------------------------------------------------------
// Classe Lobisomem
//---------------------------------------------------------------
  
  class Lobisomem: public Pessoa, public Lobo // Herana Mœltipla
  {
     public:
        Lobisomem(); // Construtor default
        ~Lobisomem(); // Destruidor
        void TransformaHomemLobo(); 
        void TransformaLoboHomem();
        void ShowStatus();
   };
   
// Declara‹o das fun›es da classe Pessoa
Pessoa::Pessoa() // Construtor default
{
   cout <<"\nCriando uma pessoa ...\n";
   RG = 0;
   CPF = 0;
   strcpy(Nome, "");
   strcpy(Endereco, "");
   strcpy(Telefone, "");
   cout << "\nCria‹o concluida!\n";
}

Pessoa::Pessoa(Pessoa &P) // Construtor de c—pia
{
   cout << "\nCriando uma pessoa...\n";
   RG = P.getRG();
   CPF = P.getCPF();
   strcpy(Nome, P.getNome());
   strcpy(Endereco, P.getEndereco());
   strcpy(Telefone, P.getTelefone());
   cout << "\nCria‹o concluida!\n";
}

Pessoa::~Pessoa() // Destruidor da classe pessoa
{
   cout << "\nPessoa destruida! \n";
}
int Pessoa::getRG()
{
   return(RG);
}

int Pessoa::getCPF()
{
   return(CPF);
}

char* Pessoa::getNome() 
{
   return(Nome);
}

char* Pessoa::getEndereco()
{
   return(Endereco);
}

char* Pessoa::getTelefone()
{
   return(Telefone);
}

void Pessoa::setRG()
{
   cout << "Nœmero do RG?\t> " ;
   cin >> RG;
}

void Pessoa::setCPF()
{
   cout <<"Nœmero do CPF?\t> ";
   cin >> CPF;
}

void Pessoa::setNome()
{
   cin.get(); // limpa o buffer
   cout << "Nome?\t\t> ";
   cin.get(Nome, 30);
}

void Pessoa::setEndereco()
{
   cin.get(); // limpa o buffer
   cout << "Endereo?\t> ";
   cin.get (Endereco, 40);
}
void Pessoa::setTelefone()
{
   cin.get(); // limpa o buffer
   cout << "Telefone?\t> ";
   cin.get(Telefone, 12);
}


Lobo::Lobo()
{
   // construtor default
   cout << "\nCriando um lobo!\n";
   strcpy(Cor,"cor de pele humana");
   TamCauda = 0;
   TamCaninos = 0.01;
   cout << "\nCria‹o Concluida.\n";
}

Lobo::~Lobo()
{
   cout << "\nLobo destruido.\n";
}

char* Lobo::getCor()
{
   return Cor;
}

float Lobo::getCauda()
{
   return TamCauda;
}

float Lobo::getCaninos()
{
   return TamCaninos;
}

void Lobo::setCor(char* cor)
{
   strcpy(Cor,cor);
}

void Lobo::setCauda(float cauda)
{
   TamCauda = cauda;
}

void Lobo::setCaninos(float caninos)
{
   TamCaninos = caninos;
}

Lobisomem::Lobisomem()
{
   cout << "\nCriando um Lobisomem...\n";
   cout << "\nLobisomem Criado.\n";
   
}

Lobisomem::~Lobisomem()
{
   cout << "\nLobisomem Destruido\n";
}

void Lobisomem::TransformaHomemLobo()
{
   cout << "\nTransformando um homem em lobisomem...\n";
   setCor("Marrom");
   setCauda(30);
   setCaninos(5);
   cout << "\nTransformacao concluida.\n";
}

void Lobisomem::TransformaLoboHomem()
{
   cout << "\nTransformando Um Lobo em Homem...\n";
   setCor("Cor de pele humana");
   setCauda(0);
   setCaninos(1);
   cout << "\nTransformacao concluida.\n";
}

void Lobisomem::ShowStatus()
{
   cout << "\nStatus do Individuo:\n";
   cout << "\n\tRG......: " << getRG();
   cout << "\n\tCPF.....: " << getCPF();
   cout << "\n\tNome....: " << getNome();
   cout << "\n\tEndereco: " << getEndereco();
   cout << "\n\tTelefone: " << getTelefone();
   cout << "\n\tCor.....: " << getCor();
   cout << "\n\tCauda...: " << getCauda() << " cm";
   cout << "\n\tCaninos.: " << getCaninos() << " cm\n";
}

int main()
{
   Lobisomem* Lupus = new Lobisomem;
   Lupus->setRG();
   Lupus->setCPF();
   Lupus->setNome();
   Lupus->setEndereco();
   Lupus->setTelefone();
   Lupus->setCor("Cor de Pele Humana");
   Lupus->setCauda(0);
   Lupus->setCaninos(1);
   Lupus->ShowStatus();
   Lupus->TransformaHomemLobo();
   Lupus->ShowStatus();
   Lupus->TransformaLoboHomem();
   Lupus->ShowStatus();
   delete Lupus;
   return 0;
}
