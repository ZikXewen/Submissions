#include <cstdio>
int main(){
    int ar[10];
    printf("Enter 10 numbers:\n");
    for(int i = 0; i < 10; ++i) scanf("%d", &ar[i]);

    int *mn = ar, *mx = ar;
    for(int i = 0; i < 10; ++i){
        if(ar[i] < *mn) mn = ar + i;
        if(ar[i] > *mx) mx = ar + i;
    }

    printf("Min: %d\nMax: %d", *mn, *mx);   
}