#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ReversePolish.h"

//Definição do tipo lista

struct element{
	struct data DATA;		// campo do tipo aluno que recebe o dado a ser armazenado
	struct element *next;		// ponteiro do tipo elemento que indica o proximo elemento 
};

typedef struct element Elem;		// definição de um nome padrão para a struct elemento

Stack* createStack(){
    Stack* ST = (Stack*) malloc(sizeof(Stack));
    if (ST != NULL){
        *ST = NULL;
    }
    return ST;
}

void freeStack(Stack* ST){
    if (ST != NULL){
        Elem* NO;
        while ((*ST)!= NULL){
            NO = *ST;
            *ST = (*ST)->next;
            free(NO);
        }
        free(ST);
    }
}

int sizeStack(Stack* ST){
    if(ST == NULL){
        return 0;
    }
    int COUNT = 0;
    Elem* NO = *ST;
    while (NO != NULL){
        COUNT++;
        NO = NO->next;
    }
    return COUNT;    
}

int emptyStack(Stack* ST){
    if(ST == NULL){
        return 1;
    }
    if(*ST == NULL){
        return 1;
    }
    return 0;
}

int insertStack(Stack* ST, struct data DT){
    if(ST == NULL){
        return 0;
    }
    Elem* NO;
    NO = (Elem*) malloc(sizeof(Elem));
    if(NO == NULL){
        return 0;
    }
    NO->DATA = DT;
    NO->next = (*ST);
    *ST = NO;
    return 1;
}

int removeStack(Stack* ST){
    if(ST == NULL){
        return 0;
    }
    if((*ST) == NULL){
        return 0;
    }
    Elem *NO = *ST;
    *ST = NO->next;
    free(NO);
    return 1;
}

int accessTopStack(Stack* ST, struct data *DT){
    if(ST == NULL){
        return 0;
    }if((*ST) == NULL){
        return 0;
    }
    *DT = (*ST)->DATA;
    return 1;
}