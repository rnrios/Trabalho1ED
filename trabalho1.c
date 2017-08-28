/* 	Mateus Freitas Cavalcanti	16/0137519
	Rodrigo Naves Rios			00/0000000
   	Estruturas de Dados - Turma C
  	Trabalho 1 -> Calculadora Polonesa */

#include <stdio.h>
#include <stdlib.h>

typedef struct numero{
	int num;
	struct elemento* prox;
}t_numero;

typedef struct pilha{
	t_numero* inicio;
	t_numero* fim;
}t_pilha;

t_pilha* cria_pilha() {
	t_pilha* p = (t_pilha*)malloc(sizeof(t_pilha));
	p->inicio = NULL;
	p->fim = NULL;
	printf("\n -> PILHA CRIADA !\n\n");
	return p;
}

void adiciona_fim(int digito, t_pilha* p) {
	t_numero* novo = (t_numero*)malloc(sizeof(t_numero));
	novo->num = digito;
	novo->prox = NULL;
	if(p->inicio == NULL) {
		p->inicio = novo;
	}
	else {
		p->fim = novo;
	}
}

void mostra_pilha(t_pilha* p) {
	t_numero* aux = p->inicio;
	printf(" -> Pilha atual :");
	while(aux != NULL) {
		printf(" %d", aux->num);
		aux = aux->prox;
	}
	printf("\n");
}

int main() {
int digito;
t_pilha* p = cria_pilha();
while(1) {
	printf("\e[H\e[2J");
	printf("\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t\t[   CALCULADORA POLONESA   ]\n");
	printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n -> Número que deseja colocar no fim da pilha : ");
	scanf("%d", &digito);
	adiciona_fim(digito,p);
	mostra_pilha(p);
	getchar();
	getchar();
}
return 0;
}
