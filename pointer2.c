#include<stdio.h>
#include<string.h>

void main(int ac, char *av[])
{
    int i=1, j=2;
    int *p, **pp, ***ppp;

    p = NULL;
    pp = &p;
    ppp = &pp;

    printf("%d, %d, %d\n", p, *pp, **ppp);

}








