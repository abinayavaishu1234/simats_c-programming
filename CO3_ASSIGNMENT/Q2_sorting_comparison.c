#include <stdio.h>
#define N 8
typedef struct { long comparisons, moves; } Stats;
void bubble(int a[], Stats *s) {
    s->comparisons=s->moves=0;
    for(int i=0;i<N-1;i++) {
        int swapped=0;
        for(int j=0;j<N-1-i;j++) {
            s->comparisons++;
            if(a[j]>a[j+1]) { int t=a[j]; a[j]=a[j+1]; a[j+1]=t; s->moves+=3; swapped=1; }
        }
        if(!swapped) break;
    }
}
void selection(int a[], Stats *s) {
    s->comparisons=s->moves=0;
    for(int i=0;i<N-1;i++) {
        int min=i;
        for(int j=i+1;j<N;j++) { s->comparisons++; if(a[j]<a[min]) min=j; }
        if(min!=i) { int t=a[i]; a[i]=a[min]; a[min]=t; s->moves+=3; }
    }
}
void insertion(int a[], Stats *s) {
    s->comparisons=s->moves=0;
    for(int i=1;i<N;i++) {
        int key=a[i], j=i-1;
        while(j>=0) {
            s->comparisons++;
            if(a[j]>key) { a[j+1]=a[j]; s->moves++; j--; }
            else break;
        }
        a[j+1]=key; s->moves++;
    }
}
void run(const char *label, int input[N]) {
    int a[N]; Stats s;
    for(int i=0;i<N;i++) a[i]=input[i];
    bubble(a,&s); printf("%s | Bubble: comparisons=%ld swaps/moves=%ld\n",label,s.comparisons,s.moves);
    for(int i=0;i<N;i++) a[i]=input[i];
    selection(a,&s); printf("%s | Selection: comparisons=%ld swaps/moves=%ld\n",label,s.comparisons,s.moves);
    for(int i=0;i<N;i++) a[i]=input[i];
    insertion(a,&s); printf("%s | Insertion: comparisons=%ld shifts/moves=%ld\n",label,s.comparisons,s.moves);
}
int main(void) {
    int sorted[N]={1,2,3,4,5,6,7,8};
    int nearly[N]={1,2,3,5,4,6,7,8};
    int reverse[N]={8,7,6,5,4,3,2,1};
    int randomish[N]={4,1,7,3,8,2,6,5};
    run("Sorted",sorted); run("Nearly sorted",nearly);
    run("Reverse sorted",reverse); run("Mixed",randomish);
    return 0;
}