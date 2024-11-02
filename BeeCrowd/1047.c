#include <stdio.h>
int main(void)
{
    int a, b, c, d;
    int dif;
    int *p1 = &a, *p2 = &b, *p3 = &c, *p4 = &d;
    scanf("%d %d %d %d", p1, p2, p3, p4);
    dif = ((*p3 * 60) + *p4) - ((*p1 * 60) + *p2);
    if(dif <= 0) dif += 24 * 60;
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", dif/60, dif%60);
    return 0;
}