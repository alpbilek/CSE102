//#HW02_PART01
//ALP EMIR BILEK
//161044049
#include <stdio.h>
#include <stdlib.h>
int main() {
//DEFINING VARIABLES.
    int i=0,total=0,counterA=0,counterB=0,counterC=0,counterD=0,counterF=0;
    int a,most_succesful,most_unsuccesful,x,secim,max_index,min_index;
    double average;
    char grade_of_max,grade_of_min;
    int control = 1;
//ASKING STUDENT NUMBER TO THE USER.
    printf("Enter student count:");

    while(control){

        scanf("%d",&a);
//CONTROLLING THE NUMBER FOR RANGE.
        if(a<3){
            printf("Not in range!\n");
            printf("Enter student count: ");

        }
        else if(a>50){
            printf("Not in range!\n");
            printf("Enter student count: ");
        }
//RANDOMIZING FOR STUDENTS NOTES.
        else{
            x =( rand() % 101);
            printf("%d ", x);
//INCREASING THE COUNTERS FOR LETTER GRADES.
            if (x >= 90 && x <= 100) {
                counterA++;
            } else if (x >= 80 && x <= 89) {
                counterB++;
            } else if (x >= 70 && x <= 79) {
                counterC++;
            } else if (x >= 60 && x <= 69) {
                counterD++;
            } else if (x >= 0 && x <= 59) {
                counterF++;
            }
//ASSIGN THE X TO THE MOST_SUCCESFUL AND MOST_UNSUCCESFUL.
            most_succesful = x;
            most_unsuccesful = x;
            total += x;
            i++;
            while (i < a) {
                x = rand() % 100;
                printf("%d ", x);
                if (x >= 90 && x <= 100) {
                    counterA++;
                } else if (x >= 80 && x <= 89) {
                    counterB++;
                } else if (x >= 70 && x <= 79) {
                    counterC++;
                } else if (x >= 60 && x <= 69) {
                    counterD++;
                } else if (x >= 0 && x <= 59) {
                    counterF++;
                }
//IF X SMALLER THAN MOST_UNSUCCESFUL,X BECOMES THE NEW MOST_UNSUCCESFUL.
                if (x < most_unsuccesful) {
                    most_unsuccesful = x;
                    if (x >= 90 && x <= 100) {
                        grade_of_min = 'A';
                    } else if (x >= 80 && x <= 89) {
                        grade_of_min = 'B';
                    } else if (x >= 70 && x <= 79) {
                        grade_of_min = 'C';
                    } else if (x >= 60 && x <= 69) {
                        grade_of_min = 'D';
                    } else if (x >= 0 && x <= 59) {
                        grade_of_min = 'F';
                    }
                    min_index = i + 1;

                }
//IF X BIGGER THAN MOST_SUCCESFUL,X BECOMES THE NEW MOST_SUCCESFUL.
                if (x > most_succesful) {
                    most_succesful = x;
                    if (x >= 90 && x <= 100) {
                        grade_of_max = 'A';
                    } else if (x >= 80 && x <= 89) {
                        grade_of_max = 'B';
                    } else if (x >= 70 && x <= 79) {
                        grade_of_max = 'C';
                    } else if (x >= 60 && x <= 69) {
                        grade_of_max = 'D';
                    } else if (x >= 0 && x <= 59) {
                        grade_of_max = 'F';
                    }
                    max_index = i + 1;
                }
                total = total + x;
                i++;
            }
//CALCULATING THE AVARAGE.
            average = (double) total / (double)a;

            while(control ){
//CREATING A MENU.
                printf("\nStudent Score Calculator Menu for %d Student ", a);
                printf("\n1)Most Successful Student\n2)Most Unsuccesful Student\n3)Letter Grade Statistics\n4)Calculate Average\n5)Show All Data\n ");
                printf("                                                       Make selection:");
                scanf("%d", &secim);
                printf("                                                       Make selection:%d\n",secim);
//PRINTING THE RESULTS.
                switch (secim) {
                    case 1:
                        printf("Index:%d\n",max_index);
                        printf("Score:%d\n", most_succesful);
                        printf("Letter Grade:%c\n",grade_of_max);
                        break;
                    case 2:
                        printf("Index:%d\n",min_index);
                        printf("Score:%d\n", most_unsuccesful);
                        printf("Letter Grade:%c\n",grade_of_min);
                        break;
                    case 3:
                        printf("%d Student got letter grade 'A'\n", counterA);
                        printf("%d Student got letter grade 'B'\n", counterB);
                        printf("%d Student got letter grade 'C'\n", counterC);
                        printf("%d Student got letter grade 'D'\n", counterD);
                        printf("%d Student got letter grade 'F'\n", counterF);
                        break;
                    case 4:
                        printf("The avarege Score of %d Student is %.2f\n", a, average);
                        break;
                    case 5:
                        printf("Most Successful Student:\n");
                        printf("Index:%d\n", max_index);
                        printf("Score:%d\n", most_succesful);
                        printf("Letter Grade:%c\n", grade_of_max);
                        printf("Most Unsuccessful Student:\n");
                        printf("Index:%d\n", min_index);
                        printf("Score:%d\n", most_unsuccesful);
                        printf("Letter Grade:%c\n", grade_of_min);
                        printf("%d Student got letter grade 'A'\n", counterA);
                        printf("%d Student got letter grade 'B'\n", counterB);
                        printf("%d Student got letter grade 'C'\n", counterC);
                        printf("%d Student got letter grade 'D'\n", counterD);
                        printf("%d Student got letter grade 'F'\n", counterF);
                        printf("The avarege Score of %d Student is %.2f\n", a, average);
                        break;

                    case -1:
                        control = 0;
                        break;
                    default :
                        printf("False Selection.");
                }

            }
        }
    }
    return 0;
}