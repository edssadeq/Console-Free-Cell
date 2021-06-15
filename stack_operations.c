#include<stdio.h>
#include<stdlib.h>

#include "../utils/utils.h"
#include "../headers/stack.h"

Stack * createStack(){
	Stack *stack = (Stack*)malloc(sizeof(Stack));	
	if(stack == NULL){
		sendErrorMessage("createStack","Created stack is NULL");
		exit(EXIT_FAILURE);
	}
	stack->size = 0;
	stack->head = NULL;
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
	elm->nextCard =  NULL;
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
	if(isStackEmpty(stack)){
		stack->head = elm;
		stack->size ++;
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



