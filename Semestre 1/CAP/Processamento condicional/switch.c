#include <stdio.h>

int main(){
    char c = 'X';

    switch (c) {
        // um 'printf' aqui resultaria em erro, pois nunca seria executado
        case 'A':
            printf("1\n");
            printf("2\n");
            printf("3\n");
            printf("4\n");
            break;
        case 'B':
            printf("5\n");
            printf("6\n");
            printf("7\n");
            break;
        case 'C':
            printf("8\n");
            break;
        default:
            printf("NDA\n");
    }

    return 0;
}