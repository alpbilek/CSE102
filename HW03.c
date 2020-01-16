//#HW03
//ALP EMIR BILEK
//161044049
#include <stdio.h>
#include <stdlib.h>
//DEFINING FUNCTIONS.
void menu();
int getInt(int mini, int maxi);
int numberGeneratorBetweenRange(int min, int max);
void horseRacingGame();
void countOccurrence();
void triangleOfSequences();
int main() {
//CALLING THE MENU FUNCTION
    menu();
    return 0;
}
void menu(){
//PRINTING THE MENU.
    int choise,k;
    printf("1. Horse Racing Game\n");
    printf("2. Occurrence Counter\n");
    printf("3. Triangle of Sequences\n");
    printf("0. Exit\n ");
    k=1;
    do{
//CALLING THE getInt FUNCTION.
        choise=getInt(0,3);
        switch(choise){
            case 1:
                horseRacingGame();
                break;
            case 2:
                countOccurrence();
                break;
            case 3:
                triangleOfSequences();
                break;
            case 0:
                k=0;
                break;
        }
    }while(k==1);
}
int getInt(int mini, int maxi){
//IF THE VARIABLE IS NOT IN RANGE ,THIS FUNCTION ASKS AGAIN UNTIL USER ENTER THE AVAIBLE VALUE.
    int x,flag=0;
    do{
        scanf("%d",&x);
        if(x>=mini && x<=maxi){
            flag=1;
        }
        else{
            printf("Try again please\n");
        }
    }while(flag==0);
    return x;
}
int numberGeneratorBetweenRange(int min, int max){
//RANDOMIZE THE VALUES FOR THE VARIABLES.
    int y;
    y=rand() %(max-min+1);
    y=y+min;

    return y;
}
void horseRacingGame(){
//PLAYS A HORSERACING GAME.
    int horsetime,horsenum,winner,i,j,min=20,guess;
    horsenum=numberGeneratorBetweenRange(3,5);
    printf("Number of Horse:%d\n",horsenum);
    printf("Horse Number:");
    guess=getInt(1,horsenum);
    printf("Racing starts...\n");
    for(i=1;i<=horsenum;i++){
        horsetime=numberGeneratorBetweenRange(10,20);
        printf("Horse%d:",i);
        if(horsetime<=min){
            min=horsetime;
            winner=i;
        }

        for(j=1;j<=horsetime;j++){
            printf("-");
        }
        printf("\n");
    }
    if(guess==winner){
        printf("You win! Winner is Horse %d.",winner);
    }
    else{
        printf("You lose! Winner is Horse %d.",winner);
    }
}
void countOccurrence(){
//THIS FUNCTION ASKS FROM USER BIG NUMBER AND SEARCH NUMBER AND CALCULATES THE HOW MANY SEARCH NUMBERS HAVE BEEN IN BIG NUMBER.
    int num,search,b,last_digit,temp,temp2,bigtemp,search_temp,i;
    int counter=0;
    int sum=1;
    int counter1=0;
    printf("Big Number:\n");
    scanf("%d",&num);
    printf("Search Number:\n");
    scanf("%d",&search);
    temp = search;
    search_temp = search;
    bigtemp = num;
    if(temp==0){
        counter=1;
    }
    else{
        while(temp > 0){
            temp = temp / 10;
            counter++;
        }
    }
    for(i=0;i<counter;i++){
        sum=10*sum;
    }
    temp2 = sum;
    while(bigtemp > 0){
        b = bigtemp % temp2;
        last_digit = bigtemp % 10;
        bigtemp = (bigtemp - last_digit) / 10;
        if(b == search_temp){
            counter1++;
        }
    }
    printf("Occurrence:%d\n",counter1);
}
void triangleOfSequences(){
//PRINTS  TRIAGLE OF SEQUENCES.
    int n,j,i,sum=0;
    n=numberGeneratorBetweenRange(2,10);
    printf("Output (for %d)\n",n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            sum=j*i;
            printf("%d",sum);
            printf(" ");
        }
        printf("\n");
    }
}