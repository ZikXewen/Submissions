#include <cstdio>
#include <algorithm>
const int X = 3;
struct Person{
    int id, f1, f2, sm, fn, to;
    char nm[15];
    double gd;
} ar[X];
int main(){
    for(int i = 0; i < X; ++i){
        printf("--------------\nStudent #%d\n-------------\n", i + 1);
        printf("Enter ID: "); scanf("%d", &ar[i].id);
        printf("Enter Name: "); scanf("%s", ar[i].nm);
        printf("Enter Formative 1 Score (25): "); scanf("%d", &ar[i].f1);
        printf("Enter Formative 2 Score (25): "); scanf("%d", &ar[i].f2);
        printf("Enter Summative Score (20): "); scanf("%d", &ar[i].sm);
        printf("Enter Finals Score (30): "); scanf("%d", &ar[i].fn);
        ar[i].to = ar[i].f1 + ar[i].f2 + ar[i].sm + ar[i].fn;
        if(ar[i].to < 50) ar[i].gd = 0;
        else ar[i].gd = std::min(4.0, double((ar[i].to - 40) / 5) / 2);
    }
    for(int i = 0; i < X; ++i){
        printf("------------------------\nID: %d\tName: %s\nFor1: %d  For1: %d  Sum: %d  Fin: %d\nTotal: %d\tGrade: %.2lf\n",
        ar[i].id, ar[i].nm, ar[i].f1, ar[i].f2, ar[i].sm, ar[i].fn, ar[i].to, ar[i].gd);
    }
}