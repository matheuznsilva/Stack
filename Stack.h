struct data{		// struct onde é guardada as informações de cada nó da lista
	float NUMBER;		// variável onde será armasendo cada numero 
};

typedef struct element* Stack; // padronização do nome do ponteiro tipo lista

Stack* createStack();
void freeStack(Stack* ST);
int accessTopStack(Stack* ST, struct data *DT);
int insertStack(Stack* ST, struct data DT);
int removeStack(Stack* ST);
int sizeStack(Stack* ST);
int emptyStack(Stack* ST);