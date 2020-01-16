/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/


#include "hw4_io.h"
//3. dereceden bir polinomun katsayilarini kullanicidan istiyor.
int read_polynomial3(double * a0, double * a1, double * a2, double * a3){
    printf("Enter index for polynomial 3\n");
    scanf("%lf",a3);
    printf("Enter index for polynomial 3\n");
    scanf("%lf",a2);
    printf("Enter index for polynomial 3\n");
    scanf("%lf",a1);
    printf("Enter index for polynomial 3\n");
    scanf("%lf",a0);
    return 0;
}
//4. dereceden bir polinomun katsayilarini kullanicidan istiyor.
int read_polynomial4(double * a0, double * a1, double * a2, double * a3, double * a4){
    printf("\nEnter index for polynomial 4");
    scanf("%lf",a4);
    printf("Enter index for polynomial 4");
    scanf("%lf",a3);
    printf("Enter index for polynomial 4");
    scanf("%lf",a2);
    printf("Enter index for polynomial 4");
    scanf("%lf",a1);
    printf("Enter index for polynomial 4:");
    scanf("%lf",a0);
    return 0;
}

//3. dereceden katsayilari kullanicidan istenmis olan polinomun istenilen sekilde duzgun bir sekilde bastiriliyor.
void write_polynomial3(double a0, double a1, double a2, double a3){
    read_polynomial3(&a0,&a1,&a2,&a3);
    if(a3==1){
        printf("x^3");
    }
    else if(a3==0) {
        printf("");
    }
    else {
        if (a3 - (int) a3 != 0) {

            printf("%.2lfx^3", a3);
        }
        else {
            printf("%dx^3", (int) a3);
        }
    }
    if(a2<0){
        if(a2==-1){
            printf("-x^2");
        }
        else{
            if (a2 - (int) a2 != 0) {

                printf("%.2lfx^2", a2);
            }
            else {
                printf("%dx^2", (int) a2);
            }
        }

    }
    else if(a2==0){
        printf("");
    }
    else if(a2>0) {
        if (a2 == 1) {
            printf("+x^2");
        } else {
            if (a2 - (int) a2 != 0) {

                printf("+%.2lfx^2", a2);
            } else {
                printf("+%dx^2", (int) a2);
            }
        }
    }
    if(a1<0){
        if(a1==-1){
            printf("-x");
        }
        else{
            if (a1 - (int) a1 != 0) {

                printf("%.2lfx", a1);
            }
            else {
                printf("%dx", (int) a1);
            }
        }

    }
    else if(a1==0){
        printf("");
    }
    else if(a1>0) {
        if (a1 == 1) {
            printf("+x");
        } else {
            if (a1 - (int) a1 != 0) {

                printf("+%.2lfx", a1);
            } else {
                printf("+%dx", (int) a1);
            }
        }
    }
    if(a0<0){
        if (a0 - (int) a0 != 0) {

            printf("%.2lf", a0);
        } else {
            printf("%d", (int) a0);
        }
    }
    else if(a0==0){
        printf("");
    }
    else{
        if (a0 - (int) a0 != 0) {

            printf("+%.2lf", a0);
        } else {
            printf("+%d", (int) a0);
        }
    }
}
//4. dereceden katsayilari kullanicidan istenmis olan polinomun istenilen sekilde duzgun bir sekilde bastiriliyor.
void write_polynomial4(double a0, double a1, double a2, double a3,double a4){
    read_polynomial4(&a0,&a1,&a2,&a3,&a4);
    if(a4==1){
        printf("x^4");
    }
    else if(a4==0) {
        printf("");
    }
    else {
        if (a4 - (int) a4 != 0) {

            printf("%.2lfx^4", a4);
        }
        else {
            printf("%dx^4", (int) a4);
        }
    }

    if(a3<0){
        if(a3==-1){
            printf("-x^3");
        }
        else{
            if (a3 - (int) a4 != 0) {

                printf("%.2lfx^3", a3);
            }
            else {
                printf("%dx^3", (int) a3);
            }
        }

    }
    else if(a3==0){
        printf("");
    }
    else if(a3>0) {
        if (a3 == 1) {
            printf("+x^3");
        } else {
            if (a3 - (int) a3 != 0) {

                printf("+%.2lfx^3", a3);
            } else {
                printf("+%dx^3", (int) a3);
            }
        }
    }
    if(a2<0){
        if(a2==-1){
            printf("-x^2");
        }
        else{
            if (a2 - (int) a2 != 0) {

                printf("%.2lfx^2", a2);
            }
            else {
                printf("%dx^2", (int) a2);
            }
        }

    }
    else if(a2==0){
        printf("");
    }
    else if(a2>0) {
        if (a2 == 1) {
            printf("+x^2");
        } else {
            if (a2 - (int) a2 != 0) {

                printf("+%.2lfx^2", a2);
            } else {
                printf("+%dx^2", (int) a2);
            }
        }
    }
    if(a1<0){
        if(a1==-1){
            printf("-x");
        }
        else{
            if (a1 - (int) a1 != 0) {

                printf("%.2lfx", a1);
            }
            else {
                printf("%dx", (int) a1);
            }
        }

    }
    else if(a1==0){
        printf("");
    }
    else if(a1>0) {
        if (a1 == 1) {
            printf("+x");
        } else {
            if (a1 - (int) a1 != 0) {

                printf("+%.2lfx", a1);
            } else {
                printf("+%dx", (int) a1);
            }
        }
    }
    if(a0<0){
        if (a0 - (int) a0 != 0) {

            printf("%.2lf", a0);
        } else {
            printf("%d", (int) a0);
        }
    }
    else if(a0==0){
        printf("");
    }
    else{
        if (a0 - (int) a0 != 0) {

            printf("+%.2lf", a0);
        } else {
            printf("+%d", (int) a0);
        }
    }
}
//161044049
//Alp Emir BİLEK...
