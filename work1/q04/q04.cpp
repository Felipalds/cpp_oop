#include <iostream>
using namespace std;

class Metheor {

    public:
    int x1, y1, x2, y2, total, teste;

    public:
    Metheor(){
        this->teste = 1;
        this->x1 = -1;
        this->y1 = -1;
        this->x2 = -1;
        this->y2 = -1;
        this->total = 0;
        this->readFile();
    }

    private:
    void readFile(){
        FILE *in, *out;
        int metheorAmount = 0;
        int xi, yi;
        in = fopen("./meteoros.in", "r");
        out = fopen("./meteoros.out", "w");
        fclose(out);
        while(fscanf(in, "%d %d %d %d", &this->x1, &this->y1, &this->x2, &this->y2) &&
             (this->x1 != 0 && this->y1 != 0 && this->x2 != 0 && this->y2 != 0)){
            fscanf(in, "%d", &metheorAmount);
            for(int i = 0; i <= metheorAmount - 1; i++){
                fscanf(in, "%d %d", &xi, &yi);
                this->validatePoint(xi, yi);
            }
            this->writeFile();
            this->total = 0;
            this->teste++;
            
        }
        fclose(in);
    }

    void writeFile(){
        FILE *out;
        out = fopen("./meteoros.out", "a");
        fprintf(out, "Teste %d\n", this->teste);
        fprintf(out, "%d\n\n", this->total);
        fclose(out);
    }

    void validatePoint(int xi, int yi){
        if(xi >= this->x1 && xi <= this->x2 && yi <= this->y1 && yi >= this->y2){
            this->total++;
        }
    }
    
    void printArea(){
        cout << this->x1 << " " << this-> y1 << " " << this->x2 << " " << this->y2 << endl;
    }

};

int main(){
    Metheor metheor;
}