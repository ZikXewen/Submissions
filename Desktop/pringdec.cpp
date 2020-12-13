#include <cstdio>
using namespace std;
const int X = 10;
int lef[X] = {10, 15, 25, 10, 10, 20, 50, 10, 20, 30};
int prc[X] = {7, 2, 4, 9, 7, 4, 5, 10, 9 ,4};
int car[X];
char flo[X][20] = {"Marigold", "Tulip", "Lotus", "Rose", "Sunflower", "Carnation", "Sakura", "Jasmine", "Orchids", "Daisy"};
void addline(int x = 1){ while(x--) printf("\n"); }
int choice(char x[100] = "Enter your choice"){ 
    int ret;
    addline(2);
    printf("%s: ", x);
    scanf("%d", &ret);
    return ret;
}
void err(){ choice("\n\nError occured. Please check your input(s).\n\nEnter any number to continue"); }
bool chk(){
    for(int i = 0; i < X; ++i) if(lef[i] or car[i]) return 1;
    return 0;
}
int main(){
    while(1){
        addline(20);
        if(!chk()){
            choice("We are closed today. Please come back and check our shop later.\n\nEnter any number to terminate the program"); 
            return 0;
        }
        printf("===Main Menu===\n 1. View Stock / Add to Cart\n 2. View Cart / Remove Items\n 3. Checkout\n 4. Exit");
        int in = choice();
        switch(in){
            case 1: {
                addline(20);
                printf("===Flowers In Stock===\n\n");
                for(int i = 0; i < X; ++i) printf("%d. %s:\t %d THB\t\t%d Remaining.\n", i + 1, flo[i], prc[i], lef[i]);
                printf("\nType in its number to add into cart. Type 0 to cancel.");
                int temi = choice(); 
                if(!temi) break;
                --temi;
                int temi2 = choice("How much?");
                if(temi < 0 or temi > X or temi2 > lef[temi]) {err(); break;}
                car[temi] += temi2; lef[temi] -= temi2;
                break;
            } case 2: {
                addline(20);
                printf("===Flowers In Cart===\n\n");
                for(int i = 0; i < X; ++i) printf("%d. %s:\t %d THB\t\t%d in cart.\n", i + 1, flo[i], prc[i], car[i]);
                printf("\nType in its number to edit the cart. Type 0 to go back.");
                int temi = choice(); 
                if(!temi) break;
                --temi;
                int temi2 = choice("How much?");
                if(temi < 0 or temi > X or temi2 > car[temi]) {err(); break;}
                car[temi] -= temi2; lef[temi] += temi2;
                break;
            } case 3: {
                addline(20);
                printf("===Check Out===\n\n");
                int sm = 0;
                for(int i = 0; i < X; ++i){
                    if(car[i]) printf("%d. %s:\t %d THB\t\t%d in cart.\t-- %d total.\n", i + 1, flo[i], prc[i], car[i], car[i] * prc[i]);
                    sm += car[i] * prc[i];
                }
                addline();
                printf("Total cost: %d THB", sm);
                int temi = choice("Enter cash (Enter 0 to go back.)");
                if(temi == 0) break;
                if(temi < sm) {err(); break;}
                printf("\n\n------------------------------\n\n");
                if(temi - sm) printf("Here is the change, %d THB.", temi - sm);
                printf("Thank you for the purchase");
                addline(2);
                printf("Terminate the program? (y/n): ");
                char temc;
                scanf(" %c" ,&temc);
                if(temc == 'y' or temc == 'Y') return 0;
                else if(temc != 'n' and temc != 'N') err();
                break;
            } case 4: {
                printf("\nTerminate the program?");
                bool temb = 0;
                char temc;
                for(int i = 0; i < X; ++i) if(car[i]) {temb = 1; break;}
                if(temb) printf(" (Existing cart will not be saved.)");
                printf(" (y/n): "); scanf(" %c", &temc);
                if(temc == 'y' or temc == 'Y') return 0;
                else if(temc != 'n' and temc != 'N') err();
            }
        }
    }
}