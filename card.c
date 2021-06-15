#include<stdio.h>
#include<stdlib.h>
#include "./utils/utils.h"
#include "./headers/card.h"


Card * createCard(NUM n, TYPE t){
	Card * newCard = (Card*) malloc(sizeof(Card));
	if(newCard == NULL){
		sendErrorMessage("createCard","Created card is NULL");
		exit(EXIT_FAILURE);
	}
	if(!(1<=n<=13) ||!(200<=t<=203)){
		sendErrorMessage("createCard","Unacceptable values");
		exit(EXIT_FAILURE);
	}
	if(t == DIAMOND || t == HEART) newCard->color = RED;
	if(t == SPADE || t == CLUB) newCard->color = BLACK;
	newCard->num = n;
	newCard->type = t;
	
	return newCard;
}

void displayCard(Card *card){
	char * typeStr;
	char * numStr;
	char * colorStr;
	
	if(card->type == DIAMOND ) typeStr = "DIAMOND";
	if(card->type == SPADE ) typeStr = "SPADE";
	if(card->type == HEART ) typeStr = "HEART";
	if(card->type == CLUB ) typeStr = "CLUB";
	
	if(card->num == AS ) numStr = "AS";
	if(card->num == JACK ) numStr = "JACK";
	if(card->num == QUEENE ) numStr = "QUEENE";
	if(card->num == KING ) numStr = "KING";
	
	if(card->color == RED ) colorStr = "RED";
	if(card->color == BLACK ) colorStr = "BLACK";
	
	printf("{%d | %s | %s}", card->num, typeStr, colorStr);
}

Card ** createCardsArray(){
	int i;
	Card ** cardsArray = (Card**) malloc(sizeof(Card*)* 52);
	if(cardsArray == NULL){
		sendErrorMessage("createCardsArray","Created card is NULL");
		exit(EXIT_FAILURE);
	}
	for(i=0; i<=12; i++){
		cardsArray[i] = createCard(i+1, DIAMOND);
	}
	for(i=13; i<=25 ; i++){
		cardsArray[i] = createCard((i+1)-13, SPADE);
	}
	for(i=26; i<=39; i++){
		cardsArray[i] = createCard((i+1)-(13*2), HEART);
	}
	for(i=39; i<=52; i++){
		cardsArray[i] = createCard((i+1)-(13*3), CLUB);
	}
	
	return cardsArray;
}

int areTheSameCard(Card *c1, Card *c2){
	if((c1->num == c2->num)&& (c1->type == c2->type) && (c1->color == c2->color) ) return 1;
	return 0;
}


int isCardExistInArray(Card ** arr, int arraySize, Card *c){
	//arr elements must initialized with null;
	if(*arr == NULL){
		sendErrorMessage("isCardExistInArray","Array is NULL");
		//return 0;
		exit(EXIT_FAILURE);
	}
	if(c == NULL){
		sendErrorMessage("isCardExistInArray","Card is NULL");
		exit(EXIT_FAILURE);
	}
	int i=0;
	for(;i<arraySize; i++){
		if(arr[i] == NULL) continue;
		if(areTheSameCard(arr[i], c)) return 1;
	}
	return 0;
}


