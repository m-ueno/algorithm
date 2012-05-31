#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int ac, char *av[])
{
    int a[5] = {5,4,3,2,1}, i,j, *p;

    p = a;

    printf("%d, %d\n", a, p);
    printf("%d, %d\n", &a, &p);
    printf("%d, %d\n", *a, *p);
    printf("%d, %d\n", a[0], p[0]);

    printf("%d, %d\n", a+2, p+2);
    printf("%d, %d\n", *(a+2), *(p+2));

/*
    for(i=0;i<5;i++)
        printf("i:%d, a[i]:%d, *(p+i):%d, a->i:%d\n", i, a[i], *(p+i), a->i);
*/
    return 0;
}

