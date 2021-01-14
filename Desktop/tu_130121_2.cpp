#include <cstdio>
#include <cstring>
int dif = 'A' - 'a';
char name1[20], name2[20], str1[20], str2[20] = "-", name4[20];
char tem[20];
char name5_1[20], name5_2[20];
void init(){
    tem[0] = '-';
    for(int i = 1; i < 20; ++i) tem[i] = '\0';
}
char* func1(char* in){
    for(int i = 0; i < strlen(in); ++i)
        if(in[i] <= 'z' && in[i] >= 'a') tem[i] = in[i] + dif;
        else tem[i] = in[i];
    return tem;
}
char* func2(char* in){
    strcpy(tem, in);
    for(int i = 0; i < strlen(in); ++i)
        tem[i] = in[strlen(in) - i - 1];
    return tem;
}
void func3(){
    strcpy(str2, str1);
}
void func4(char* in, char* out){
    strcpy(out, in);
}
char* func5(char* u, char *v){
    strcpy(tem, u);
    strcat(tem, v);
    return tem;
}
int main(){
    printf("Input 1: "); scanf("%s", name1); 
    printf("Function 1: %s -> %s\n", name1, func1(name1));
    
    init();
    printf("Input 2: "); scanf("%s", name2);
    printf("Function 2: %s -> %s\n", name2, func2(name2));
    
    init();
    printf("Input 3: "); scanf("%s", str1);
    printf("Function 3: %s %s -> ", str1, str2);
    func3();
    printf("%s %s\n", str1, str2);
    
    init();
    printf("Input 4: "); scanf("%s", name4);
    printf("Function 4: %s %s -> ", name4, tem);
    func4(name4, tem);
    printf("%s %s\n", name4, tem);
    
    init();
    printf("Input 5 (2 strings): "); scanf("%s %s", name5_1, name5_2);
    printf("Function 5: %s", func5(name5_1, name5_2));
}