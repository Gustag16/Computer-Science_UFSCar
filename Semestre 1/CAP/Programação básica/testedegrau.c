#include <stdio.h>
#include <math.h>

int main()
{
    float x, altura, degraus;

    printf("Insira a altura dos degraus em metros ");
    scanf("%f,&x");

    printf("Insira a altura que voce deseja alcancar ");
    scanf("%f,&altura");

    degraus = altura/x;
    ceil(degraus);

    printf("Voce precisara subir %d degraus para alcancar %.2f metros de altura", x, altura);
    return 0;
}