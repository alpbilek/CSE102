/*
#HW10

ALP EMİR BİLEK

161044049


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//DEFINING STURCTURE.
struct Node{
    int data;
    struct Node *next;
};
//DEFINING FUNCTIONS.
int is_prime(int num);
void primelinkedlist();
int readline(FILE *fp);
void primearray(int *a);
int main() {
    int *a=(int*)malloc(sizeof(int)*1000000);
	//WARNING THE USER FOR TİME.
	printf("Reading and Writing to Files!!!\nPlease Wait a Sec...\n");
	printf("This process takes approximetly a minute.");
	//CALLING THE PRIME FUNCTIONS.
	primelinkedlist();
	primearray(a);
}
int readline(FILE *fp) {
//THIS FUNCTION READS DATAS FROM FILE.
    int b;
    fscanf(fp, "%d,00\n", &b);
    return b;
}
void primearray(int *a){
//THIS FUNCTION FINDS THE PRIME NUMBERS WITH ARRAY
    FILE *fp;
    fp=fopen("data.txt","r");
    FILE *np;
    np=fopen("output_even_dynamic_array.txt","w");
    int i=0,j=0,counter=0,counter1=0,upper=1000000;
    clock_t start,end1,end2,end3;
    start=clock();
    for(i=0;i<upper;i++){
        a[i]=readline(fp);
     	if(is_prime(a[i])){
     		fprintf(np,"%d\n",a[i]);
     	}
        if(a[i]==500000){
			end1=clock();
		}
		else if(a[i]==750000){
			end2=clock();
		}
		else if(a[i]==1000000){
			end3=clock();
		}
		counter=0;
	}
		float diff1= (((float)end1 - (float)start) / 1000000.0F ) * 1000;
		float diff2= (((float)end2 - (float)start) / 1000000.0F ) * 1000;
		float diff3= (((float)end3 - (float)start) / 1000000.0F ) * 1000;
		fprintf(np,"500.000 için=%.2f\n750.000 için=%.2f\n1.000.000 için=%2.f",diff1,diff2,diff3);
}
void primelinkedlist(){
//THIS FUNCTION FINDS THE PRIME NUMBERS WITH LINKED LIST	
	struct Node *root;
	root=(struct Node*)malloc(sizeof(struct Node)*10);	
	FILE *sp;
	sp=fopen("data.txt","r");
	FILE *tp;
	tp=fopen("output_even_LiknedList.txt","w");
	int i=0,j=0,counter=0,counter1=0,upper=1000000;
    clock_t start,end1,end2,end3;
    start=clock();
    for(i=0;i<upper;i++){
        root->data=readline(sp);
       if(is_prime(root->data)){
     		fprintf(tp,"%d\n",root->data);
     	}
		if(root->data==500000){
			end1=clock();
		}
		else if(root->data==750000){
			end2=clock();
		}
		else if(root->data==1000000){
			end3=clock();
		}
		counter=0;
    }	
	float diff1= (((float)end1 - (float)start) / 1000000.0F ) * 1000;
	float diff2= (((float)end2 - (float)start) / 1000000.0F ) * 1000;
	float diff3= (((float)end3 - (float)start) / 1000000.0F ) * 1000;
    fprintf(tp,"500.000 için=%.2f\n750.000 için=%.2f\n1.000.000 için=%2.f",diff1,diff2,diff3);
}
int is_prime(int num)
{
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i < num / 2; i+= 2)
     {
         if (num % i == 0)
             return 0;
     }
     return 1;
}
