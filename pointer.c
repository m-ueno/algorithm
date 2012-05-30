#include<stdio.h>
#include<string.h>

int main(int ac, char *av[])
{
    int i=1, j=2;
    int *p;
    int **pp;

    printf("start\n");
    p = &i;
    pp = &(p);

    printf("i %d, j %d, *p %d, **p %d\n", i,j,*p, **pp);

//    *p = j; // [i,j,*p] = [2,2,2]
    *pp = &j; // [i,j,*p] = [1,2,2]

    printf("i %d, j %d, *p %d, **p %d\n", i,j,*p, **pp);

    return 0;
}

