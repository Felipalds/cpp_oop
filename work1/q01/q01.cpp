#include <iostream>
using namespace std;

class Quermesse {
    public:
        int peopleAmount;
        int sortedPerson;

    public:
    Quermesse(){
        this->peopleAmount = -1;
        this->readStdin();
    }



    private:
    void readStdin(){
        FILE *in, *out;
        out = fopen("./quermesse.out", "w");
        fclose(out);
        in = fopen("./quermesse.in", "r");
        int iteration = 1;
        while(fscanf(in, "%d", &peopleAmount) && this->peopleAmount != 0){
            int x;
            for(int i = 1; i <= this->peopleAmount; i++){
                fscanf(in, "%d", &x);
                if(x == i) this->sortedPerson = i;
            }
        this->printStdout(iteration);
        iteration++;
        }
    }

    void printStdout(int iteration){
        FILE *out;
        out = fopen("./quermesse.out", "a");
        fprintf(out, "Teste %d\n", iteration);
        fprintf(out, "%d\n\n", this->sortedPerson);
        fclose(out);
    }
};

int main(){

    Quermesse quermesse;

    return 0;
}