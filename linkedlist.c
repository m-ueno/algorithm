#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list {
    int item;
    struct list *next;
} list;

void append_list(int n, list **L) {
    list *new;

    new = (list *)malloc(sizeof(list));
    new->item = n;
    new->next = 1 ? *L : NULL; /* !! */
    *L = new;                   /* This is why '**L' is need */
}

list *predecessor_list(int n, list *L) {
//    printf("L:%d, next:%d\n",L,L->next);
    if ((L==NULL) || (L->next == NULL)) {
//        printf("Error: predecessor sought on null list.\n");
        return(NULL);
    }
    if ((L->next)->item == n)
        return(L);
    else
        return( predecessor_list(n, L->next) );
}

void insert_list(int n, list **L) {
    /* min first: [1,2,4,6,dummy,NULL] */
    list *new, *pred;

    if ( (*L)->next==NULL ) {
        new = (list *)malloc(sizeof(list));
        new->item = n;
        new->next = *L;

        *L = new;
        printf("insert:%d\n", n);
        return;
    }

    if ( (*L)->item < n ) {
        new = (list *)malloc(sizeof(list));
        new->item = n;
        new->next = *L;

        pred = predecessor_list(n, (*L));
        if (pred == NULL) { /* new is minimum */
            *L = new;
            printf("*L is renewed\n");
        } else {
            pred->next = new;
            printf("*L is not change...\n");
        }
        printf("insert:%d\n", n);
        return;
    }
    insert_list( n, &((*L)->next) );
}

void traverse_list (list *L, void (*fn)()) {
    if (L==NULL) {
        printf("\nend of list -- traverse\n");
        return;
    }
    fn(L);
    traverse_list(L->next, fn);
}

void _print_simple (list *L) {
    printf("%d ", L->item);
}

void print_list_simple (list *L) {
    printf("** print_list_simple **\n");
    traverse_list(L, _print_simple);
}

void print_list(list *L) {
    if (L==NULL) {
        printf("end of list\n");
        return;
    }

    printf("item: %d, L:%d, next: %d\n", L->item, L, L->next);
    print_list(L->next);
}

list *search_list(int n, list *L) {
    printf("L:%d, L==NULL:%d\n", L, L==NULL);
    if (L==NULL) {
        printf("NOT FOUND:%d\n",n);
        return(NULL);
    }

    if (L->item == n) {
        printf("FOUND: %d\n", n);
        return(L);
    }
    else
        return( search_list(n, L->next) );
}
/* ****************
/* test
/* **************** */
void test_insert_list() {
    list *L;
    int i;

    L = (list *)malloc(sizeof(list));
    for(i=0;i<100;i++)
        insert_list(rand()%100+1, &L);
//        insert_list(100-i, &L);

    print_list_simple(L);
}

void main(){
    list *L;
    int i, k;

    test_insert_list();
    return;


//    srand((unsigned)time(NULL));
    srand(1);
    printf("sizeof int: %d\n", sizeof(int));
    printf("sizeof list: %d\n", sizeof(list));

//    printf("\n** print_list **\n");
//    print_list(L);


    L = (list *)malloc(sizeof(list));
    L->item = -666;

    for (i=0; i<10; i++) {
        k = rand() % 10 + 1;
        printf("append: %d\n", k);
        append_list( k, &L );
    }

    printf("\n** print_list **\n");
    print_list(L);

    printf("\n** search **\n");
    printf("search: %d\n", search_list(5, L));

}
