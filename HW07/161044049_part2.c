#include<stdio.h>
void part1();
void part2();
int main(){


	part1();
	//part2();
	printf("Your calendar has been made!!!\nPlease check the files!\n");



return 0;
}
//PART1 fonksiyonu!
void part1(){
	FILE *fp;
	fp=fopen("input_date.txt","w");
	char start[11],end[11];
	char day1[2],month1[2],year1[4],day2[2],month2[2],year2[4];
	int flag=0,i;
	int days,daye,months,monthe,years,yeare;
	//Kullanıcıdan baslangıc ve bitis tarihi al!
	printf("Please enter starting date:");
	scanf("%s",start);
	printf("Please enter ending date:");
	scanf("%s",end);
	//String olarak aldığımız tarihi üzerinde işlem yapabilmek icin integer a ceviriyorum!
	day1[0]=start[0];
    day1[1]=start[1];
    month1[0]=start[3];
    month1[1]=start[4];
	day2[0]=end[0];
	day2[1]=end[1];
	month2[0]=end[3];
	month2[1]=end[4];
	year1[0]=start[6];
	year1[1]=start[7];
	year1[2]=start[8];
	year1[3]=start[9];
	year2[0]=end[6];
	year2[1]=end[7];
	year2[2]=end[8];
	year2[3]=end[9];
	switch(day1[0]){
		case '0':
			days=0;
			break;
		case '1':
			days=10;
			break;
		case '2':
			days=20;
			break;
		case '3':
			days=30;
			break;
		default :
			printf("Wrong date!!The program is going to terminate!!");		
			break;	
	}
	switch(day1[1]){
		case '0':
			days=days+0;
			break;
		case '1':
			days=days+1;
			break;
		case '2':
			days=2+days;
			break;
		case '3':
			days=3+days;
			break;
		case '4':
			days=days+4;
			break;
		case '5':
			days=days+5;
			break;
		case '6':
			days=6+days;
			break;
		case '7':
			days=7+days;
			break;
		case '8':
			days=days+8;
			break;
		case '9':
			days=days+9;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");	
			break;
	}
	switch(month1[0]){
		case '0':
			months=0;
			break;
		case '1':
			months=10;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");	
			break;
	}
	switch(month1[1]){
		case '0':
			months=months+0;
			break;
		case '1':
			months=months+1;
			break;
		case '2':
			months=2+months;
			break;
		case '3':
			months=3+months;
			break;
		case '4':
			months=months+4;
			break;
		case '5':
			months=months+5;
			break;
		case '6':
			months=6+months;
			break;
		case '7':
			months=7+months;
			break;
		case '8':
			months=months+8;
			break;
		case '9':
			months=months+9;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");	
			break;
	}
	switch(day2[0]){
		case '0':
			daye=0;
			break;
		case '1':
			daye=10;
			break;
		case '2':
			daye=20;
			break;
		case '3':
			daye=30;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");		
			break;	
	}	
	switch(day2[1]){
		case '0':
			daye=daye+0;
			break;
		case '1':
			daye=daye+1;
			break;
		case '2':
			daye=2+daye;
			break;
		case '3':
			daye=3+daye;
			break;
		case '4':
			daye=daye+4;
			break;
		case '5':
			daye=daye+5;
			break;
		case '6':
			daye=6+daye;
			break;
		case '7':
			daye=7+daye;
			break;
		case '8':
			daye=daye+8;
			break;
		case '9':
			daye=daye+9;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");	
			break;
	}
	switch(month2[0]){
		case '0':
			monthe=0;
			break;
		case '1':
			monthe=10;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");	
			break;
	}
	switch(month2[1]){
		case '0':
			monthe=monthe+0;
			break;
		case '1':
			monthe=monthe+1;
			break;
		case '2':
			monthe=2+monthe;
			break;
		case '3':
			monthe=3+monthe;
			break;
		case '4':
			monthe=monthe+4;
			break;
		case '5':
			monthe=monthe+5;
			break;
		case '6':
			monthe=6+monthe;
			break;
		case '7':
			monthe=7+monthe;
			break;
		case '8':
			monthe=monthe+8;
			break;
		case '9':
			monthe=monthe+9;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");	
			break;
	}
	switch(year1[0]){
		case '0':
			years=0;
			break;
		case '1':
			years=1000;
			break;
		case '2':
			years=2000;
			break;
		case '3':
			years=3000;
			break;
		case '4':
			years=4000;
			break;
		case '5':
			years=5000;
			break;
		case '6':
			years=6000;
			break;
		case '7':
			years=7000;
			break;
		case '8':
			years=8000;
			break;
		case '9':
			years=9000;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");	
			break;
	}
	switch(year1[1]){
		case '0':
			years=0+years;
			break;
		case '1':
			years=100+years;
			break;
		case '2':
			years=200+years;
			break;
		case '3':
			years=300+years;
			break;
		case '4':
			years=400+years;
			break;
		case '5':
			years=500+years;
			break;
		case '6':
			years=600+years;
			break;
		case '7':
			years=700+years;
			break;
		case '8':
			years=800+years;
			break;
		case '9':
			years=900+years;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");	
			break;
	}
	switch(year1[2]){
		case '0':
			years=0+years;
			break;
		case '1':
			years=10+years;
			break;
		case '2':
			years=20+years;
			break;
		case '3':
			years=30+years;
			break;
		case '4':
			years=40+years;
			break;
		case '5':
			years=50+years;
			break;
		case '6':
			years=60+years;
			break;
		case '7':
			years=70+years;
			break;
		case '8':
			years=80+years;
			break;
		case '9':
			years=90+years;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");	
			break;
	}
	switch(year1[3]){
		case '0':
			years=0+years;
			break;
		case '1':
			years=1+years;
			break;
		case '2':
			years=2+years;
			break;
		case '3':
			years=3+years;
			break;
		case '4':
			years=4+years;
			break;
		case '5':
			years=5+years;
			break;
		case '6':
			years=6+years;
			break;
		case '7':
			years=7+years;
			break;
		case '8':
			years=8+years;
			break;
		case '9':
			years=9+years;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");	
			break;
	}
	switch(year2[0]){
		case '0':
			yeare=0;
			break;
		case '1':
			yeare=1000;
			break;
		case '2':
			yeare=2000;
			break;
		case '3':
			yeare=3000;
			break;
		case '4':
			yeare=4000;
			break;
		case '5':
			yeare=5000;
			break;
		case '6':
			yeare=6000;
			break;
		case '7':
			yeare=7000;
			break;
		case '8':
			yeare=8000;
			break;
		case '9':
			yeare=9000;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");	
			break;
	}
	switch(year2[1]){
		case '0':
			yeare=0+yeare;
			break;
		case '1':
			yeare=100+yeare;
			break;
		case '2':
			yeare=200+yeare;
			break;
		case '3':
			yeare=300+yeare;
			break;
		case '4':
			yeare=400+yeare;
			break;
		case '5':
			yeare=500+yeare;
			break;
		case '6':
			yeare=600+yeare;
			break;
		case '7':
			yeare=700+yeare;
			break;
		case '8':
			yeare=800+yeare;
			break;
		case '9':
			yeare=900+yeare;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");	
			break;
	}
	switch(year2[2]){
		case '0':
			yeare=0+yeare;
			break;
		case '1':
			yeare=10+yeare;
			break;
		case '2':
			yeare=20+yeare;
			break;
		case '3':
			yeare=30+yeare;
			break;
		case '4':
			yeare=40+yeare;
			break;
		case '5':
			yeare=50+yeare;
			break;
		case '6':
			yeare=60+yeare;
			break;
		case '7':
			yeare=70+yeare;
			break;
		case '8':
			yeare=80+yeare;
			break;
		case '9':
			yeare=90+yeare;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");	
			break;
	}
	switch(year2[3]){
		case '0':
			yeare=0+yeare;
			break;
		case '1':
			yeare=1+yeare;
			break;
		case '2':
			yeare=2+yeare;
			break;
		case '3':
			yeare=3+yeare;
			break;
		case '4':
			yeare=4+yeare;
			break;
		case '5':
			yeare=5+yeare;
			break;
		case '6':
			yeare=6+yeare;
			break;
		case '7':
			yeare=7+yeare;
			break;
		case '8':
			yeare=8+yeare;
			break;
		case '9':
			yeare=9+yeare;
			break;
		default :
			printf("\nWrong date!!The program is going to terminate!!");	
			break;
	}
	//Cevirme islemi bitti simdi tarihi ilerleterek dosyaya print ediyorum!
   while(flag==0){
            if(days<10 && months<10) {
                fprintf(fp,"0%d/0%d/%d\n", days, months, years);
            }
            else if(days<10){
                fprintf(fp,"0%d/%d/%d\n",days,months,years);
            }
            else if(months<10){
                fprintf(fp,"%d/0%d/%d\n",days,months,years);
            }

            else {
            fprintf(fp,"%d/%d/%d\n", days, months, years);
            }
            if(months==1 || months==3 || months==5 || months==7 || months==8 || months==10 || months==12){			
                if(days==31) {
                    days =0;
                    if(months == 12) {
                        years++;
                        months = 1;
                    }
                    else {
                        months++;
                    }
                }
            }
            else if(months==4 || months==6 || months==9 || months==11){
                if(days==30) {
                    days =0;
                    if(months == 12) {
                        years++;
                        months = 1;
                    }
                    else {
                        months++;
                    }
                }
            }
            else if(months==2) {
                if (years % 4 == 0) {
                    if (days == 29) {
                        days = 0;
                        if (months == 12) {
                            years++;
                            months = 1;
                        }
						else {
                            months++;
                        }
                    }
                }
                else{
                    if (days == 28) {
                        days = 0;
                        if (months == 12) {
                            years++;
                            months = 1;
                        } 
						else {
                            months++;
                        }
                    }
                }
            }
            days++;
            if(days== daye && months==monthe && years==yeare){
                if(days<10 && months<10) {
                fprintf(fp,"0%d/0%d/%d\n", days, months, years);
            	}
		        else if(days<10){
		           fprintf(fp,"0%d/%d/%d\n",days,months,years);
		        }
		        else if(months<10){
		            fprintf(fp,"%d/0%d/%d\n",days,months,years);
		        }

		        else {
		        fprintf(fp,"%d/%d/%d\n", days, months, years);
		        }
                flag++;
            }
		}
	}
void part2(){
	FILE *fp;
	FILE *sp;
	fp=fopen("input_date.txt","r");
	sp=fopen(" new_date.txt ","w");
	char str[100];
	char day2[2],month2[2],year2[4],*day;
	int days,daye,months,monthe,years,yeare;
	int flag=0,flag1=0,day_counter=0;
	int day1=29,mouth1=10,year1=1923;
	int day_counter1[1000];
	char day_aq;
	char gun[7]="stwpfcm",gun1[100];
	int flag_aq=0,i=0;
	while(flag==0){
		fscanf(fp,"%s",str);
		day2[0]=str[0];
		day2[1]=str[1];	
		month2[0]=str[3];
		month2[1]=str[4];
		year2[0]=str[6];
		year2[1]=str[7];
		year2[2]=str[8];
		year2[3]=str[9];
		switch(day2[0]){
			case '0':
				daye=0;
				break;
			case '1':
				daye=10;
				break;
			case '2':
				daye=20;
				break;
			case '3':
				daye=30;
				break;
			default :
				printf("\nWrong day1!!The program is going to terminate!!");		
				break;	
		}
		switch(day2[1]){
			case '0':
				daye=daye+0;
				break;
			case '1':
				daye=daye+1;
				break;
			case '2':
				daye=2+daye;
				break;
			case '3':
				daye=3+daye;
				break;
			case '4':
				daye=daye+4;
				break;
			case '5':
				daye=daye+5;
				break;
			case '6':
				daye=6+daye;
				break;
			case '7':
				daye=7+daye;
				break;
			case '8':
				daye=daye+8;
				break;
			case '9':
				daye=daye+9;
				break;
			default :
				printf("\nWrong day2!!The program is going to terminate!!");	
				break;
		}
		switch(month2[0]){
			case '0':
				monthe=0;
				break;
			case '1':
				monthe=10;
				break;
			default :
				printf("month0%c\n",month2[0]);
				printf("\nWrong day3!!The program is going to terminate!!");	
				break;
		}
		switch(month2[1]){
			case '0':
				monthe=monthe+0;
				break;
			case '1':
				monthe=monthe+1;
				break;
			case '2':
				monthe=2+monthe;
				break;
			case '3':
				monthe=3+monthe;
				break;
			case '4':
				monthe=monthe+4;
				break;
			case '5':
				monthe=monthe+5;
				break;
			case '6':
				monthe=6+monthe;
				break;
			case '7':
				monthe=7+monthe;
				break;
			case '8':
				monthe=monthe+8;
				break;
			case '9':
				monthe=monthe+9;
				break;
			default :
				printf("month1%c\n",month2[1]);
				printf("\nWrong day4!!The program is going to terminate!!");	
				break;
		}
		switch(year2[0]){
			case '0':
				yeare=0;
				break;
			case '1':
				yeare=1000;
				break;
			case '2':
				yeare=2000;
				break;
			case '3':
				yeare=3000;
				break;
			case '4':
				yeare=4000;
				break;
			case '5':
				yeare=5000;
				break;
			case '6':
				yeare=6000;
				break;
			case '7':
				yeare=7000;
				break;
			case '8':
				yeare=8000;
				break;
			case '9':
				yeare=9000;
				break;
			default :
				printf("year0%c\n",year2[0]);
				printf("\nWrong day5!!The program is going to terminate!!");	
				break;
		}	
		switch(year2[1]){
			case '0':
				yeare=0+yeare;
				break;
			case '1':
				yeare=100+yeare;
				break;
			case '2':
				yeare=200+yeare;
				break;
			case '3':
				yeare=300+yeare;
				break;
			case '4':
				yeare=400+yeare;
				break;
			case '5':
				yeare=500+yeare;
				break;
			case '6':
				yeare=600+yeare;
				break;
			case '7':
				yeare=700+yeare;
				break;
			case '8':
				yeare=800+yeare;
				break;
			case '9':
				yeare=900+yeare;
				break;
			default :
				printf("year1%c\n",year2[1]);
				printf("\nWrong day6!!The program is going to terminate!!");	
				break;
		}
		switch(year2[2]){
			case '0':
				yeare=0+yeare;
				break;
			case '1':
				yeare=10+yeare;
				break;
			case '2':
				yeare=20+yeare;
				break;
			case '3':
				yeare=30+yeare;
				break;
			case '4':
				yeare=40+yeare;
				break;
			case '5':
				yeare=50+yeare;
				break;
			case '6':
				yeare=60+yeare;
				break;
			case '7':
				yeare=70+yeare;
				break;
			case '8':
				yeare=80+yeare;
				break;
			case '9':
				yeare=90+yeare;
				break;
			default :
				printf("year2%c\n",year2[2]);
				printf("\nWrong day7!!The program is going to terminate!!");	
				break;
		}
	switch(year2[3]){
			case '0':
				yeare=0+yeare;
				break;
			case '1':
				yeare=1+yeare;
				break;
			case '2':
				yeare=2+yeare;
				break;
			case '3':
				yeare=3+yeare;
				break;
			case '4':
				yeare=4+yeare;
				break;
			case '5':
				yeare=5+yeare;
				break;
			case '6':
				yeare=6+yeare;
				break;
			case '7':
				yeare=7+yeare;
				break;
			case '8':
				yeare=8+yeare;
				break;
			case '9':
				yeare=9+yeare;
				break;
			default :
				printf("year8%c\n",year2[3]);
				printf("\nWrong day8!!The program is going to terminate!!");	
				break;
		}
		while(flag1==0){
		  /* if(day1<10 && mouth1<10) {
           		printf("0%d/0%d/%d\n", day1, mouth1, year1);
            }
            if(day1<10){
                printf("0%d/%d/%d\n",day1,mouth1,year1);
            }
            else if(mouth1<10){
                printf("%d/0%d/%d\n",day1,mouth1,year1);
            }

            else {
            printf("%d/%d/%d\n", day1, mouth1, year1);
            }*/
            if(mouth1==1 || mouth1==3 || mouth1==5 || mouth1==7 || mouth1==8 || mouth1==10 || mouth1==12){
                if(day1==31) {
                    day1 =0;
                    if(mouth1 == 12) {
                        year1++;
                        mouth1 = 1;
                    }
                    else {
                        mouth1++;
                    }
                }
            }
            else if(mouth1==4 || mouth1==6 || mouth1==9 || mouth1==11){
                if(day1==30) {
                    day1 =0;
                    if(mouth1 == 12) {
                        year1++;
                        mouth1 = 1;
                    }
                    else {
                        mouth1++;
                    }
                }
            }
            else if(mouth1==2) {
                if (year1 % 4 == 0) {
                    if (day1 == 29) {
                        day1 = 0;
                        if (mouth1 == 12) {
                            year1++;
                            mouth1 = 1;
                        } else {
                            mouth1++;
                        }
                    }
                }
                else{
                    if (day1 == 28) {
                        day1 = 0;
                        mouth1++;                        
                    }
                }
            }
            day1++;
            day_counter++;
			
            if(day1== daye && mouth1==monthe && year1==yeare){
               // printf("%d/%d/%d\n",daye,monthe,yeare);
                flag1++;
            }
			
        }			
		if(feof(fp)){
			break;	
		}
		//printf("%d\n",day_counter);	
		//printf("%d/%d/%d\n",daye,monthe,yeare);
	}

	switch(day_counter%7){
		case 0:
			day_aq='s';
			break;
		case 1:
			day_aq='t';
			break;
		case 2:
			day_aq='w';
			break;
		case 3:
			day_aq='p';
			break;
		case 4:
			day_aq='f';
			break;
		case 5:
			day_aq='c';
			break;
		case 6:
			day_aq='m';
			break;
	}

	printf("%s\n",gun);
	for(i=0;i<7;i++){
		if(gun[i]==day_aq){
			printf("%c\n",day_aq);
			flag_aq++;
		}
	}
	while(flag_aq==0){
		if(i==6){
			printf("%c\n",gun[i]);
			i=0;	
		}
		else {
			
		}
	}
	

	fclose(fp);	
	/*while(flag==0){
		fscanf(fp,"%s",str);
		day2[0]=str[0];
		day2[1]=str[1];
		month2[0]=str[3];
		month2[1]=str[4];
		year2[0]=str[6];
		year2[1]=str[7];
		year2[2]=str[8];
		year2[3]=str[9];
		days=23;
		months=10;
		years=1923;
		printf("day20%c\n",day2[0]);	
		printf("day21%c\n",day2[1]);
		printf("month20%c\n",month2[0]);
		printf("month21%c\n",month2[1]);
		printf("year20%c\n",year2[0]);
		printf("year21%c\n",year2[1]);
		printf("year22%c\n",year2[2]);
		printf("year23%c\n",year2[3]);	
}*/
	
/*
		switch(day2[0]){
			case '0':
				daye=0;
				break;
			case '1':
				daye=10;
				break;
			case '2':
				daye=20;
				break;
			case '3':
				daye=30;
				break;
			default :
				printf("\nWrong day1!!The program is going to terminate!!");		
				break;	
		}	
		switch(day2[1]){
			case '0':
				daye=daye+0;
				break;
			case '1':
				daye=daye+1;
				break;
			case '2':
				daye=2+daye;
				break;
			case '3':
				daye=3+daye;
				break;
			case '4':
				daye=daye+4;
				break;
			case '5':
				daye=daye+5;
				break;
			case '6':
				daye=6+daye;
				break;
			case '7':
				daye=7+daye;
				break;
			case '8':
				daye=daye+8;
				break;
			case '9':
				daye=daye+9;
				break;
			default :
				printf("\nWrong day2!!The program is going to terminate!!");	
				break;
		}
		switch(month2[0]){
			case '0':
				monthe=0;
				break;
			case '1':
				monthe=10;
				break;
			default :
				printf("month0%c\n",month2[0]);
				printf("\nWrong day3!!The program is going to terminate!!");	
				break;
		}
		switch(month2[1]){
			case '0':
				monthe=monthe+0;
				break;
			case '1':
				monthe=monthe+1;
				break;
			case '2':
				monthe=2+monthe;
				break;
			case '3':
				monthe=3+monthe;
				break;
			case '4':
				monthe=monthe+4;
				break;
			case '5':
				monthe=monthe+5;
				break;
			case '6':
				monthe=6+monthe;
				break;
			case '7':
				monthe=7+monthe;
				break;
			case '8':
				monthe=monthe+8;
				break;
			case '9':
				monthe=monthe+9;
				break;
			default :
				printf("month1%c\n",month2[1]);
				printf("\nWrong day4!!The program is going to terminate!!");	
				break;
		}
		switch(year2[0]){
			case '0':
				yeare=0;
				break;
			case '1':
				yeare=1000;
				break;
			case '2':
				yeare=2000;
				break;
			case '3':
				yeare=3000;
				break;
			case '4':
				yeare=4000;
				break;
			case '5':
				yeare=5000;
				break;
			case '6':
				yeare=6000;
				break;
			case '7':
				yeare=7000;
				break;
			case '8':
				yeare=8000;
				break;
			case '9':
				yeare=9000;
				break;
			default :
				printf("year0%c\n",year2[0]);
				printf("\nWrong day5!!The program is going to terminate!!");	
				break;
		}
	switch(year2[1]){
			case '0':
				yeare=0+yeare;
				break;
			case '1':
				yeare=100+yeare;
				break;
			case '2':
				yeare=200+yeare;
				break;
			case '3':
				yeare=300+yeare;
				break;
			case '4':
				yeare=400+yeare;
				break;
			case '5':
				yeare=500+yeare;
				break;
			case '6':
				yeare=600+yeare;
				break;
			case '7':
				yeare=700+yeare;
				break;
			case '8':
				yeare=800+yeare;
				break;
			case '9':
				yeare=900+yeare;
				break;
			default :
				printf("year1%c\n",year2[1]);
				printf("\nWrong day6!!The program is going to terminate!!");	
				break;
		}
	switch(year2[2]){
			case '0':
				yeare=0+yeare;
				break;
			case '1':
				yeare=10+yeare;
				break;
			case '2':
				yeare=20+yeare;
				break;
			case '3':
				yeare=30+yeare;
				break;
			case '4':
				yeare=40+yeare;
				break;
			case '5':
				yeare=50+yeare;
				break;
			case '6':
				yeare=60+yeare;
				break;
			case '7':
				yeare=70+yeare;
				break;
			case '8':
				yeare=80+yeare;
				break;
			case '9':
				yeare=90+yeare;
				break;
			default :
				printf("year2%c\n",year2[2]);
				printf("\nWrong day7!!The program is going to terminate!!");	
				break;
		}
	switch(year2[3]){
			case '0':
				yeare=0+yeare;
				break;
			case '1':
				yeare=1+yeare;
				break;
			case '2':
				yeare=2+yeare;
				break;
			case '3':
				yeare=3+yeare;
				break;
			case '4':
				yeare=4+yeare;
				break;
			case '5':
				yeare=5+yeare;
				break;
			case '6':
				yeare=6+yeare;
				break;
			case '7':
				yeare=7+yeare;
				break;
			case '8':
				yeare=8+yeare;
				break;
			case '9':
				yeare=9+yeare;
				break;
			default :
				printf("year8%c\n",year2[3]);
				printf("\nWrong day8!!The program is going to terminate!!");	
				break;
		}
		   while(flag1==0){
		        if(months==1 || months==3 || months==5 || months==7 || months==8 || months==10 || months==12){			
		            if(days==31) {
		                days =0;
		                if(months == 12) {
		                    years++;
		                    months = 1;
		                }
		                else {
		                    months++;
		                }
		            }
		        }
		        else if(months==4 || months==6 || months==9 || months==11){
		            if(days==30) {
		                days =0;
		                if(months == 12) {
		                    years++;
		                    months = 1;
		                }
		                else {
		                    months++;
		                }
		            }
		        }
		        else if(months==2) {
		            if (years % 4 == 0) {
		                if (days == 29) {
		                    days = 0;
		                    if (months == 12) {
		                        years++;
		                        months = 1;
		                    }
							else {
		                        months++;
		                    }
		                }
		            }
		            else{
		                if (days == 28) {
		                    days = 0;
		                    if (months == 12) {
		                        years++;
		                        months = 1;
		                    } 
							else {
		                        months++;
		                    }
		                }
		            }
		        }
		        days++;
				day_counter++;
		        if(days== daye && months==monthe && years==yeare){
		            flag1++;
		        }
			}
		if(feof(fp)){
			break;	
		}
		fprintf(sp,"%d/%d/%d\n", daye, monthe, yeare);		
		printf("%d\n",day_counter%7);
	}
	fclose(fp);	























*/
}








































