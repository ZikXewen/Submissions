#include <cstdio>
double rec(int x = 30){
    if(x == 0) return 10000;
    return rec(x - 1) * 1.05;
}
int main(){
    printf("%lf", rec());
}