#include <iostream>
#include <string>
using namespace std;


class Genoma{

    int sizeP;
    int sizeGenoma;
    char p[100];
    char genoma[100];

    public:
    Genoma(){
        this->sizeP = 1;
        this->sizeGenoma = 1;
    }

    
    public:
    void readFile(char filename[]){
     
        FILE *file;
        file = fopen(filename, "r");
            
        while(this->sizeP != 0 && this->sizeGenoma != 0){
            fscanf(file, "%d %d %s %s", &this->sizeP, &this->sizeGenoma, this->p, this->genoma);
            if(this->sizeP != 0 && this->sizeGenoma !=0) this->executeGenomaTest();
        }

    }

    void executeGenomaTest(){
        cout << this->genoma << endl;
        string fullstring = std::string(this->genoma);
        int sizeOfP = strlen(this->p);

        int direct = 0;

        for(int i = 0; i < strlen(this->genoma); i++){
            if(fullstring.substr(i, sizeOfP) == this->p){
                cout << i << endl;
                direct++;
            }
        }
    }

    void printGenoma(){
        cout << this->sizeP;
    }

};

int main(){

    char fileName[] = "./genoma.in";
    Genoma genoma;
    genoma.readFile(fileName);

    return 0;
}