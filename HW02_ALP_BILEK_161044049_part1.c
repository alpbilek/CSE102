//#HW02_PART02
//ALP EMIR BILEK
//161044049
#include <stdio.h>
int main() {
//DEFINING VARIABLES.
    int num, digit1 = -1, digit2 = -1, digit3 = -1, digit4 = -1, digit5 = -1;
//ASKING A NUMBER TO THE USER.
    printf("Enter number:");
    scanf("%d", &num);
//CONTROLLING THE RANGE.
    if(num<23 || num>98760){
        printf("Not in range!!!!");
    }
    else{
        int suc = 0;

        int count = 1;
//DIVIDING ALWAYS THE NUMBER TO 10.
        while (suc != 1) {
            if (count == 1) digit1 = num % 10;
            if (count == 2) digit2 = num % 10;
            if (count == 3) digit3 = num % 10;
            if (count == 4) digit4 = num % 10;
            if (count == 5) digit5 = num % 10;
            count++;
            num = num - num % 10;
            num = num / 10;
            if (num < 1) suc = 1;
        }
//PRINTING THE NUMBER DIGITS BY DIGITS.
        if (digit5 != -1)
            printf("The fifth digit is %d\n", digit5);
        if (digit4 != -1)
            printf("The fourth digit is %d\n", digit4);
        if (digit3 != -1)
            printf("The third digit is %d\n", digit3);
        if (digit2 != -1)
            printf("The second digit is %d\n", digit2);
        if (digit1 != -1)
            printf("The first digit is %d\n", digit1);
        return 0;
    }
}