#include<stdio.h>
#include<stdlib.h>

#define N 5

int * _merge(int *a, int m, int *b, int n) {
    int *ret, idx, i, j;

    idx = i = j = 0;
    printf("%d, %d -- merge\n", m,n);

    ret = (int *)malloc(sizeof(int)*(m+n));

    printf("mallocated\n");

    while (m>0 && n>0) {
        if (a[i] < b[j]) {
            ret[idx++] = a[i++];
            m--;
        }
        else {
            ret[idx++] = b[j++];
            n--;
        }
    }

    if (m==0)
        while (j<n)
            ret[idx++] = j++;
    else
        while (i<m)
            ret[idx++] = i++;

    return(ret);
}

int *merge_sort (int *a, int low, int high) {
    int mid;
    printf("[low,high] = [%d,%d]\n", low, high);
    if (high-low <=0)
        return(a+low);
    mid = (high - low)/2;
    printf("mid:%d\n", mid);

    return( _merge( merge_sort(a,low,mid), mid-low+1,
                    merge_sort(a,mid+1,high), high-mid ) );
}

void main() {
    int a[N], *ret_a;
    int i,k;

    srand(1);

    printf("start\n");

    for(i=0;i<N;i++){
        k = rand()%N + 1;
        printf("%d ",k);
        a[i] = k;
    }
    printf("\n");

    ret_a = merge_sort(a, 0, N-1);
}

