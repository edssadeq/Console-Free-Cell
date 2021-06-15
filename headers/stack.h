#ifndef STACK_HEADER
#define STACK_HEADER
#include "./card.h"

typedef struct stack Stack;
typedef struct stackElm StackElement;


struct stackElm{
	Card *card;
	struct stackElm *nextElm;
};

struct stack{
	unsigned capacity; //maximum size
	int size;
	StackElement *head;
};

Stack * createStack(unsigned capacity);
StackElement * createStackElm(Card *card);
int isStackEmpty(Stack *stack);
void push(Stack *stack, StackElement *elm);
void pop(Stack *stack);
StackElement * peek(Stack *stack);
void displayStack(Stack *stack);
int isStackFull(Stack *stack);
int isStackSorted(Stack *stack);
int areStackCardsAreTheSameType(Stack *stack);
#endif
