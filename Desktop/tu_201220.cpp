#include <cstdio>
int rec(int x){
    if(!x) return 0;
    return x + rec(x - 1);
}
int main(){
    int N;
    scanf("%d", &N);
    printf("%d", rec(N));
}