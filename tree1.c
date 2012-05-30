#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define N 10
#define NOTFOUND -1

typedef struct tree {
    int item; // limited for int item, both pointer and non-pointer is ok
    struct tree *parent;
    struct tree *left;
    struct tree *right;
} tree;

tree *find_min(tree *);

tree *search(int n, tree *T) {
    if (T==NULL) {
        printf("NOTFOUND:%d\n", n);
        return(NULL);
    }

    printf("T->item: %d, T:%d -- search\n", T->item, T);
    if (n == T->item) {
        printf("FOUND:%d\n", n);
        return(T);
    }

    if (n < T->item)
        return(search(n, T->left));
    else
        return(search(n, T->right));
}

void _delete(int n, tree *T, int free_flag) {
    tree *target, *parent, *l, *r, *min;
    tree **parentpointer;

    target = search(n, T);
    if (target==NULL) return;

    if (target->parent==NULL) {
        /* dummy parent */
        parent = (tree *)malloc(sizeof(tree));
        parent->left = NULL;
        parent->right=NULL;
    } else {
        parent = target->parent;
    }

    if (target->parent && target == target->parent->left)
        parentpointer = &(parent->left);
    else
        parentpointer = &(parent->right);

    l = target->left;
    r = target->right;

    if (l==NULL && r==NULL) {
        *parentpointer = NULL;
    } else if (l==NULL) {
        *parentpointer = r;
    } else if (r==NULL) {
        *parentpointer = l;
    } else {
        min = find_min(target->right);
        _delete(min->item, T, 0); /* min has 0 or 1 child => easy to delete */
        *parentpointer = min;
        min->left = target->left;
        min->right = target->right;
    }

    if (free_flag) {
        printf("free!\n");
        free(target);
    }
}

void delete (int n, tree *T) {
    _delete(n,T,1);
}

tree *find_min(tree *T) {
    tree *child;
    if (T==NULL) {
        printf("Error -- find_min\n");
        return(NULL);
    }

    child = T;
    while (child->left)
        child = child->left;
    return(child);
}

void insert(int n, tree **T, tree *parent) {
    /* First Search, second insert */
    tree *p;

    if (*T==NULL) {
        p = (tree *)(malloc(sizeof(tree)));
        p->item = n;
        p->left = p->right = NULL;
         p->parent = parent;
        *T = p;
        return;
    }
//    printf("n: %d, tree:%d, parent:%d\n", n, *T, (long)parent%1000);

    if (n < (*T)->item)
        insert(n, &((*T)->left), *T);
    else
        insert(n, &((*T)->right), *T);
}

void print_tree(tree *T) {
    if (T==NULL) {
//        printf("** FINISH **\n");
        return;
    }
//    printf("T->item: %d, left: %d, right: %d\n", T->item, T->left, T->right);
    print_tree(T->left);
    printf("%d ", T->item);
    print_tree(T->right);
}

void traverse(tree *T, void (*fn)()) {
    if (T==NULL) return;

    traverse(T->left, fn);
    fn(T);
    traverse(T->right, fn);
}

void _print(tree *T) {
    printf("%d ", T->item);
}

void print_tree2(tree *T) {
    traverse(T, _print);
    printf("\n");
}

void main() {
    int i,j,*po;
    long u;
    tree *T;

//    srand((unsigned)time(NULL));
    srand(1);
    T = NULL;
    printf("size:%d\n",sizeof(T));
    printf("size:%d\n",sizeof(po));
    printf("size:%d\n",sizeof(u));

//    T = (tree *)(malloc(sizeof(T)));

    insert(50, &T, NULL);
    for(i=0;i<N;i++)
        insert(rand() % 100, &T, T);

    printf("\n** print2 **\n");
    print_tree2(T);

    printf("\n** delete **\n");
    delete(77, T);

    printf("\n** print2 **\n");
    print_tree2(T);


}
