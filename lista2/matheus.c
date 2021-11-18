#include <stdio.h>

int main()
{
    int n, x0, x1, y0, y1, z0, z1, cx, cy, cz;
    scanf("%i\n%i %i %i %i %i %i", &n, &x0, &x1, &y0, &y1, &z0, &z1); 
    cx = 0;
    for (int i=x1; i >= x0; i--) {
        for (int k=z1; k >= z0; k--) {
            for (int j=y1; j >= y0; j--) {
                if (i + j + k == n) {
                    cx = i;
                    cy = j;
                    cz = k;
                }
            }
        }    
    }          
    if (cx) {
        printf("S\n");
        printf("%i %i %i", cx, cy, cz);
    } else {
        printf("N");
    }
    return 0;
}