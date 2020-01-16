/*#HW09
 * ALP EMİR BİLEK
 * 161044049
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//DEFINING THE STRUCTS.
typedef struct{
    char **map;
    int height;
    int width;
    int Flower_x;
    int Flower_y;
}Forest;
typedef struct {
    int coord_x;
    int coord_y;
    int water_bottle_size;
}Botanist;
//DEFINING THE FUNCTIONS.
void init_game (Forest *forest, Botanist *botanist);
void print_map (Forest *forest);
void search(Forest *forest,Botanist *botanist);
int * getIndices(Forest *forest,char data,int index[2]);
int main() {
    //DEFINING THE VARIABLES.
    int i = 0;
    Forest *forest;
    Botanist *botanist;
    //PROCESS OF MALLOCS.
    botanist=(Botanist*)malloc(sizeof(Botanist));
    forest=(Forest*)malloc(sizeof(Forest));
    forest->map=(char**)malloc(10*sizeof(char*));
    for(i=0;i<10;i++){
        forest->map[i]=(char*)malloc(sizeof(char)*10);
    }
    srand(time(NULL));
    //CALLING THE GAME FUNCTIONS.
    init_game(forest,botanist);
    print_map(forest);
    printf("Searching...\n");
    search(forest,botanist);
    int indexb[2];
    getIndices(forest,'B',indexb);
    if(botanist->water_bottle_size == 0){
        print_map(forest);
        printf("Help!! I am on (%d,%d)",botanist->coord_x,botanist->coord_y);
    }
    else if(forest->map[botanist->coord_x][botanist->coord_y] == 'F'){
        forest->map[botanist->coord_x][botanist->coord_y]='F';
        forest->map[indexb[0]][indexb[1]]=' ';
        print_map(forest);
        printf("I have found it on (%d,%d)!!\n",forest->Flower_x,forest->Flower_y);
    }
    return 0;
}
//INITIALIZING FUNCTIONS.
void init_game (Forest *forest, Botanist *botanist){
    int i = 0;
    int j = 0;
    char **map=(char**)malloc(10*sizeof(char*));
    for ( i = 0; i < 10; ++i)
        map[i] = (char *) malloc(sizeof(char) * 20);
    i=0;
    //READING FROM THE TXT FILE.
    FILE * fp;
    fp = fopen("init.txt","r");
    fscanf(fp,"%d\n%d,%d\n",&botanist->water_bottle_size,&forest->height,&forest->width);
    char file;
    while(!(feof(fp)) ){
        for(j = 0; j<forest->width*2; ++j){
            file = fgetc(fp);
            map[i][j] = file;
        }
        ++i;
        if(i == forest->height){
            break;
        }
    }
    fclose(fp);
    for(i = 0; i<forest->height; ++i){
        for(j=0; j<forest->width*2; ++j){
            if(map[i][j]!=','){
                forest->map[i][(j+1)/2]=map[i][j];
            }
        }
    }
}
//PRINTING THE MAP.
void print_map (Forest *forest){
    int i,j;
    for(i=0;i<forest->height;i++){
        for(j=0;j<forest->width;j++){
            printf("%c",forest->map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//FINDING THE CURRENT INDICES.
int * getIndices(Forest *forest,char data,int index[2]){
    int i = 0;
    int j = 0;
    for(i = 0; i<10; ++i){
        for(j = 0; j<10; ++j){
            if(forest->map[i][j] == data){
                index[0] = i;
                index[1] = j;
            }
        }
    }
    return index;
}
//TRYING THE FINDING THE FLOWER.
void search(Forest *forest, Botanist *botanist){
    //WALKING ACOORDING THE RANDOM DIRECTIONS.
    int random=rand()%4;
    int indexb[2];
    int indexf[2];
    getIndices(forest,'F',indexf);
    getIndices(forest,'B',indexb);
    botanist->coord_x=indexb[0];
    botanist->coord_y=indexb[1];
    forest->Flower_x=indexf[0];
    forest->Flower_y=indexf[1];
    if(botanist->water_bottle_size==0){
        return;
    }
    if(random==0){//FOR 0;
        if(botanist->coord_y == 9){//FOR 9
            search(forest,botanist);
        }
        else{
            if(forest->map[botanist->coord_x][botanist->coord_y+1]=='#'){
                search(forest,botanist);
            }
            else{
                if(botanist->coord_y!=9){//FOR 9
                    if(forest->map[botanist->coord_x][botanist->coord_y+1]!='F') {
                        forest->map[botanist->coord_x][botanist->coord_y + 1] = 'B';
                        forest->map[botanist->coord_x][botanist->coord_y] = ' ';
                        botanist->coord_y++;
                        botanist->water_bottle_size--;
                        search(forest, botanist);
                    }
                    else{
                        botanist->coord_y++;
                    }
                }
                else{
                    search(forest,botanist);
                }
            }
        }
    }
    else if(random==1){//FOR 1.
        if(botanist->coord_y == 0){//FOR 0
            search(forest,botanist);
        }
        else{
            if(forest->map[botanist->coord_x][botanist->coord_y-1]=='#'){
                search(forest,botanist);
            }
            else {
                if(forest->map[botanist->coord_x][botanist->coord_y-1]!='F'){
                    forest->map[botanist->coord_x][botanist->coord_y-1]='B';
                    forest->map[botanist->coord_x][botanist->coord_y]=' ';
                    botanist->coord_y--;
                    botanist->water_bottle_size--;
                    search(forest,botanist);
                }
                else{
                    botanist->coord_y--;
                }
            }
        }
    }
    else if(random==2){//FOR 2
        if(botanist->coord_x == 9){//FOR 9
            search(forest,botanist);
        }
        else{
            if(forest->map[botanist->coord_x+1][botanist->coord_y]=='#'){
                search(forest,botanist);
            }
            else{
                if(forest->map[botanist->coord_x+1][botanist->coord_y]!='F') {
                    forest->map[botanist->coord_x+1][botanist->coord_y]='B';
                    forest->map[botanist->coord_x][botanist->coord_y] = ' ';
                    botanist->coord_x++;

                    botanist->water_bottle_size--;
                    search(forest, botanist);
                }
                else{
                    botanist->coord_x++;
                }
            }
        }
    }
    else if(random==3){//FOR 3
        if(botanist->coord_x == 0){//FOR 0
            search(forest,botanist);
        }
        else{
            if(forest->map[botanist->coord_x-1][botanist->coord_y]=='#'){
                search(forest,botanist);
            }
            else {
                if(forest->map[botanist->coord_x-1][botanist->coord_y]!='F') {
                    forest->map[botanist->coord_x - 1][botanist->coord_y] = 'B';
                    forest->map[botanist->coord_x][botanist->coord_y] = ' ';
                    botanist->coord_x--;
                    botanist->water_bottle_size--;
                    search(forest, botanist);
                }
                else{
                    botanist->coord_x--;
                }
            }
        }
    }
    if(forest->map[botanist->coord_x][botanist->coord_y]=='F'){
        return;
    }
}