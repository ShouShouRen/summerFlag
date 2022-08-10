#include <stdio.h>

int func1(int a)
{
    return a + 1;
}

int main(void)
{
    int i = 10;
    i = func1(i);
    printf("%d\n",i);
}