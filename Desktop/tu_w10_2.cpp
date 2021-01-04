#include <cstdio>
double in[5], sm;
int main(){
    printf("Enter 5 numbers...\n");
    for(int i = 0; i < 5; ++i) scanf("%lf", &in[i]);
    for(int i = 0; i < 5; ++i) sm += in[i];
    printf("\nThe sum is...\n%.2lf\n\nThe mean is...\n%.2lf", sm, sm / 5);
}