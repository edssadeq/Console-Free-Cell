#include<stdio.h>
#include<stdlib.h>
#include <time.h>


#include "./utils/utils.h"
#include "./headers/stack.h"
#include "./headers/card.h"
#include "./headers/jeu.h"


Zone * createZone(ZONE_COLS columns, Stack ** stacksArray){ 
	Zone *z = (Zone*)malloc(sizeof(Zone));
	if(stacksArray == NULL){
		sendErrorMessage("createZone","stacks array is NULL");
		exit(EXIT_FAILURE);
	}
	if(z == NULL){
		sendErrorMessage("createZone","created Zone is NULL");
		exit(EXIT_FAILURE);
	}
	z->columns = columns;
	z->stacksArray = stacksArray;
}

Zone * initializeZONE1(){
	int i;
	Stack **stacksArray = (Stack**) malloc(sizeof(Stack*) * ZONE1);
	if(*stacksArray == NULL){
		sendErrorMessage("initializeZONE1","stacks array is NULL");
		exit(EXIT_FAILURE);
	}
	for(i=0; i<ZONE1; i++){
		Stack *ns = createStack(13);
		if(ns == NULL){
			sendErrorMessage("initializeZONE1","stacks created is NULL");
			exit(EXIT_FAILURE);
		}
		stacksArray[i] = ns;
	}
	
	Zone *z = createZone(8, stacksArray);
	if(z == NULL){
		sendErrorMessage("initializeZONE1","created zone is NULL");
		exit(EXIT_FAILURE);
	}
	return z;
}


Zone * initializeZONE2(){
	int i;
	Stack ** stacksArray = (Stack **) malloc(sizeof(Stack*)* ZONE23);
	if(stacksArray == NULL){
		sendErrorMessage("initializeZONE2","stacks array is NULL");
		exit(EXIT_FAILURE);
	}
	for(i=0; i<ZONE23; i++){
		Stack *ns = createStack(1);
		if(ns == NULL){
			sendErrorMessage("initializeZONE2","stacks created is NULL");
			exit(EXIT_FAILURE);
		}
		stacksArray[i] = ns;
	}
	
	Zone *z = createZone(ZONE23, stacksArray);
	if(z == NULL){
		sendErrorMessage("initializeZONE2","created zone is NULL");
		exit(EXIT_FAILURE);
	}
	return z;
}


Zone * initializeZONE3(){
	int i;
	Stack ** stacksArray = (Stack **) malloc(sizeof(Stack*)* ZONE23);
	if(*stacksArray == NULL){
		sendErrorMessage("initializeZONE3","stacks array is NULL");
		exit(EXIT_FAILURE);
	}
	for(i=0; i<ZONE23; i++){
		Stack *ns = createStack(13);
		if(ns == NULL){
			sendErrorMessage("initializeZONE3","stacks created is NULL");
			exit(EXIT_FAILURE);
		}
		stacksArray[i] = ns;
	}
	
	Zone *z = createZone(ZONE23, stacksArray);
	if(z == NULL){
		sendErrorMessage("initializeZONE3","created zone is NULL");
		exit(EXIT_FAILURE);
	}
	return z;
}

void initializeZones(Zone **z1, Zone **z2, Zone **z3){
	*z1 = initializeZONE1();
	*z2 = initializeZONE2();
	*z3 = initializeZONE3();
}


void randCardsToZone1(Zone *z1){
	int i=0, j=0, k=0, u;
	if(z1 == NULL){
		sendErrorMessage("randCardsToZone1","Zone1 is NULL");
		exit(EXIT_FAILURE);
	}
	// On commence par initialiser le générateur de nombre pseudo-aléatoires.
	srand( time( NULL ) );
	Card **cardsDB = createCardsArray(); //create cards (52 cards)
	int tmpArr[52]; //peeked cards from DB
	//initialize tmpArr
	for(u=0; u<52; u++){
		tmpArr[u] = -1;
	}
	//init stack
	Stack *iterStack = NULL;

	while(i<52){
		int randomValue = rand() % 53; // random between 0 and 52
		iterStack = z1->stacksArray[i%8];
		//test if it is peeked before
		if(!isInArray(tmpArr, 52, randomValue)){
			tmpArr[j] = randomValue; j++; //add to peeked cards array 
			//peek a random card from Database
			Card *cardFromDB = cardsDB[randomValue];
			StackElement *stm = createStackElm(cardFromDB); 
			push(iterStack, stm); //add to zone stacks
			i++;	
		}
		
	}

}

void displayZone(Zone *z, int zoneNumber){
	int i;
	if(z == NULL){
		sendErrorMessage("displayZone","Zone1 is NULL");
		exit(EXIT_FAILURE);
	}
	printf("\n=====[ZONE %d]=====\n", zoneNumber);
	for(i=0; i<z->columns; i++){
		printf("{column: %d}", i+1);
		displayStack(z->stacksArray[i]);
	}
}

int isInArray(int *arr, int size, int tocheck){
	int j=0;
	for(; j< size ; j++){
		if(arr[j] == tocheck) return 1;
	}
	return 0;
}




void showStatus(Zone *zone1, Zone *zone2, Zone *zone3){
	if(zone1 == NULL || zone2 == NULL || zone3 == NULL){
		sendErrorMessage("showStatus","A Zone is NULL");
		exit(EXIT_FAILURE);
	}
	printf("\n============[Show Status]============\n");
	displayZone(zone1, 1);
	displayZone(zone2, 2);
	displayZone(zone3, 3);
}

void makeAMovement(Zone* sourceZone, int sourceCellNum, Zone* destinationZone, int destinationCellNum ){
	
	if(sourceZone == NULL || destinationZone == NULL){
		sendErrorMessage("makeAMovement","A Zone is NULL");
		exit(EXIT_FAILURE);
	}
	if((sourceCellNum < 1) || (sourceCellNum > 8) || (destinationCellNum < 1) || (destinationCellNum > 8)){
		sendErrorMessage("makeAMovement", "One of cells does not existe please [1,8]");
		return;
	}
	//Cell for Stack
	int sourceZoneNum = whatZoneIsIt(sourceZone);
	int destinationZoneNum = whatZoneIsIt(destinationZone);
	
	if(((sourceZoneNum < 1) || (sourceZoneNum > 3)) || (destinationZoneNum < 1) || (destinationZoneNum > 3)){
		//sourceZoneNum & destinationZoneNum must be between 1 and 3
		sendErrorMessage("makeAMovement", "Source Zone does not existe please [1,2,3]");
		return;
	}
	if((sourceZoneNum == 1 && ((sourceCellNum < 1) || (sourceCellNum > 8))) || (destinationZoneNum == 1 && ((destinationCellNum < 1) || (destinationCellNum > 8)))){
		//if it is zone1 so the cell must be between 1 and 8
		printf("\n*********s %d, d %d, sn %d, dn %d",sourceZoneNum, destinationZoneNum, sourceCellNum, destinationCellNum);
		sendErrorMessage("makeAMovement", "Zone 1 has exactly 8 cells");
		return;
	}
	
	if(((sourceZoneNum == 2 || sourceZoneNum == 3) && ((sourceCellNum < 1) || (sourceCellNum > 4))) || ((destinationZoneNum == 2 || destinationZoneNum == 3) && ((destinationCellNum < 1) || (destinationCellNum > 4)))){
		//if it is zone2 or 3 so the cell must be between 1 and 4
		sendErrorMessage("makeAMovement", "Zone 2 and 3 have exactly 4 cells");
		return;
	}
	if(isZoneEmpty(sourceZone)){
		sendErrorMessage("makeAMovement", "Source zone is empty");
		return;
	}
	Stack *sourceCell = sourceZone->stacksArray[sourceCellNum];
	if(sourceCell == NULL){
		sendErrorMessage("makeAMovement","Source stack is NULL");
		exit(EXIT_FAILURE);
	}
	if(isStackEmpty(sourceCell)){
		sendErrorMessage("makeAMovement", "Source cell is empty");
		return;
	}
	
	//get the card to move
	StackElement *cardToMoveElm = peek(sourceCell);
	if(cardToMoveElm == NULL){
		sendErrorMessage("makeAMosourceCellvement","Element Card to move is NULL");
		exit(EXIT_FAILURE);
	}
	Card * cardToMove = cardToMoveElm->card;
	if(cardToMove == NULL){
		sendErrorMessage("makeAMosourceCellvement","Card to move is NULL");
		exit(EXIT_FAILURE);
	}
	
	if(destinationZoneNum == 1){
		if(!isMovementToZone1Possible(destinationZone, destinationCellNum, cardToMove)){
			sendErrorMessage("makeAMovement", "Unreachable movement to zone1");
			return;
		}
		Stack *destCell = destinationZone->stacksArray[destinationCellNum];
		if(destCell == NULL){
			sendErrorMessage("makeAMosourceCellvement","destination cell is NULL");
			exit(EXIT_FAILURE);
		}
		StackElement *stElmdest = createStackElm(cardToMove);
		if(cardToMove == NULL){
			sendErrorMessage("makeAMosourceCellvement","destination stackElement is NULL");
			exit(EXIT_FAILURE);
		}
		push(destCell, stElmdest);
		pop(sourceCell);
		printf("\n(=Done)\n");
	}
	else if(destinationZoneNum == 2){
		if(!isMovementToZone2Possible(destinationZone, destinationCellNum, cardToMove)){
			sendErrorMessage("makeAMovement", "Unreachable movement to zone1");
			return;
		}
		Stack *destCell = destinationZone->stacksArray[destinationCellNum];
		if(destCell == NULL){
			sendErrorMessage("makeAMosourceCellvement","destination cell is NULL");
			exit(EXIT_FAILURE);
		}
		StackElement *stElm = createStackElm(cardToMove);
		if(cardToMove == NULL){
			sendErrorMessage("makeAMosourceCellvement","destination stackElement is NULL");
			exit(EXIT_FAILURE);
		}
		push(destCell, stElm);
		pop(sourceCell);
	}
	else if(destinationZoneNum == 3){
		if(!isMovementToZone3Possible(destinationZone, destinationCellNum, cardToMove)){
			sendErrorMessage("makeAMovement", "Unreachable movement to zone1");
			return;
		}
		Stack *destCell = destinationZone->stacksArray[destinationCellNum];
		if(destCell == NULL){
			sendErrorMessage("makeAMosourceCellvement","destination cell is NULL");
			exit(EXIT_FAILURE);
		}
		StackElement *stElm = createStackElm(cardToMove);
		if(cardToMove == NULL){
			sendErrorMessage("makeAMosourceCellvement","destination stackElement is NULL");
			exit(EXIT_FAILURE);
		}
		push(destCell, stElm);
		pop(sourceCell);
	}
	else{
		sendErrorMessage("makeAMosourceCellvement","Uknown Movement");
		return;
	}
	
}

int whatZoneIsIt(Zone *z){
	if(z == NULL){
		sendErrorMessage("whatZoneIsIt","Zone is NULL");
		exit(EXIT_FAILURE);
	}
	
	if(z->stacksArray[0] == NULL){
		sendErrorMessage("whatZoneIsIt","first stack is NULL");
		exit(EXIT_FAILURE);
	}
	if(z->columns == 8 && z->stacksArray[0]->capacity == 13) return 1;
	if(z->columns == 4 && z->stacksArray[0]->capacity == 1) return 2;
	if(z->columns == 4 && z->stacksArray[0]->capacity == 13) return 3;
	return -1;
}

int isZoneFull(Zone *z){
	if(z == NULL){
		sendErrorMessage("isZoneFull","Zone1 is NULL");
		exit(EXIT_FAILURE);
	}
	int i=0;
	for(; i<z->columns; i++){
		Stack *st = z->stacksArray[i];
		if(!isStackFull(st)) return 0;
	}
	return 1;
	
}

int isZoneEmpty(Zone *z){
	if(z == NULL){
		sendErrorMessage("isZoneEmpty","Zone1 is NULL");
		exit(EXIT_FAILURE);
	}
	int i=0;
	for(; i<z->columns; i++){
		Stack *st = z->stacksArray[i];
		if(!isStackEmpty(st)) return 0;
	}
	return 1;
}


int isWinner(Zone *zone1, Zone *zone2, Zone *zone3){
	if(zone1 == NULL || zone2 == NULL || zone3 == NULL){
		sendErrorMessage("isWinner","A Zone is NULL");
		exit(EXIT_FAILURE);
	}
	if(!isZoneEmpty(zone1) || !isZoneEmpty(zone2) || !isZoneFull(zone3)) return 0;
	int i=0;
	for(;i<zone3->columns; i++){
		Stack *stmp = zone3->stacksArray[i];
		if(!isStackSorted(stmp) || !areStackCardsAreTheSameType(stmp)) return 0;
	}
	return 1;
//	if(isZoneFull(zone3) || )
}

int isMovementToZone3Possible(Zone *zone3, int cell, Card *cardToMove){
	if(zone3 == NULL){
		sendErrorMessage("isMovementToZone3Possible","Zone 3 is NULL");
		exit(EXIT_FAILURE);
	}
	if(cardToMove == NULL){
		sendErrorMessage("isMovementToZone3Possible","cardToMove is NULL");
		exit(EXIT_FAILURE);
	}
	if(cell < 1 || cell > 4 ){
		//sendErrorMessage("isMovementToZone3Possible","cell must be between 1 and 4");
		return 0;
	}
	if(isZoneEmpty(zone3) && cardToMove->num != AS) return 0;
	if(isZoneFull(zone3)) return 0;
	Stack *stmp = zone3->stacksArray[cell];
	if(isStackEmpty(stmp) && cardToMove->num != AS) return 0;
	if(isStackFull(stmp)) return 0;
	if(isStackEmpty(stmp) && cardToMove->num == AS) return 1;
	if((cardToMove->num-stmp->head->card->num != 1) || cardToMove->type!=stmp->head->card->type) return 0;
	return 1;
	
}


int isMovementToZone2Possible(Zone *zone2, int cell, Card *cardToMove){
	if(zone2 == NULL){
		sendErrorMessage("isMovementToZone2Possible","Zone 1 is NULL");
		exit(EXIT_FAILURE);
	}
	if(cardToMove == NULL){
		sendErrorMessage("isMovementToZone2Possible","cardToMove is NULL");
		exit(EXIT_FAILURE);
	}
	if(cell < 1 || cell > 4 ){
		//sendErrorMessage("isMovementToZone3Possible","cell must be between 1 and 4");
		return 0;
	}
	if(isZoneEmpty(zone2)) return 1;
	//if(isZoneFull(zone1)) return 0;
	Stack *stmp = zone2->stacksArray[cell];
	if(isStackEmpty(stmp)) return 1;
	if(isStackFull(stmp)) return 0;
	return 1;
	
}

int isMovementToZone1Possible(Zone *zone1, int cell, Card *cardToMove){
	if(zone1 == NULL){
		sendErrorMessage("isMovementToZone1Possible","Zone 1 is NULL");
		exit(EXIT_FAILURE);
	}
	if(cardToMove == NULL){
		sendErrorMessage("isMovementToZone1Possible","cardToMove is NULL");
		exit(EXIT_FAILURE);
	}
	if(cell < 1 || cell > 8 ){
		sendErrorMessage("isMovementToZone3Possible","cell must be between 1 and 4");
		return 0;
	}
	if(isZoneEmpty(zone1)) return 1;
	
	//if(isZoneFull(zone1)) return 0;
	Stack *stmp = zone1->stacksArray[cell];
	if(stmp == NULL){
		sendErrorMessage("isMovementToZone1Possible","Requisted cell is NULL");
		exit(EXIT_FAILURE);
	}
	if(isStackEmpty(stmp)) return 1;
	if(isStackFull(stmp)){
		sendErrorMessage("isMovementToZone1Possible","destination cell is full");
		return 0;
	};
	if((stmp->head->card->num-cardToMove->num != 1) || cardToMove->color==stmp->head->card->color){
		sendErrorMessage("isMovementToZone1Possible","Card to move must lower with different color");
		return 0;
	}
	return 1;
	
}


void initGAME(Zone **zone1, Zone **zone2, Zone **zone3){
	if(zone1 == NULL || zone2 == NULL || zone3 == NULL){
		sendErrorMessage("initGAME","A Zone is NULL");
		exit(EXIT_FAILURE);
	}
	initializeZones(zone1, zone2, zone3);
	randCardsToZone1(*zone1);
	showStatus(*zone1, *zone2, *zone3);
}

void resetGAME(Zone **zone1, Zone **zone2, Zone **zone3){
	system("cls");//clear console
	initGAME(zone1, zone2, zone3);
}
 
