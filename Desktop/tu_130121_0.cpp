#include <cstdio>
int main(){
    int X; 
    printf("Programe show max@min number\nEnter N Number : "); scanf("%d", &X);

    int ar[X], mx, mn;
    for(int i = 0; i < X; ++i){
        printf("x[%d] = ", i + 1);
        scanf("%d", &ar[i]);
    }
    mx = mn = ar[0];
    for(int i = 0; i < X; ++i) {
        if(ar[i] < mn) mn = ar[i];
        if(ar[i] > mx) mx = ar[i];
    }
    printf("Maximum = %d\n\nMinmum = %d", mx, mn);
}