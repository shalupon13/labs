#include "lr.h"

int main(){
    int number, dop;
    printf("Select a number: ");
    scanf("%i", &number);
    printf("With dop? (0-no, 1-yes)");
    scanf("%i", &dop);
    

    switch (number){
        case 1:
            lab1();
            break;
        case 2:
           if (dop == 0) lab2();
           else dop2();
            break;
        case 3:
            if (dop == 0) lab3();
            else dop3();
            break;
        case 4:
            if (dop == 0) lab4();
            else dop4();
            break;
        case 5:
            if (dop == 0) lab5();
            else dop5();
            break;
        case 6:
            if (dop == 0) lab6();
            else dop6();
            break;
        case 7:
            if (dop == 0) lab7();
            break;

    }
    return 0;
}
