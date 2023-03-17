#include <iostream>
using namespace std;

class Racional{

    private:
        int numerator;
        int denominator;

    public:
        Racional(); //default constructor
        Racional(int num, int den); //parametrized constructor
        Racional(const Racional &R); //copy constructor

        
        friend istream &operator >> (istream &input, Racional &R); 
        friend ostream &operator << (ostream &output, const Racional &R);
        //sobrecarregando o cin e o cout para o tipo racional. Vai funcionar
        //igual qualquer um, mas quando tiver algo do tipo Racional, vai ser
        //da nossa forma. Todas as classes bases do C já tem implementado...
        // para leitura não pode ser constante, pois teremos que alterar
        // já o de escrita deve ser, não podemos alterar o valor na escrita!
       
        /*
         * (cin >> A) retorna istream!
         * é como se fosse recursivo
         * (cin >> A) >> B isso também retorna istream. 
         * O ponteiro do buffer é atualizado toda vez, 
         * por isso o & no &operator
         */


        friend Racional operator +(const Racional &L, const Racional &R);
        friend Racional operator +(int L, const Racional &R);
        friend Racional operator +(const Racional &L, int R);

        friend Racional operator -(const Racional &L, const Racional &R);
        friend Racional operator -(int L, const Racional &R);
        friend Racional operator -(const Racional &L, int R);

        friend Racional operator *(const Racional &L, const Racional &R);
        friend Racional operator *(int L, const Racional &R);
        friend Racional operator *(const Racional &L, int R);
      
        friend Racional operator /(const Racional &L, const Racional &R);
        friend Racional operator /(int L, const Racional &R);
        friend Racional operator /(const Racional &L, int R);
};

