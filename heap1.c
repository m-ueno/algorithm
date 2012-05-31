#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define N 100
#define NOTFOUND -1
#define INFTY 1e9
typedef struct {                /* 要はただの配列 */
    int q[N+1];                 /* index: 1,2,...,N */
    int n;
} heap;

void bubble_up (int n, heap *H) {
    int parent, this, temp;

    if (n<=1)
        return;

    this = (H->q)[n];
    parent = (H->q)[n/2];

    if (this < parent) {
//        printf("bubble up %d < %d\n", H->q[n], H->q[n/2]);

        (H->q)[n] = parent;
        (H->q)[n/2] = this;
        bubble_up(n/2, H);
    }
//    printf("stop: %d >= %d\n", H->q[n], H->q[n/2]);
}

void insert (int item, heap *H) {
    (H->q)[H->n+1] = item;
    bubble_up(H->n, H);

    H->n += 1;
}

void bubble_down (int n, heap *H) {
    int i, min, min_idx, left, right;
    int temp;

    min = H->q[n];
    left = (2*n <= H->n) ? H->q[2*n] : INFTY;
    right = (2*n+1 <= H->n) ? H->q[2*n + 1] : INFTY;

    if (left < min)
        min = left;
    if (right < min)
        min = right;

    if (min == n)
        return;
    else if (min == left) {
        temp = H->q[n];
        H->q[n] = H->q[2*n];
        H->q[2*n] = temp;
        bubble_down(2*n, H);
    } else if (min == right) {
        temp = H->q[n];
        H->q[n] = H->q[2*n+1];
        H->q[2*n+1] = temp;
        bubble_down(2*n+1, H);
    }
}

void delete (int n, heap *H) {

}

int search (int n, heap *H) {
    /* O(N) */
    int i;
    for (i=1; i<N+1; i++)
        if ((H->q)[i] == n)
            return(i);

    return(NOTFOUND);
}


heap *make_heap1 (int *a, int n) {
    heap *H;
    int i;

    H = (heap *)malloc(sizeof(heap));
    H->n = 0;

    for (i=0; i<n; i++)
        insert(a[i], H);
    return H;
}

void main() {
    heap *h;
    int a[N];
    int i;

    srand(1);

    for(i=0;i<N;i++)
        a[i] = rand()%N+1;

    for(i=0;i<N;i++) printf("%d ",a[i]);
    printf("\n");

    h = make_heap1(a, sizeof(a)/sizeof(a[0]));

    printf("\n** make_heap **\n");
    for (i=1;i<N+1;i++) {
        if (i == 2 || i==4 || i==8 || i==16 || i==32 || i==64)
            printf("\n");
        printf("%d ",h->q[i]);
    }
    printf("\n");

}
