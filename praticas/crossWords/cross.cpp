#include <iostream>
#include <vector>
using namespace std;

FILE *in;

class CrossWord {

    public:
    int x;
    int y;
    char cross[100][100];
    vector<string> horizontals;
    vector<string> verticals;

    public:
    CrossWord(int x, int y){
        this->x = x;
        this->y = y;
    }

    void scanWords(){
        for(int i = 0; i < this->x; i++){
            for(int j = 0; j < this->y; j++){
                this->verifyNumeralSquare(i, j);
            }
        }
    }
    void findRightWord(int x, int y){
        cout << "FINDING RIGHT " << endl;
        int i = x;
        int j = y;
        int c = 0;
        char word [100];
        while(j <= this->y && this->cross[i][j] != '*'){
            word[c] = this->cross[i][j];
            j++;
            c++;
        }
        word[c] = '\0';
        cout << word;
        this->horizontals.push_back(string(word));
    }

    void findDownWord(int x, int y){
        cout << "FINDING DOWN " << endl;
        int i = x;
        int j = y;
        int c = 0;
        char word [100];
        while(x <= this->x && this->cross[i][j] != '*'){
            word[c] = this->cross[i][j];
            j++;
            c++;
        }
        word[c] = '\0';
        cout << word;
        this->verticals.push_back(string(word));
    }

    void verifyNumeralSquare(int x, int y){
        cout << x << " " << y;
        if(this->cross[x][y] != '*'){
            if(y-1 < 0){
                if(this->cross[x][y+1] != '*'){
                    this->findRightWord(x, y);
                }
            } else {
                if(this->cross[x][y - 1] == '*'){
                    if(y+1 != '*'){
                        this->findRightWord(x, y);
                    }
                }
            }
            if(x-1 < this->x){
                if(this->cross[x+1][y] != '*'){
                    this->findDownWord(x, y);
                }
            } else {
                if(this->cross[x-1][y] == '*'){
                    this->findDownWord(x, y);
                }
            }
        }
    }

    void printCross(){
        for(int i = 0; i < this->x; i++){
            cout << this->cross[i] << endl;
        }
    }

    void printHorizontals(){
        cout << this->horizontals.size();
        for(int i = this->horizontals.size() - 1; i > 0; i--){
            cout << horizontals[i];
        }
    }
    void printVerticals(){
        cout << this->verticals.size();
        for(int i = this->verticals.size() - 1; i > 0; i--){
            cout << verticals[i];
        }
    }
};


int main(){

    in = fopen("./cruz.in", "r");
    int x = 1;
    int y = 1;

    while(x != 0 && y != 0){
        fscanf(in, "%d %d", &x, &y);
        cout << x << " " << y << endl;
        CrossWord crossword(x, y);
        for(int i = 0; i < x; i++){
            fscanf(in, "%s", crossword.cross[i]);
        }
        crossword.scanWords();
        //crossword.printCross();
        //cout << crossword.horizontals[0];
        crossword.printHorizontals();
        crossword.printVerticals();

    }
}