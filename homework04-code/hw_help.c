#include <stdio.h>

int main(){
int x = 9;
switch(x) {
  case 0:
    printf("Hello!\n");
    break;
  case 1:
    printf("World!\n");
    break;
  case 9:
    printf("CSCI\n");
  case 8:
    printf("2021\n");
  default:
    printf("Fall 2022\n");
}
    return 0;
}