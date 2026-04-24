// Descrição: Cálculo da área de um retângulo a partir de suas coordenadas
// Requer: Dois pares ordenados  de dois vértices opostos de um retângulo
// Assegura: Apresentação da área desse retângulo

#include <stdio.h>
#include <math.h> // incluir a função 'fabs()' valor absoluto/módulo de um floating point

int main(){
    char entrada[160];

    printf("Insira as coordenadas x,y de um vértice do retângulo: ");
    fgets(entrada, sizeof entrada, stdin);
    double x1, y1;
    sscanf(entrada, "%lf%lf", &x1, &y1);

    double x2, y2;
    printf("Insira as coordenadas x,y do vértice do retângulo oposto ao anterior: ");
    fgets(entrada, sizeof entrada, stdin);
    sscanf(entrada, "%lf%lf", &x2, &y2);

    double altura, base;
    base = fabs(x2 - x1);  // módulo da diferença entre os dois pontos no eixo x
    altura = fabs(y2 - y1);  // módulo da diferença entre os dois pontos no eixo y

    printf("\nBase: %.2f unidades\n", base);
    printf("Altura: %.2f unidades\n\n", altura);

    if (base == 0 || altura == 0){
        printf("O retângulo não existe\n");
    }
    else {
        double area;
        area = base * altura;
        printf("A área do retângulo é de %g unidades quadradas\n", area);
    }

    return 0;
}