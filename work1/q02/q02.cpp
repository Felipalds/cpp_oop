#include <iostream>
using namespace std;

class Bit {

    public:
    int bitcoin;
    int fifty;
    int ten;
    int five;
    int one;
    int iteration;
    Bit(){
        this->bitcoin = -1;
        this->iteration = 0;
        this->readStdin();
    }

    private:
    void readStdin(){
        FILE *in , *out;
        out = fopen("./bit.out", "w");
        fclose(out);
        in = fopen("./bit.in", "r");

        while(fscanf(in, "%d", &this->bitcoin) && this->bitcoin != 0){
            this->iteration++;
            this->processCoin();
            this->printStdout();
        }
    }

    void processCoin(){
        int coin = this->bitcoin;
        this->fifty = 0;
        this->ten = 0;
        this->five = 0;
        this->one = 0;
        while(coin >= 50){
            this->fifty++;
            coin -= 50;
        }
        while(coin >= 10){
            this->ten++;
            coin -= 10;
        }
        while(coin >= 5){
            this->five++;
            coin -= 5;
        }
        while(coin >= 1){
            this->one++;
            coin--;
        }
    }

    void printStdout(){
        FILE *out;
        out = fopen("./bit.out", "a");
        fprintf(out, "Teste %d\n", this->iteration);
        fprintf(out, "%d %d %d %d\n\n", this->fifty, this->ten, this->five, this->one);
        fclose(out);
    
    }
};

int main(){
    Bit bit;

    return 0;
}