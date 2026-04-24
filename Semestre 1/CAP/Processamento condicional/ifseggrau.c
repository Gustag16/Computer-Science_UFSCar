// Descrição: Apresentar se há ou não duas raízes reais distintas em uma equação do segundo grau
// Requer: Os valores de a, b e c da equação do segundo grau
// Assegura: Apresentação da mensagem se há ou não duas raízes reais

#include <stdio.h>
#include <math.h>

int main(){
    char entrada[160];
    printf("Insira os valores de a, b e c: ");
    fgets(entrada, sizeof entrada, stdin);
    double a, b, c;
    sscanf(entrada, "%lf%lf%lf", &a, &b, &c);

    double delta = pow(b,2) - 4*a*c;

    if (delta > 0 && a != 0) {
        printf("Há\n");
    }
    else {
        printf("Não há\n");
    }

    return 0;
}

/* OU:

int main() {
    char entrada[160];
    printf("Insira os valores de a, b e c: ");
    fgets(entrada, sizeof entrada, stdin);
    double a, b, c;
    sscanf(entrada, "%lf%lf%lf", &a, &b, &c);

    if (a == 0) {
        printf("Não há");
    }
    else {
        delta = pow(b,2) - 4*a*c;
        if (delta > 0){
            printf("Há");
        }
        else {
            printf("Não há")
        }
    }

return 0;
}
*/