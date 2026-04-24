/* Dadas as coordenadas x e y de dois pontos em Reais², determinar as coordenadas do ponto médio.
Se (x1, y1) e (x2, y2) são os pontos, o ponto médio tem coordenadas (xm, ym), sendo xm = (x1 + x2) / 2 
e ym = (y1 + y2) / 2. Use modularização! */

#include <stdio.h>

void ponto_medio(double x1, double y1, double x2, double y2, double *xm, double *ym) {
    *xm = (x1 + x2) / 2;
    *ym = (y1 + y2) / 2;
}

int main() {
    char entrada[160];
    double x1, y1, x2, y2;

    printf("Insira as coordenadas do primeiro ponto: ");
    fgets(entrada, sizeof entrada, stdin);
    sscanf(entrada, "%lf%lf", &x1, &y1);

    printf("Insira as coordenadas do segundo ponto: ");
    fgets(entrada, sizeof entrada, stdin);
    sscanf(entrada, "%lf%lf", &x2, &y2);

    double xm, ym;
    ponto_medio(x1, y1, x2, y2, &xm, &ym);
    printf("Ponto médio: (%g, %g)\n", xm, ym);
    
    return 0;
}