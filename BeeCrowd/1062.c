#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 1000

// Estrutura de Pilha: sempre inserir no topo e remover no topo
// LIFO: Last In, First Out = Ultimo a entrar é o primeiro a sair
typedef struct {
    int vetor[MAX];
    int topo;
} Pilha; 

void push(Pilha *p, int id){
	p->vetor[++p->topo] = id;
}

void pop(Pilha *p){
	p->topo--;
}

int main(){	
	
	int fora, vagoes, i, deuruim, entrando, zero; 
	Pilha p;
	
	while(scanf("%d", &vagoes) && vagoes){
		while(1){			
			p.topo = -1;
			for (i = 0, entrando = 1, deuruim = 0, zero = 0; i < vagoes && !deuruim && !zero; i++){
				scanf("%d", &fora);
				if(!fora){
					zero = 1;
					break;
				}
				while(1){
					if(fora == entrando){
						entrando++;
						break;
					}else
						if(fora > entrando){
							push(&p, entrando);
							entrando++;
						}else{
							if(p.vetor[p.topo] == fora)
								pop(&p);
							else{
								deuruim=1;
								for(;i<vagoes-1;i++)
									scanf("%d", &fora);
							}								
							break;
						}
				}				
			}
			if(!zero)
				if(!deuruim)
					printf("Yes\n");
				else
					printf("No\n");
			else
				break;
		}
		printf("\n");
	}
	return 0;
}