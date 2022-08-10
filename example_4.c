#include <stdio.h>

int main(void){
    int a = -1;
    unsigned int b =a ;
    printf("%#0x\n",a);
    printf("%#0x\n",b);
    printf("%d\n",a);
    printf("%d\n",b);

    if(a < 0){
        puts("a < 0");
    }else{
        puts("a >= 0");
    }

    if(b < 0){
        puts("b < 0");
    }else{
        puts("b >= 0");
    }
}