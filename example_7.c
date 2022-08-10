#include <stdio.h>

int main(void){
    int i;
    for(i = 0; i < 3; i+=1){
        printf("for %d\n", i);
    }
    i = 0;
    while (i < 3)
    {
        printf("while: %d\n", i);
        i += 1;
    }
    i = 0;
    do{
        printf("do: %d\n", i);
        i += 1;
    }while (i < 3);
}