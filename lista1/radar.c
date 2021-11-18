#include <stdio.h>

int main()
{
    float v, vp;
    scanf("%f", &vp);
    scanf("%f", &v);
    if (v > vp) {
        if (v <= vp*1.2) printf("R$ 85.13\n4");
        if ((v > vp*1.2) && (v <= vp*1.5)) printf("R$ 127.69\n5");
        if (v > vp*1.5) printf("R$ 574.62\n7");
    } else {
        printf("R$ 0.00\n0");
    }
    return 0;
}