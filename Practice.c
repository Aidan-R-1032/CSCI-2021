#include <stdio.h>

/// @brief 
/// @param arr_of_ints 
/// @param size 
/// @return 
int *divisible_by_5(int *arr_of_ints, int size){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(arr_of_ints[i] % 5 == 0){
            count++; 
        }
    }
    return &count;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int *a = &arr[2];
    *a = 15;
    int *count = divisible_by_5(arr,10);
    printf("count: %d\n", *count);
}