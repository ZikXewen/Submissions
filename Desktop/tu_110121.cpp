#include <cstdio>
#include <cstring>
char nm[30], ls[30], str[201];
void scanbook(){
    char tmp[201];
    while(scanf("%s", tmp) and strcmp(tmp, "--") != 0)
        strcat(str, tmp), strcat(str, " ");
}
void cls(){
    for(int i = 0; i < 20; ++i) putchar('\n');
}
int cont(){
    int tmp;
    printf("\n\n\nEnter 0 to end program. Enter any other integer to continue: ");
    scanf("%d", &tmp);
    return tmp;
}
void init(){
    cls(); str[0] = '\0';
}
int main(){
    do{
        printf("Enter your first name: "); scanf("%s", nm);
        printf("Enter your last name: "); scanf("%s", ls);
        printf("Enter your book entry (< 200 words)\n*** To finish your entry, enter -- \n"); scanbook();
        cls();
        printf("%s %s\'s Entry:\n%s", nm, ls, str);
    } while(cont());
}