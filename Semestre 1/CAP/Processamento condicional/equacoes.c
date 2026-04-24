// Descrição: Determinação, dados os coeficientes, das raízes reais de uma equação ax² + bx + c = 0,
//    nunca sendo a e b simultaneamente nulos.
// Requer: valores de a, b, c
// Assegura: apresentação das raízes reais ou sem apresentear nada se não houver nenhuma

#include <stdio.h>
#include <math.h>

int main() {
    char entrada[160];
    
    printf("Digite os valores de a, b, c: ");
    fgets(entrada, sizeof entrada, stdin);
    double a, b, c;
    sscanf(entrada, "%lf%lf%lf", &a, &b, &c);

    double x, x1, x2, delta;

    if (a == 0) {
        // trata equação como bx + c = 0
        x = -c/b;
        printf("x = %g\n", x);
    }
    else {
        // trata equação como ax² + bx + c = 0
        delta = pow(b,2) - 4*a*c;
        if (delta == 0) {
            x = -b/(2*a);
            printf("Raíz = %g\n", x);
        }
        else if (delta > 0) {
            x1 = (-b - sqrt(delta)) / (2*a);
            x2 = (-b + sqrt(delta)) / (2*a);
            printf("Raíz 1 = %g e Raíz 2 = %g\n", x1, x2);
        }
    }

    return 0;
}