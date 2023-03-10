#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    int start;
    int end;
} IceRange;

class Icecream{

    private:
    int beachLength;
    int iceCreamAmount;
    int iteration;
    vector<IceRange> solutions;
    vector<IceRange> finalSolutions;

    public:
    Icecream(){
        beachLength = -1;
        iceCreamAmount = -1;
        iteration = 1;
        createOrClearFile();
        readFile();
    }

    private:
    void createOrClearFile(){
        FILE *out;
        out = fopen("./sorvete.out", "w");
        fclose(out);
    }

    void readFile(){
        FILE *in, *out;
        in = fopen("./sorvete.in", "r");
        out = fopen("./sorvete.out", "a");
        while(fscanf(in, "%d %d", &beachLength, &iceCreamAmount) && beachLength != 0 && iceCreamAmount != 0){
            for(int c = 0; c < iceCreamAmount; c++){
                readEntries(in);
            }
            findSolution();
            solutions.clear();
            printFinalSolutions(out);
            finalSolutions.clear();
            iteration++;
        }
        fclose(in);
    }

    void readEntries(FILE *in){
        int start, end;
        fscanf(in, "%d %d", &start, &end);
        IceRange currentSolution;
        currentSolution.start = start;
        currentSolution.end = end;
        solutions.push_back(currentSolution);
    }

    void printSolutions(){
        for(int c = 0; c < solutions.size(); c++){
            cout << solutions[c].start << " " << solutions[c].end << endl;
        }
    }
    void printFinalSolutions(FILE *in){
        fprintf(in, "Teste %d\n", iteration);

        for(int c = 0; c < finalSolutions.size(); c++){
            fprintf(in, "%d %d\n", finalSolutions[c].start, finalSolutions[c].end);
        }
        fprintf(in, "\n");
    }

    void findSolution(){
        while(solutions.size() > 0){
            int currentStart, currentEnd;
            int index = findMinorRange();
            if(solutions.size() == iceCreamAmount){
                currentStart = solutions[index].start;
                currentEnd = solutions[index].end;
            } else {
                if(
                    solutions[index].start <= currentEnd && 
                    solutions[index].end >= currentEnd
                ){
                    currentEnd = solutions[index].end;
                }
                if(solutions[index].start >= currentEnd){
                    insertFinalSolution(currentStart, currentEnd);
                    currentStart = solutions[index].start;
                    currentEnd = solutions[index].end;
                }
            }
            solutions.erase(solutions.begin() + index);
            if(solutions.size() == 0) insertFinalSolution(currentStart, currentEnd);
        }
    }

    int findMinorRange(){
        int minor = 9999;
        int index = -1;
        for (int c = 0; c < solutions.size(); c++){
            if(solutions[c].start < minor){
                minor = solutions[c].start;
                index = c;
            }
        }
        return index;
    }

    void insertFinalSolution(int start, int end){
        IceRange currentFinalSolution;
        currentFinalSolution.start = start;
        currentFinalSolution.end = end;
        finalSolutions.push_back(currentFinalSolution);
    }
};

int main(){

    Icecream icecream;

    return 0;
}