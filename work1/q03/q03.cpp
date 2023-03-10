#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    int x;
    int y;
    int u;
    int v;
} Area;

class Monkey {

    private:
    int areaAmount;
    int iteration;
    vector<Area> areas;
    vector<Area> result;

    public:
    Monkey(){
        areaAmount = -1;
        iteration = 1;
        createOrClearFile();
        readFile();
    }

    private:
    void createOrClearFile(){
        FILE *out;
        out = fopen("./macaco.out", "w");
        fclose(out);
    }

    void readFile(){
        FILE *in, *out;
        in = fopen("./macaco.in", "r");
        out = fopen("./macaco.out", "a");
        while(fscanf(in, "%d", &areaAmount) && areaAmount != 0){
            for( int c = 0; c < areaAmount; c++ ){
                Area area;
                fscanf(in, "%d %d %d %d", &area.x, &area.y, &area.u, &area.v);
                areas.push_back(area);
            }
            findIntersection();
            printFile(out);
            areas.clear();
            result.clear();
            iteration++;
        }
        fclose(in);
    }

    void findIntersection(){
        int currentX, currentY, currentU, currentV;
        Area solutionArea;
        solutionArea.x = -1;
        solutionArea.y = -1;
        solutionArea.u = -1;
        solutionArea.v = -1;

        for(int c = 0; c < areaAmount; c++){
            currentX = areas[c].x;
            currentY = areas[c].y;
            currentU = areas[c].u;
            currentV = areas[c].v;

            if(isInsideAllX(currentX)) {
                solutionArea.x = currentX;
            }
            if(isInsideAllY(currentY)) {
                solutionArea.y = currentY;
            }
            if(isInsideAllU(currentU)) {
                solutionArea.u = currentU;
            }
            if(isInsideAllV(currentV)) {
                solutionArea.v = currentV;
            }
        }
        result.push_back(solutionArea);
        verifySolution();
    }

    void verifySolution(){
        int x = result[0].x;
        int y = result[0].y;
        int u = result[0].u;
        int v = result[0].v;

        for( int c = 0; c < areaAmount; c++){
            if(x > areas[c].u ) result[0].x = -1;
            if(v > areas[c].y ) result[0].v = -1;
        }

    }

    bool isInsideAllX(int cx){
        bool isInsideAll = 1;
        for(int c = 0; c < areaAmount; c++){
            if( !(cx >= areas[c].x ) ) isInsideAll = 0;
        }
        return isInsideAll;
    }

    bool isInsideAllY(int cy){
        bool isInsideAll = 1;
        for(int c = 0; c < areaAmount; c++){
            if( !( cy <= areas[c].y) ) isInsideAll = 0;
        }
        return isInsideAll;
    }

    bool isInsideAllU(int cu){
        bool isInsideAll = true;
        for(int c = 0; c < areaAmount; c++){
            if( !( cu <= areas[c].u) ) isInsideAll = false;
        }
        return isInsideAll;
    }
    bool isInsideAllV(int cv){
        bool isInsideAll = true;
        for(int c = 0; c < areaAmount; c++){
            if( !( cv >= areas[c].v) ) isInsideAll = false;
        }
        return isInsideAll;
    }

    void printFile(FILE *out){
        fprintf(out, "Teste %d\n", iteration);
        if(result[0].x == -1 || result[0].y == -1 || result[0].u == -1 || result[0].v == -1)
            fprintf(out, "nenhum\n");
        else
            fprintf(out, "%d %d %d %d\n", result[0].x, result[0].y, result[0].u, result[0].v);
        fprintf(out, "\n");
    }
};

int main(){
    Monkey monkey;
    return 0;
}
