#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define N 1000000
#define NOTFOUND -1

typedef struct {
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
    left = (2*n <= H->n) ? H->q[2*n] : min+1;
    right = (2*n+1 <= H->n) ? H->q[2*n + 1] : min+1;

//    printf("[%d, %d, %d, %d] -- bubbledown\n", n, min, left, right);

    if (left < min)
        min = left;
    if (right < min)
        min = right;

    if (min == H->q[n]) {
//        printf("stop bubbling down\n");
        return;
    }
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

void delete (int idx, heap *H) {
    if (H->n < idx) {
        printf("Error: H->n < idx -- delete\n");
        return;
    }

    H->q[idx] = H->q[H->n];
    bubble_down(idx, H);
    H->n -= 1;
}

int extract_min(heap *H) {
    int min = NOTFOUND;

    if (H->n <= 0) return(min);

    min = H->q[1];
    delete(1, H);
    return(min); // for debug
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

void heap_sort(int *a, int n) {
    int i;
    heap *H;

    H = make_heap1(a, n);

    for(i=0;i<n;i++)
        a[i] = extract_min(H);
}

void test_delete() {
    heap *h;
    int a[N];
    int i;

    srand(1);

    for(i=0;i<N;i++)
        a[i] = rand()%N+1;

    printf("\n** a **\n");
    for(i=0;i<N;i++) printf("%d ",a[i]);
    printf("\n");

    h = make_heap1(a, sizeof(a)/sizeof(a[0]));

    printf("\n** h->q **\n");
    for(i=1;i<=h->n;i++) printf("%d ",h->q[i]);
    printf("\n\nok\n\n");

    printf("min: %d\n", h->q[1]);
    printf("deleted: %d, n:%d\n", extract_min(h), h->n);
    printf("min: %d\n", h->q[1]);
    printf("deleted: %d, n:%d\n", extract_min(h), h->n);
    printf("min: %d\n", h->q[1]);
    printf("deleted: %d, n:%d\n", extract_min(h), h->n);
    printf("min: %d\n", h->q[1]);

    printf("\n** h->q **\n");
    for(i=1;i<=h->n;i++) printf("%d ",h->q[i]);
    printf("\n");

    return;
}

void test_heap_sort () {
    heap *h;
    int i;
    int a[N];

    srand(1);

    for(i=0;i<N;i++)
        a[i] = rand()%N+1;

    printf("\n** a **\n");
    for(i=0;i<N;i++) printf("%d ",a[i]);
    printf("\n");

    heap_sort(a, sizeof(a)/sizeof(a[0]));
    printf("\n** heap_sort **\n");
    for(i=0;i<N;i++) printf("%d ",a[i]);
    printf("\n");

}

void main () {
    test_heap_sort();
}
