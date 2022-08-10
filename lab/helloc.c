#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int hello1()
{
    return 76;
}

int hello2(int a)
{
    return a + hello1();
}

int main(void)
{
    char flag[19] = { 0 };
    int secret[5] = {8502, 13431, 10165, 6767, 11495};
    int key[5] = {109, 121, 107, 101, 121};

    flag[0] = 70;       //70: F
    flag[1] = hello1(); //76: L

    //flag[2]: 65: A
    //flag[3]: 71: G


    for (int i = 0; i < 2; ++i) {
        flag[2+i] = flag[0+i] - 5;
    }

    flag[4] = 66 ^ 57;  // use python 123:{
    
    //flag[5]:8502/109 = 78:N
    //flag[6]:13431/121 =111: o
    //flag[7]:10165/107 = 95: _
    //flag[8]:6767/101 = 67: C
    // flag[9]:11495/121 = 95: _
    for (int i = 0; i < 5; ++i) {
        flag[5 + i] = secret[i] / key[i];  //i -> 0,1,2,3,4
    }

    //flag[10] 76+2 = 78 : N
    flag[10] = hello2(2);
    // flag[11] 76+1 -29 =48 : 0
    flag[11] = hello2(1) - 29;

    // flag[12] = 48 & 0x80 =0 not run  else=> flag[7] =95= _
    if (flag[11] & 0x80) {
        flag[12] = flag[11];
    } else {
        flag[12] = flag[7];
    }
    //flag[13] = 76: L 
    flag[13] = hello2(0);
    //flag[14] = (76 * (76+8) = 6384 & 0xff)- 191 = 240 - 191 = 49: 1
    flag[14] = ((hello1() * hello2(8)) & 0xff) - 191;
    flag[15] = 'E'; //69
    flag[16] = 'v'; // 118
    flag[15] = flag[15] ^ flag[16]; // 69 ^ 118 = 51
    flag[16] = flag[15] ^ flag[16]; // 51 ^ 118 = 69 flag[16] = 69: E
    flag[15] = flag[15] ^ flag[16]; // 51 ^ 69 = 118 flag[15] = 118: v
    flag[17] = '}';

    // TODO: write some C code to output flag
    printf("%s\n", flag);

    return 0;
}
