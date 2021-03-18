#include <cstdio>
struct Person{
    char nm[15];
    int ag;
    double he, we, bmi;
};
int main(){
    int X; 
    printf("Enter numbers of students: "); scanf("%d", &X);
    Person ar[X];
    for(int i = 0; i < X; ++i){
        printf("--------------\nStudent #%d\n-------------\n", i + 1);
        printf("Enter Name: "); scanf("%s", ar[i].nm);
        printf("Enter Age: "); scanf("%d", &ar[i].ag);
        printf("Enter Height: "); scanf("%lf", &ar[i].he);
        printf("Enter Weight: "); scanf("%lf", &ar[i].we);
        ar[i].bmi = ar[i].we * 1e4/ ar[i].he / ar[i].he;
    }
    for(int i = 0; i < X; ++i)
        printf("--------------\n#%d: %s\t\tAge: %d\nWeight: %.2lf\tHeight: %.2lf\tBMI: %.2lf\n%s\n", 
        i + 1, ar[i].nm, ar[i].ag, ar[i].we , ar[i].he, ar[i].bmi, (ar[i].bmi < 20 || ar[i].bmi > 25)? "Dangerous BMI" : "Normal BMI");
}