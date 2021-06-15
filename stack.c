#include<stdio.h>
#include<stdlib.h>

#include "./utils/utils.h"
#include "./headers/stack.h"
#include "./headers/card.h"



Stack * createStack(unsigned capacity){
	Stack *stack = (Stack*)malloc(sizeof(Stack));	
	if(stack == NULL){
		sendErrorMessage("createStack","Created stack is NULL");
		exit(EXIT_FAILURE);
	}
	if(capacity <= 0){
		sendErrorMessage("createStack","Capacity can not be 0");
		exit(EXIT_FAILURE);
	}
	stack->size = 0;
	stack->head = NULL;
	stack->capacity = capacity;
}

//creer un element 
StackElement * createStackElm(Card *card){
	if(card == NULL){
		sendErrorMessage("createStackElm","Paramater is NULL");
		exit(EXIT_FAILURE);
	};
	StackElement *elm = (StackElement *) malloc(sizeof(StackElement));
	if(elm == NULL){
		sendErrorMessage("createStackElm","Created element is NULL");
		exit(EXIT_FAILURE);
	}
	elm->card = card;
	elm->nextElm =  NULL;
}

int isStackEmpty(Stack *stack){
	if(stack == NULL){
		sendErrorMessage("isStackEmpty", "Stack pointer is NULL");
		exit(EXIT_FAILURE);
	}
	if(stack->head == NULL){
		if((stack->size != 0)){
			sendErrorMessage("isStackEmpty", "Stack Conflict !!");
			exit(EXIT_FAILURE);
		}
		return 1;
	}
	
	return 0;
}

int isStackFull(Stack *stack){
	if(stack == NULL){
		sendErrorMessage("isStackFull", "Stack pointer is NULL");
		exit(EXIT_FAILURE);
	}
	if(stack->size == stack->capacity){
		return 1;
	}
	
	return 0;
}

//empiler

void push(Stack *stack, StackElement *elm){
	if(stack == NULL){
		sendErrorMessage("push", "Stack pointer is NULL");
		exit(EXIT_FAILURE);
	}
	if(elm == NULL){
		sendErrorMessage("push", "Element to add is NULL");
		exit(EXIT_FAILURE);
	}
	if(isStackFull(stack)){
		sendErrorMessage("push", "Stack is full");
		exit(EXIT_FAILURE);
	}
	
	if(isStackEmpty(stack)){
		stack->head = elm;
		stack->size ++;
		return;
	}
	if(areTheSameCard(stack->head->card, elm->card) ){
		sendErrorMessage("push", "Can not push the same card twice");
		exit(EXIT_FAILURE);	
	}
	elm->nextElm = stack->head;
	stack->head = elm;
	stack->size ++;
}

void pop(Stack *stack){
	if(stack == NULL){
		sendErrorMessage("pop", "Stack pointer is NULL");
		exit(EXIT_FAILURE);
	}
	if(isStackEmpty(stack)){
		//sendErrorMessage("pop", "Stack is Empty");
		exit(EXIT_FAILURE);
	}
	
	StackElement * tmp = stack->head;
	stack->head = stack->head->nextElm;
	free(tmp);
	stack->size --;
}

StackElement * peek(Stack *stack){
	if(stack == NULL){
		sendErrorMessage("peek", "Stack pointer is NULL");
		exit(EXIT_FAILURE);
	}
	return stack->head;
}

//display

void displayStack(Stack *stack){
	if(stack == NULL){
		sendErrorMessage("displayStack", "Stack pointer is NULL");
		exit(EXIT_FAILURE);
	}
	int counter = 0;
	StackElement * tmp = stack->head;
	printf("\n(%d/%d)[\n", stack->size, stack->capacity);
	while(tmp != NULL){
		//counter <= stack->size
		displayCard(tmp->card);
		printf("\n");
		tmp = tmp->nextElm;
		//counter ++;
	}
	printf("]\n");
}

int isStackSorted(Stack *stack){
	if(stack == NULL){
		sendErrorMessage("isStackSorted", "Stack pointer is NULL");
		exit(EXIT_FAILURE);
	}
	StackElement * tmp = stack->head;
	while(tmp->nextElm != NULL){
		if(tmp->card->num - tmp->nextElm->card->num != 1) return 0;
		tmp = tmp->nextElm;
	}
	return 1;
}

int areStackCardsAreTheSameType(Stack *stack){
	if(stack == NULL){
		sendErrorMessage("isStackCardsAreTheSameType", "Stack pointer is NULL");
		exit(EXIT_FAILURE);
	}
	StackElement * tmp = stack->head;
	while(tmp!= NULL){
		if(tmp->card->type != stack->head->card->type) return 0;
		tmp = tmp->nextElm;
	}
	return 1;
}


