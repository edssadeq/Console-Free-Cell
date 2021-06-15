#include<stdio.h>
#include<stdlib.h>
#include "utils.h"


void sendErrorMessage(char* function, char* error){
	if(function == NULL) function = "GENEREL";
	if(error == NULL) error = "Default error message!";
	printf("\n[X][ERROR]{from:( %s )_ desc:( %s )}", function, error);
}

void sendInfoMessage(char* function, char* error){
	if(function == NULL) function = "GENEREL";
	if(error == NULL) error = "Default info message!";
	printf("\n[!][INFO]{from:( %s )_ desc:( %s )}", function, error);
}

void flag(int num){
	printf("\n[!][Flag](%d)\n", num);
}

