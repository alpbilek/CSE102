/*161044049
 * ALP EMİR BİLEK
 * HW08_PART2
 */
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#define size1 6
//DEFINING RECURSION FUNCTION
char *find_operation(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current);
int main() {
    int arr[] = {25, 12, 6, 10, 32, 8};
    char op[size1];
    int i = 0;
    int j = 0;
    char * control = NULL;
    control = find_operation(arr, 44, op, size1, 1, arr[0]);
    if(control == NULL  ){
        printf("bulunamadi");
    }
    else{
        for(i = 0; i<size1; ++i){
            if(i == 0){
                for(j=0; j<size1-1; ++j ){
                    printf("(");
                }
                printf("%d %c %d)",arr[i],op[i],arr[i+1]);
                ++i;
            }
            else{
                printf(" %c %d)",op[i-1],arr[i]);
            }
        }
    }
return 0;
}
//CHECKING THE FUNTION IF IT IS OKEY OR CONTINUE.
bool isOkey(char *op, int size) {
    if (op[size - 1] == '\0')
        return true;
    return false;
}
char *find_operation(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current) {
//THE BASE CASE
    if (expected_val == current && arr_len == cursor) {
        operations[cursor - 1] = '\0';
        return operations;
    }
    if (cursor >= arr_len) {
        operations[cursor - 2] = 'x';
        return operations;
    }
    int c = cursor - 1;
//MULTIPLE OPERATION.
    int res = current * arr[cursor];
    operations[c] = '*';
    find_operation(arr, expected_val, operations, arr_len, cursor + 1, res);
    if (isOkey(operations, arr_len) == true) {
        return operations;
    }
//ADDITION OPERATION.
    res = current + arr[cursor];
    operations[c] = '+';
    find_operation(arr, expected_val, operations, arr_len, cursor + 1, res);
    if (isOkey(operations, arr_len) == true) {
        return operations;
    }
//SUBSTRACTE OPERATION.
    res = current - arr[cursor];
    operations[c] = '-';
    find_operation(arr, expected_val, operations, arr_len, cursor + 1, res);
    if (isOkey(operations, arr_len) == true) {
        return operations;
    }
}