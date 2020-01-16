//ALP EMİR BİLEK
//161044049
//#HW01
#include <stdio.h>
#include <math.h>
#define PI 3.14
//Prototype of Functions
double circle_area(double radius);
double calc_hypotenuse(int side1, int side2);
double calc_radius_of_smallest_circle(int side1,int side2);
double calc_radius_of_largest_circle(int side1,int side2);
double calc_area_of_smallest_circle(int side1,int side2);
double calc_area_of_largest_circle(int side1,int side2);
double calc_area_of_smallest_square(int side1,int side2);
double calc_area_of_largest_square(int side1,int side2);
double calc_area_of_square (int side);
void display_results(double largest_circle,double largest_square,double smalllest_circle,double smallest_square );
int main() {
//Defining Variables
    int side1,side2;
    double largest_circle,largest_square,smallest_square,smallest_circle;
//Asking sides for rectangle to user
    printf("Enter first side for rectangle: ");
    scanf("%d",&side1);
    printf("Enter second side for rectangle: ");
    scanf("%d",&side2);
//Calling Functions
    largest_circle = calc_area_of_largest_circle(side1,side2);
    largest_square = calc_area_of_largest_square(side1,side2);
    smallest_circle = calc_area_of_smallest_circle(side1,side2);
    smallest_square = calc_area_of_smallest_square(side1,side2);
    display_results(largest_circle,largest_square ,smallest_circle ,smallest_square );

    return 0;

}
//Formula for calculating area of a circle
double circle_area(double radius){
    double area;
    area = PI * pow(radius,2.0);
    return area;
}
//Formula for calculating area of a square
double calc_area_of_square (int side){
    double area;
    area = pow(side,2.0);
    return area;
}
//Formula for calculating hypotenuse of a rectangle
double calc_hypotenuse(int side1, int side2){
    double hypotenuse,square;
    square = pow(side1,2.0) + pow(side2,2.0);
    hypotenuse = sqrt(square);
    return hypotenuse;
}
//Calculating radius of largest circle that fits inside a rectangle
double calc_radius_of_largest_circle(int side1,int side2){
    double radius;
    if(side1<=side2){
        radius = side1 /2.0;
    }
    else{
        radius = side2 /2.0;
    }
    return radius;
}
//Calculating radius of smallest circle that surrounds inside a rectagle
double calc_radius_of_smallest_circle(int side1,int side2){
    double radius;
    radius = calc_hypotenuse(side1,side2) /2.0;
    return radius;
}
//Calculating smallest circle with  which functions named:"calc_radius_of_smallest_circle","circle_area"
double calc_area_of_smallest_circle(int side1,int side2){
    double area,radius;
    radius = calc_radius_of_smallest_circle(side1,side2);
    area = circle_area(radius);
    return area;
}
//Calculating largest circle with  which functions named:"calc_radius_of_largest_circle","circle_area"
double calc_area_of_largest_circle(int side1,int side2){
    double area,radius;
    radius = calc_radius_of_largest_circle(side1,side2);
    area = circle_area(radius);
    return area;
}
//Calculating largest square with  which functions named:"calc_radius_of_largest_square","calc_area_of_square"
double calc_area_of_largest_square(int side1,int side2){
    double area;
    if(side1<=side2){
        area = calc_area_of_square(side1);
    }
    else{
        area = calc_area_of_square(side2);
    }
    return area;
}
//Calculating smallest square with  which functions named:"calc_radius_of_largest_square","calc_area_of_square"
double calc_area_of_smallest_square(int side1,int side2){
    double area;
    if(side1<=side2){
        area = calc_area_of_square(side2);
    }
    else{
        area = calc_area_of_square(side1);
    }
    return area;
}
//Displaying the results of functions
void display_results(double largest_circle,double largest_square,double smallest_circle,double smallest_square ){
    printf("The area of the largest circle that fits inside a rectangle %.2f\n",largest_circle);
    printf("The area of the largest square that fits inside a rectangle %.2f\n",largest_square);
    printf("The area of the smallest circle that surrounds inside a rectangle %.2f\n",smallest_circle);
    printf("The area of the smallest square that surrounds inside a rectangle %.2f\n",smallest_square);
}
