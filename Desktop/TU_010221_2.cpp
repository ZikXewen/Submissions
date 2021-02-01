#include<cstdio>
int main(){
    char in[10], ps[10] = "123456";
    printf("Enter password (hint: 123456): "); scanf("%s", in);
    
    for(char *i = in, *j = ps; true; ++i, ++j){
        if(*i == '\0' && *j == '\0') break;
        if(*i == '\0' || *j == '\0' || *i != *j) {printf("Wrong password."); return 0;}
    }
    printf("Correct password.");
}