#include<stdio.h>
#include<stdlib.h>

#define N 50000

void ssort(int *a, int n) {
    int i,j,temp;
    for (i=0;i<n;i++) {
        for (j=i+1; j<n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(int ac, char *av[]) {
    int i, a[N];

    srand(1);

    for(i=0;i<N;i++) {
        a[i] = rand() % 1000;
//        printf("%d ",a[i]);
    }
    printf("\n\n");

    printf("size:%d\n", sizeof(a)/sizeof(a[0]) );
    
    ssort( a, sizeof(a)/sizeof(a[0]) );
    /* for(i=0;i<N;i++)
     *     printf("%d ",a[i]); */

    printf("\n");


    return 0;
}

