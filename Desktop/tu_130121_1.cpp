#include <cstdio>
#include <cstring>
char str[6969];
int main(){
    while(1){
        printf("Enter a string (enter ---- to exit): "); scanf("%s", str);
        if(strcmp(str, "----") == 0) break;
        printf("String length is\t= %d\n1st character\t= %c\nlast character\t= %c\n", strlen(str), str[0], str[strlen(str) - 1]);
    }
}