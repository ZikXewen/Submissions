#include <cstdio>
int ar[5][3], sm[5];
double grd(int x){
    if(x < 50) return 0;
    if(x >= 80) return 4;
    return double((x - 40) / 5) / 2;
}
int main(){
    for(int i = 0; i < 5; ++i) for(int j = 0; j < 3; ++j){
        printf("Student ID: %d\n", i + 1);
        if(j == 0) printf("Formative 1 & 2 (60 pts) : ");
        else if(j == 1) printf("Summative (20 pts) : ");
        else printf("Finals (20 pts) : ");
        scanf("%d", &ar[i][j]);
        sm[i] += ar[i][j];
    }
    for(int i = 0; i < 5; ++i){
        printf("Student ID: %d\nTotal Score: %d\nGrade: %.1lf\n\n", i + 1, sm[i], grd(sm[i]));
    }
    // for(int i = 0; i <= 100; ++i) printf("%d %.1lf\n", i, grd(i));
}