/**************************************************************************
 * 1.cpp: Solução da Questao 1                                            *
 * Autor: Prof. Josué Pereira de Castro                                   *
 *************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

/**************************************************************************
 * Definições de constantes                                               *
 *************************************************************************/
#define GSIZE 100

/**************************************************************************
 * Definições de tipos                                                    *
 *************************************************************************/
typedef struct
{
   char dna[GSIZE]; // cadeia de DNA
   int size;        // tamanho da cadeia
} DNA;

/**************************************************************************
 * Variáveis globais                                                       *
 *************************************************************************/
DNA p;  // subcadeia a ser procurada (direta)
DNA pci; // subcadeia complementar invertida de p
DNA t;   // cadeia de DNA onde se procura a subcadeia p
FILE *in;   // ponteiro para o arquivo de entrada
FILE *out;  // ponteiro para o arquivo de saída

/**************************************************************************
 * void com_inv(const DNA &p, DNA &pci): obtém a cadeia complementar      *
 *    invertida pci a partir da cadeia p                                  *
 *************************************************************************/
void com_inv(const DNA &a, DNA &aci)
{
   // complementa a cadeia
   for (int i = a.size - 1, j = 0; i >= 0; i--, j++)
   {
      if (a.dna[i] == 'A')
         aci.dna[j] = 'T';
      else if (a.dna[i] == 'T')
         aci.dna[j] = 'A';
      else if (a.dna[i] == 'C')
         aci.dna[j] = 'G';
      else if (a.dna[i] == 'G')
         aci.dna[j] = 'C';
   }
   aci.size = a.size;
   
   return;
}

/**************************************************************************
 * Função Principal                                                       *
 *************************************************************************/
int main()
{
   // abertura dos arquivos de dados
   in = fopen("genoma.in", "r");
   if (!in)
   {
      printf("Erro 1: arquivo genoma.in não pode ser aberto.\n");
      exit(1);
   }
   out = fopen("genoma.out", "w");
   if (!out)
   {
      printf("Erro 2: arquivo genoma.out não pode ser aberto.\n");
      exit(2);
   }

   int teste = 0; // contador dos casos de teste
   char buffer_t[GSIZE]; // ponteiro para o ponto inicial da busca em t
   
   // leitura dos dados de entrada
   
   while (fscanf(in, "%d %d", &p.size, &t.size) && p.size && t.size)
   {
      fprintf(out, "Teste %d\n", ++teste);
      fscanf(in, "%s", p.dna);  // cadeia p
      fscanf(in, "%s", t.dna);  // cadeia t

      // calcula a cadeia complementar invertida de p em pci
      com_inv(p, pci);

      // procura p em t
      fprintf(out, "Ocorrencia direta: ");
      strcpy(buffer_t, t.dna);  // copia para buffer_t
      char *k = strstr(buffer_t, p.dna);
      if (!k)
         fprintf(out, "0"); // não achou
      else
         while (k)
         {
            int m = k - &buffer_t[0];
            fprintf(out, "%d ", m + 1);
            buffer_t[m] = ' ';
            k = strstr(buffer_t, p.dna);
         }
      fprintf(out, "\n");
      // procura pci em t
      fprintf(out, "Ocorrencia complementar invertida: ");
      strcpy(buffer_t, t.dna);  // copia para buffer_t
      k = strstr(buffer_t, pci.dna);
      if (!k)
         fprintf(out, "0"); // não achou
      else
         while (k)
         {
            int m = k - &buffer_t[0];
            fprintf(out, "%d ", m + 1);
            buffer_t[m] = ' ';
            k = strstr(buffer_t, pci.dna);
         }
      fprintf(out, "\n\n");
   }
   // fecha os arquivos de dados
   fclose(in);
   fclose(out);
   
   return 0;
}
