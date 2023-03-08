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
        FILE *in;
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
        cout << "Teste " << iteration << endl << this->sortedPerson << endl << endl;
    }
};

int main(){


    Quermesse quermesse;
}