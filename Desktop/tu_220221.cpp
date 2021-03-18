#include <cstdio>
struct one{
    double x, y;
} a[3];
double an;
int main(){
    printf("Enter triangle data: \n");
    for(int i = 0; i < 3; ++i){
        printf("Point %d X: ", i + 1); scanf("%lf", &a[i].x);
        printf("Point %d Y: ", i + 1); scanf("%lf", &a[i].y); 
    }
    for(int i = 0; i < 3; ++i) 
        an += a[i].x * (a[(i + 1) % 3].y - a[(i + 2) % 3].y) / 2;
    if(an <= 0) an = -an;
    printf("%.2lf", an);
}