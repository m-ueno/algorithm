#include <stdio.h>

int main()
{
    int *po , var;
    var = 10101;
    po = &var;

    printf("ポインタに格納されている内容 = %d\n" , *po);
    printf("ポインタに格納されているアドレス = %x" , po);

    return 0;
}
