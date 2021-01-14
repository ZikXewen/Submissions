#include <bits/stdc++.h>
using namespace std;
void printAll(char name[20], char content[200]){
    printf("\n\n");
    printf("NAME : %s", name);
    printf("CONTENT : %s\n\n", content);
}
int main(){
    while(true){
        char name[20];
        char content[200];
        char check[4];

        printf("INPUT NAME : ");
        fgets(name, sizeof(name), stdin);
        
        printf("INPUT CONTENT : ");
        fgets(content, sizeof(content), stdin);
        
        printAll(name, content);
        
        printf("DO YOU WANT TO CONTINUE? (yes/no) : ");
        fgets(check, sizeof(check), stdin);
        
        if(strcmp(check, "yes") != 0) break;
        getchar();
    }
}