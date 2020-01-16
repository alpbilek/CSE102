/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"
#include <math.h>
#define error_margin 0.001
//integral hesaplama fonksiyonu.
double integral(double f(double x), double xs, double xe, double delta){
    double length,sum1=0,sum2=0,sum,y0,yn;
    int i;
//kac tane alan olduğunu hesaplamak için
    length=(xe-xs)/delta;
    for(i=1; i<=length; i++){
        sum1 = sum1 + (f(xs)*delta);
        xs=xs+delta;
    }
    return sum1;
}
//cift katlı integral hesaplamak icin
double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta){
    double sum2=0,j;
    double i;
    double temp;
    for(i=xs; i<xe; i+=delta){
        for(j=ys;j<ye;j+=delta){
            temp = ((f(i,j))*delta*delta);
            sum2 += temp;
        }
    }
    //cift katlı integralde x ve y ekseni icin düsünmem gerekiyor bunu da 2 for ıcınde yaptım ve en son olarak sum2 degerini donduruyorum.
    return sum2;
}
//Turev hesaplamak icin.
int derivatives(double f(double a), double x, double eps, double * d1, double * d2) {
    double sum, sum1;
    sum = f(x+ eps) - f(x - eps);
    *d1 = (sum / (2*eps));
    sum1 = f(x + eps) - 2 * f(x) + f(x - eps);
    *d2 = (sum1 /( eps * eps));
    return 0;
    //d1 pointeri 1. turevi donduruyor.
    //d2 pointeri 2. turevi donduruyor.
}
//turevlerın error degerlerını hesaplamak ıcın.
int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2){
    double cd1,cd2,*sum,*sum2,temp,temp2;
    derivatives(f(x),x,eps,&cd1,&cd2);
    *e1=fabs((cd1-d1(x)));
    *e2=fabs((cd2-d2(x)));
    return 0;
    //e1 pointeri benim kendi yazdigim 1.turev ile sizin gireceginiz turev degerleriyle farkını donduruyor
    //e2 pointeri benim kendi yazdigim 2.turev ile sizin gireceginiz turev degerleriyle farkını donduruyor
}
//herhangi bir polinom icin kok bulmak icin
int find_roots(double f(double x), double * x1, double * x2, double * x3, double * x4){
    double i;
    int counter=0,a=0;
    double array[4];
    for(i=-239;i<=239;i=i+error_margin){
        if(f(i)<0.001 && f(i)>-0.001){
            array[a]=i;
            counter++;
            a++;
        }
    }
    if(counter==1){
        x1=&array[0];
        printf("First root is %.3lf\n",*x1);
        printf("x2=0.0\n,x3=0.0\n,x4=0.0");
    }
    else if(counter==2){
        x1=&array[0];
        x2=&array[1];
        printf("First root is %.3lf\n",*x1);
        printf("Second root is %.3lf\n",*x2);
        printf("x3=0.0\n,x4=0.0");
    }
    else if(counter==3){
        x1=&array[0];
        x2=&array[1];
        x3=&array[2];
        printf("First root is %.3lf\n",*x1);
        printf("Second root is %.3lf\n",*x2);
        printf("Third root is %.3lf\n",*x3);
        printf("x4=0.0");
    }
    else if(counter==4){
        x1=&array[0];
        x2=&array[1];
        x3=&array[2];
        x4=&array[3];
        printf("First root is %.3lf\n",*x1);
        printf("Second root is %.3lf\n",*x2);
        printf("Third root is %.3lf\n",*x3);
        printf("Fourth root is %.3lf\n",*x4);
    }
    return 0;
    //hocam oncelıkle bu fonksiyonumda hata payını kendiniz degistirebilirsiniz define olarak tanımladım.
    //kodum -239 ile 239 degerleri arasindaki kokleri buluyor ve isterseniz bunu da degistirebilirsiniz.
    //kodum sizin gireceginiz polinomu -239 ile 239 arasindaki 0.001 arttirarak 0 yapiyor mu diye ariyor ve yapiyor ise bir arraye atıyor.
    //sonra da bu array deki degerleri x1 x2 x3 x4 pointerlerina tek tek atiyor ve bastiriyor.
    //161044049
    //Alp Emir BİLEK...
}
