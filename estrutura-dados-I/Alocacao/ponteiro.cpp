#include <stdio.h>

main(){
    int *p;
    int x = 10;
    p = &x;
    printf("valor: %d\n", *p);
    printf("endereço: %d", p);
}