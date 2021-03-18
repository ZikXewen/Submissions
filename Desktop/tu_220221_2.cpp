#include <cstdio>
#include <algorithm>
const int X = 5;

struct studentBirthday{
    int d, m, y, ag;
};
struct studentGrade{
    int f1, f2, sm, fn, to;
    double gd;
};
struct student{
    int id;
    char nm[15];
    studentBirthday bd;
    studentGrade gd;
} ar[X];

int main(){
    for(int i = 0; i < X; ++i){
        printf("--------------\nStudent #%d\n-------------\n", i + 1);
        printf("Enter ID: "); scanf("%d", &ar[i].id);
        printf("Enter Name: "); scanf("%s", ar[i].nm);
        
        printf("Enter Birthdate (Day Month Year): "); scanf("%d%d%d", &ar[i].bd.d, &ar[i].bd.m, &ar[i].bd.y);
        printf("Enter Age: "); scanf("%d", &ar[i].bd.ag);

        printf("Enter Formative 1 Score (25): "); scanf("%d", &ar[i].gd.f1);
        printf("Enter Formative 2 Score (25): "); scanf("%d", &ar[i].gd.f2);
        printf("Enter Summative Score (20): "); scanf("%d", &ar[i].gd.sm);
        printf("Enter Finals Score (30): "); scanf("%d", &ar[i].gd.fn);

        ar[i].gd.to = ar[i].gd.f1 + ar[i].gd.f2 + ar[i].gd.sm + ar[i].gd.fn;
        if(ar[i].gd.to < 50) ar[i].gd.gd = 0;
        else ar[i].gd.gd = std::min(4.0, double((ar[i].gd.to - 40) / 5) / 2);
    }
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\narray\n");
    for(int i = 0; i < X; ++i) printf(" |-[%d]\n | |-id: %d\n | |-name: %d\n | |-studentBirthday\n | | |-d: %d\n | | |-m: %d\n | | |-y: %d\n | | |-ag: %d\n | |-studentGrade\n | | |-f1: %d\n | | |-f2: %d\n | | |-sm: %d\n | | |-fn: %d\n | | |-to: %d\n | | |-gd: %.2lf\n", i, ar[i].id, ar[i].nm, ar[i].bd.d, ar[i].bd.m, ar[i].bd.y, ar[i].bd.ag, ar[i].gd.f1, ar[i].gd.f2, ar[i].gd.sm, ar[i].gd.fn, ar[i].gd.to, ar[i].gd.gd);
}