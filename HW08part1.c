/*
 * 161044049
 * ALP EMİR BİLEK
 * HW08_PART1
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//DEFINING STRUCT
typedef struct {
    int text;
    int data;
    char type;
    int pos_x;
    int pos_y;
    int jump_x,jump_y;
}block;
//DEFINING MY FUNCTIONS
void init_board(block board[10][10]);
void printf_board(block board[10][10]);
int rules(block board[10][10],int* start,int index[2],int *counter);
int * getIndices(block board[10][10],int data,int index[2]);

int main() {
//RANDOM FUNC FOR THE DICE.
    srand((unsigned int) time(NULL));
    block board[10][10];
    int start = 1;
    int index[2];
    int choise;
    int counter1 = 0;
    int counter2 = 0;
//ASKİNG TO THE USER SINGLE OR MULTIPLAYER BECAUSE DID NOT EXACTLY EXPLAINED ON PDF.
    printf("1.Single\n2.Multiplayer\nChoise:");
    scanf("%d",&choise);
    init_board(board);
    printf_board(board);
//IF USER CHOOSES 1 I CALL THE RULES FUNCTION ONCE
    if(choise==1){
        rules(board,&start,index,&counter1);
    }
//IF USER CHOOSES 2 I CALL THE RULES FUNCTION TWICE
    else if(choise==2) {
        printf("Player1's game:\n");
        rules(board, &start, index, &counter1);
        printf("Player2's game:\n");
        start = 1;
        rules(board, &start, index, &counter2);
//OBTAINING THE WINNER!!!
        if (counter1 < counter2) {
            printf("\nPlayer1 WON!!!!!");
        } else if (counter1 == counter2) {
            printf("\nThe game has been draw!!!!");
        } else {
            printf("\nPlayer2 WON!!!!!");
        }
    }
    return 0;
}
//INITIALIZING FUNCTION.
void init_board(block board[10][10]){
    int i,j,loc=91;
    for(i=0;i<9;i++){
        board[0][i].data=loc;
        loc++;
    }
    loc=90;
    board[0][9].data=100;
    for(i=0;i<9;i++){
        board[1][i].data=loc;
        loc--;
    }
    board[1][9].data=81;
    loc=71;
    for(i=0;i<9;i++){
        board[2][i].data=loc;
        loc++;
    }
    board[2][9].data=80;
    loc=70;
    for(i=0;i<9;i++){
        board[3][i].data=loc;
        loc--;
    }
    board[3][9].data=61;
    loc=51;
    for(i=0;i<9;i++){
        board[4][i].data=loc;
        loc++;
    }
    board[4][9].data=60;
    loc=50;
    for(i=0;i<9;i++){
        board[5][i].data=loc;
        loc--;
    }
    board[5][9].data=41;
    loc=31;
    for(i=0;i<9;i++){
        board[6][i].data=loc;
        loc++;
    }
    board[6][9].data=40;
    loc=30;
    for(i=0;i<9;i++){
        board[7][i].data=loc;
        loc--;
    }
    board[7][9].data=21;
    loc=11;
    for(i=0;i<9;i++){
        board[8][i].data=loc;
        loc++;
    }
    board[8][9].data=20;
    loc=10;
    for(i=0;i<10;i++){
        board[9][i].data=loc;
        loc--;
    }
    board[9][4].type='S';
    board[9][4].text=1;
    board[9][3].type='M';
    board[9][3].text=11;
    board[8][2].type='P';
    board[8][6].type='M';
    board[8][6].text=28;
    board[7][1].type='B';
    board[7][5].type='S';
    board[7][5].text=12;
    board[6][1].type='M';
    board[6][1].text=52;
    board[6][5].type='B';
    board[6][9].type='T';
    board[5][0].type='B';
    board[5][2].type='P';
    board[5][5].type='S';
    board[5][5].text=22;
    board[4][3].type='T';
    board[4][6].type='M';
    board[4][6].text=77;
    board[4][9].type='S';
    board[4][9].text=44;
    board[3][1].type='M';
    board[3][1].text=77;
    board[3][4].type='B';
    board[3][7].type='S';
    board[3][7].text=52;
    board[2][2].type='S';
    board[2][2].text=68;
    board[2][5].type='M';
    board[2][5].text=83;
    board[2][8].type='T';
    board[1][1].type='M';
    board[1][1].text=94;
    board[1][5].type='P';
    board[1][8].type='B';
    board[0][2].type='T';
    board[0][7].type='S';
    board[0][8].type='S';
    board[0][7].text=72;
    board[0][8].text=56;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            board[i][j].pos_x=i;
            board[i][j].pos_y=j;
        }
    }
    board[9][4].jump_x=9;
    board[9][4].jump_y=4;
    board[9][3].jump_x=8;
    board[9][3].jump_y=0;
    board[8][6].jump_x=7;
    board[8][6].jump_y=2;
    board[7][1].jump_x=7;
    board[7][1].jump_y=6;
    board[7][5].jump_x=8;
    board[7][5].jump_y=1;
    board[6][1].jump_x=4;
    board[6][1].jump_y=1;
    board[6][5].jump_x=5;
    board[6][5].jump_y=9;
    board[6][9].jump_x=6;
    board[6][9].jump_y=4;
    board[5][0].jump_x=5;
    board[5][0].jump_y=5;
    board[5][5].jump_x=7;
    board[5][5].jump_y=8;
    board[4][3].jump_x=6;
    board[4][3].jump_y=8;
    board[4][6].jump_x=2;
    board[4][6].jump_y=6;
    board[4][9].jump_x=5;
    board[4][9].jump_y=6;
    board[3][1].jump_x=2;
    board[3][1].jump_y=6;
    board[3][4].jump_x=3;
    board[3][4].jump_y=9;
    board[3][7].jump_x=4;
    board[3][7].jump_y=1;
    board[2][2].jump_x=3;
    board[2][2].jump_y=2;
    board[2][5].jump_x=1;
    board[2][5].jump_y=7;
    board[2][8].jump_x=2;
    board[2][8].jump_y=3;
    board[1][1].jump_x=0;
    board[1][1].jump_y=3;
    board[1][8].jump_x=0;
    board[1][8].jump_y=3;
    board[0][2].jump_x=1;
    board[0][2].jump_y=7;
    board[0][6].jump_x=2;
    board[0][6].jump_y=1;
    board[0][7].jump_x=4;
    board[0][7].jump_y=5;

}
//OBTAINING THE CURRENT INDEXES OF ARRAY.
int * getIndices(block board[10][10],int data,int index[2]){
    int i = 0;
    int j = 0;
    for(i = 0; i<10; ++i){
        for(j = 0; j<10; ++j){
            if(board[i][j].data == data){
                index[0] = i;
                index[1] = j;
            }
        }
    }
    return index;
}
//PRINTING FUNCTION.
void printf_board(block board[10][10]){
    init_board(board);
    int i,j;
    board[9][1].type = 9;
    board[9][8].type = 2;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(board[i][j].type=='M'){
                printf("%c{%d} ",board[i][j].type,board[i][j].text);
            }
            else if(board[i][j].type=='S'){
                printf("%c{%d} ",board[i][j].type,board[i][j].text);
            }
            else if(board[i][j].type=='P'){
                printf("%c    ",board[i][j].type);
            }
            else if(board[i][j].type=='B'){
                printf("%c    ",board[i][j].type);
            }
            else if(board[i][j].type=='T'){
                printf("%c    ",board[i][j].type);
            }
            else if(board[i][j].data==100){
                printf("%d(finish)",board[i][j].data);
            }
            else if(board[i][j].data==1){
                printf("%d(start)",board[i][j].data);
            }
            else{
                if(board[i][j].data<10){
                    printf("%d     ",board[i][j].data);
                }
                else{
                    printf("%d    ",board[i][j].data);
                }
            }
        }
        printf("\n\n");
    }
}
//RULES OF GAME RECURSION FUNCTION.
int rules(block board[10][10],int * start,int index[2],int *counter){
    int diceVal = rand()%6 + 1;;
//OBTAINING THE CURRENT INDECEES
    getIndices(board,*start,index);
    printf("Current location: %d %d    Dice:%d\n",board[index[0]][index[1]].pos_x,board[index[0]][index[1]].pos_y,diceVal);
    *start += diceVal;
    (*counter)++;
//THE BASE CASE.
    if(*start == 100){
        *counter += 1;
        printf("----------------CONGRATULATION------------------\n");
        printf("YOU WON!!\nDICE COUNT = %d\n",*counter);
        return (*counter);
    }
    else {
        if(*start < 100){
            getIndices(board,*start,index);
            if(board[index[0]][index[1]].type == 'M'){
                *start = board[index[0]][index[1]].text;
            }
            else if(board[index[0]][index[1]].type == 'S'){
                *start = board[index[0]][index[1]].text;
            }
            else if(board[index[0]][index[1]].type == 'P'){
                *start -= diceVal;
            }
            else if(board[index[0]][index[1]].type == 'B'){
                *start += 5;
            }
            else if(board[index[0]][index[1]].type == 'T'){
                *start -=5;
            }
            return(rules(board,start,index,counter));
        }
        else{
            *start -= diceVal;
            return rules(board,start,index,counter);
        }
    }
}