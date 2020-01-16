//HW06
//ALP EMIR BILEK
//161044049
//Hocam encrypt yaparken bosluk yerine y basıyorum.
//ve decrypt yaparken de bosluk yerine d basıyorum.
#include<stdio.h>
//DEFINING THE FUNTIONS.
void menu();
void encrypt_open_msg();
void decrypt_secret_msg();
int find_size_of_line(char line[]);
void reverse_line(char line[], int line_lenght);
int main(){
//CALLING THE MENU FUNCTION.
	menu();
}

int find_size_of_line(char line[]){
//FINDING THE SIZE OF A LINE.
	int size = 0;
	while(line[size] != '\0'){
		size++;
	}
	return size;
}

void reverse_line(char line[], int line_lenght){
//REVERSING THE A LINE.
	int i,j;
	char line2[line_lenght];
	for(i = 0,j=line_lenght-1; i<line_lenght;j--,i++){
		line2[i] = line[j];
	}
	for(i=0;i<line_lenght;i++){
		line[i]=line2[i];
	}
}
void encrypt_open_msg(){
//ENCRYPTING...
	int i = 0,j=0;
	char str[100][1000];	
	FILE *fp;
	FILE *fp2;
	int size,key;
//ASKING A KEY FROM USER.
	printf("Enter a key pls:");
	scanf("%d",&key);
//CHECKING THE KEY WHETHER BEING POSITIVE OR NEGATIVE.
	if(key<0){
		key=key*-1;
	}
//READING THE LINES FROM FILE.
	fp=fopen("open_msg.txt","r");
	fgets(str[i],1000,fp);
	reverse_line(str[i],find_size_of_line(str[i]));
	for(j=0;j<find_size_of_line(str[i]);j++){
			if(str[i][j]==46){
				str[i][j]=42;
			}			
			else if(str[i][j]==32){
				str[i][j]=95;
			}
			else {
				str[i][j]=str[i][j]-key;
			}
			if((str[i][j])<97){
				str[i][j] = str[i][j] + 26;
			}
		}
//PRINTING FIRST LINE.
	fp2 = fopen("secret_msg.txt","w");
	fprintf(fp2,"%s\n",str[i]);
//SAME PROCESSES FOR OTHER LINES.
	while(fgets(str[i],100,fp)!= NULL){	
		reverse_line(str[i],find_size_of_line(str[i]));
		for(j=0;j<find_size_of_line(str[i]);j++){
			if(str[i][j]==46){
				str[i][j]=42;
			}			
			else if(str[i][j]==32){
				str[i][j]=95;
			}
			else {
				str[i][j]=str[i][j]-key;
			}
			if((str[i][j])<97){
				str[i][j] = str[i][j] + 26;
			}
		}
		fprintf(fp2,"%s\n",str[i]);
		i++;		
	}	
	fclose(fp);
	fclose(fp2);
}
void decrypt_secret_msg(){
//DECRYTPING...
	int i = 0,j=0;
	char str[100][1000];	
	FILE *fp;
	FILE *fp2;
	int size,key;
//ASKING A KEY FROM USER.
	printf("Enter a key pls:");
	scanf("%d",&key);
	if(key<0){
		key=key*-1;
	}
//READING THE LINES FROM FILE.
	fp=fopen("secret_msg.txt","r");
	fgets(str[i],1000,fp);
	reverse_line(str[i],find_size_of_line(str[i]));	
	for(j=0;j<find_size_of_line(str[i]);j++){
			if(str[i][j]==42){
				str[i][j]=46;
			}			
			else if(str[i][j]==95){
				str[i][j]=32;
			}
			else {
				str[i][j]=str[i][j]+key;
			}
			if(str[i][j]>122){
				str[i][j] = str[i][j] - 26;
			}
		}
//PRINTING FIRST LINE.
	fp2 = fopen("open_msg.txt","w");
	fprintf(fp2,"%s\n",str[i]);
//SAME PROCESSES FOR OTHER LINES.
	while(fgets(str[i],100,fp)!= NULL){	
		reverse_line(str[i],find_size_of_line(str[i]));
		for(j=0;j<find_size_of_line(str[i]);j++){
			if(str[i][j]==46){
				str[i][j]=42;
			}			
			else if(str[i][j]==95){
				str[i][j]=32;
			}
			else {
				str[i][j]=str[i][j]+key;
			}
			if((str[i][j])>122){
				str[i][j] = str[i][j] - 26;
			}
		}
		fprintf(fp2,"%s\n",str[i]);
		i++;		
	}	
	fclose(fp);
	fclose(fp2);
}
void menu(){
//MAKING A BASIC MENU.
	int flag=0;
	int choice;
	do{
		printf("1. Encrypt\n");
		printf("2. Dectypt\n");
		printf("0. Exit\n");
		printf("Choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				encrypt_open_msg();
				break;
			case 2:
				decrypt_secret_msg();
				break;
			case 0:
				flag++;
				break;
			default :
				printf("You did a wrong choice please try again!!\n");
				break;		
	}
	}while(flag==0);
}
//ALP OUT!
