#include <iostream>
using namespace std;

FILE *in;

class Image{

    public:
    int x, y;
    int imageQuantity;
    char image[100][100];

    public:
    Image(int x, int y){
        this->x = x;
        this->y = y;
        this->imageQuantity = 0;
    }
    void printMatrix(){
        for(int i = 0; i < this->x; i++){
            for(int j = 0; j < this->y; j++){
                cout << image[i][j];
            }
            cout << endl;
        }
    }

    void runImageDetector(){
        //cout << "MATRIZ INICIAL:" << endl;
        //this->printMatrix();
        
        for(int i = 0; i < this->x; i++){
            for(int j = 0; j < this->y; j++){
                if(this->image[i][j] != '0'){
                    this->recursion(i, j);
                    this->imageQuantity++;
                }
            } 
        }
        cout << "CONSTRUÇOES : " << this->imageQuantity << endl;
    }

    void recursion(int a, int b){
            this->image[a][b] = '0';
            // mudar para um for para passar por todas os adjacentes
            if(a+1 < this->x && b+1 < this->y &&this->image[a+1][b+1] != '0'){
                recursion(a+1, b+1); // diagonal inferior direita
            }
            if(a-1 >= 0 && b-1 >= 0 && this->image[a-1][b-1] != '0'){
                recursion(a-1, b-1); // diagonal superior esquerda
            }
            if(a-1 >= 0 && b+1 < this->y && this->image[a-1][b+1] != '0'){
                recursion(a-1, b+1); // diagonal superior direita
            }
            if(a+1 < this->x && b-1 >= 0 && this->image[a+1][b-1] != '0'){
                recursion(a+1, b-1); // diagonal inferior esquerda
            }
            if(b-1 >= this->y && this->image[a][b-1] != '0'){
                recursion(a, b-1); // esquerda
            }
            if(a-1 >= 0 && this->image[a-1][b] != '0'){
                recursion(a-1, b); // cima
            }
             if(a+1 < this->x && this->image[a+1][b] != '0'){
                recursion(a+1, b);  //baixo
            }
            if(b+1 < this->y && this->image[a][b+1] != '0'){
                recursion(a, b+1); // direita
            }
            

        }
};

int main(){

    in = fopen("./imagem.in", "r");
    int x = 1;
    int y = 1;

    while(x != 0 && y != 0){
        fscanf(in, "%d %d", &x, &y);
        Image image(x, y);
        for(int i = 0; i < x; i++){
            fscanf(in, "%s", image.image[i]);
        }
        image.runImageDetector();
    }

}