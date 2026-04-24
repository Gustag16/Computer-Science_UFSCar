/* Considere um espaço 3D. Escreva uma funão para retornar a distância entre dois pontos a partir de suas 
coordenadas.
d[(x1, y1, z1), (x2, y2, z2)] --> d = sqrt( [x1-x2]² + [y1-y2]² + [z1-z2]² )*/

// Descrição: Função que retorna a distância entre dois pontos em um espaço tridimensional a partir de suas coordenadas
// Requer: os valores x, y e z de ambos os pontos
// Assegura: a distância entre os dois pontos

#include <stdio.h>
#include <math.h>

double distancia(double x1, double y1, double z1, 
                 double x2, double y2, double z2) {
    return sqrt( pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2) );
}

int main() {
    char entrada[160];
    double x1, y1, z1, x2, y2, z2;

    printf("Insira as coordenadas do primeiro ponto: ");
    fgets(entrada, sizeof entrada, stdin);
    sscanf(entrada, "%lf%lf%lf", &x1, &y1, &z1);

    printf("Insira as coordenadas do segundo ponto: ");
    fgets(entrada, sizeof entrada, stdin);
    sscanf(entrada, "%lf%lf%lf", &x2, &y2, &z2);

    printf("A distância entre os dois pontos é de %g\n", distancia(x1, y1, z1, x2, y2, z2));

    return 0;
}