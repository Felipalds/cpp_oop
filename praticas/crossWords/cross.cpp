#include <iostream>
#include <vector>
using namespace std;

FILE *in;

typedef struct{
    string word;
    int position;
} Word;

class CrossWord {

    public:
    int x;
    int y;
    int position;
    char cross[100][100];
    vector<Word> horizontals;
    vector<Word> verticals;

    public:
    CrossWord(int x, int y){
        this->x = x;
        this->y = y;
        this->position = 0;
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
        Word structWord;
        structWord.word = string(word);
        cout << structWord.word << endl;
        structWord.position = this->position;
        this->horizontals.push_back(structWord);
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
        Word structWord;
        structWord.word = string(word);
        cout << structWord.word << endl;
        structWord.position = this->position;
        this->verticals.push_back(structWord);
    }

    void verifyNumeralSquare(int x, int y){
        cout << x << y << endl;
        if(this->cross[x][y] != '*'){
            if(y-1 < 0 && (this->cross[x][y+1] != '*')) this->findRightWord(x, y);
            if(this->cross[x][y-1] == '*' && (this->cross[x][y+1] != '*')) this->findRightWord(x ,y);
            if(x-1 < 0 && (this->cross[x+1][y] != '*')) this->findDownWord(x, y);
            if(this->cross[x-1][y] == '*' && (this->cross[x+1][y] != '*')) this->findDownWord(x, y);
        }
    }

    void printCross(){
        for(int i = 0; i < this->x; i++){
            cout << this->cross[i] << endl;
        }
    }

    void printHorizontals(){
        cout << "Printing horizontals " << endl;
        cout << this->horizontals.size() << endl;
        for(int i = 0; i < this->horizontals.size(); i++){
            cout << this->horizontals[i].position << endl << this->horizontals[i].word << endl;
        }
    }
    void printVerticals(){
        cout << "Printing verticals " << endl;
        cout << this->verticals.size() << endl;
        for(int i = 0; i < this->verticals.size(); i++){
            cout << this->horizontals[i].position << endl << this->horizontals[i].word << endl;
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
        cout << "=-=-=-=-=-=-=-=-=-=-=" << endl;
        crossword.printHorizontals();
        crossword.printVerticals();

    }
}