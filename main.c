#include <stdio.h>
#include <stdlib.h>

#include "./utils/utils.h"
#include "./headers/stack.h"
#include "./headers/card.h"
#include "./headers/jeu.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char choice;
	int sourceZoneIn, sourceCellIn;
	int destZoneIn,  destCellIn; 
	int isInitialized = 0;
	
	Zone *zone1=NULL, *zone2=NULL, *zone3=NULL;
	
	do{
		printf("\n\n====================|WELCOME TO CONSOLE FREE-CELL|====================\n");
		printf("\t type [P,p] to start playing!");
		printf("\n\t type [S,s] to show status!");
		printf("\n\t type [M,m] to make a movement!");
		printf("\n\t type [R,r] to reset the game!");
		printf("\n\t type [C,c] to clear the console!");
		printf("\n\t type [Q,q] to quite the game!");
		printf("\n======================================================================\n\n");
		
		printf("\t please enter your choice : ");
		scanf(" %c", &choice);
		
		if(choice == 'p' || choice == 'P'){
			initGAME(&zone1, &zone2, &zone3);
			isInitialized = 1;
		}
		if(choice == 'S' || choice == 's'){
			if(!isInitialized){
				initGAME(&zone1, &zone2, &zone3);
				isInitialized = 1;
			}
			showStatus(zone1, zone2, zone3);
		}
		if(choice == 'R' || choice == 'r'){
			resetGAME(&zone1, &zone2, &zone3);
			isInitialized = 1;
		}
		if(choice == 'C' || choice == 'c'){
			system("cls");//clear console
			//printf("%d **** ", zone1 == NULL);
		}
		if(choice == 'M' || choice == 'm'){
			if(!isInitialized){
				initGAME(&zone1, &zone2, &zone3);
				isInitialized = 1;
			}
			
			printf("\n\t please enter source zone [1-3]: ");
			scanf("%d", &sourceZoneIn);
			printf("\n\t please enter source cell: ");
			scanf("%d", &sourceCellIn);
			
			printf("\n\t please enter destination zone [1-3]: ");
			scanf("%d", &destZoneIn);
			printf("\n\t please enter destination cell: ");
			scanf("%d", &destCellIn);
			
			printf("\nsource:[%d, %d] | destination:[%d, %d]\n", sourceZoneIn, sourceCellIn, destZoneIn, destCellIn);
			
			Zone *peekedSourceZone = NULL;
			Zone *peekedDestinationZone = NULL;
			if(sourceZoneIn == 1) peekedSourceZone = zone1;
			if(sourceZoneIn == 2) peekedSourceZone = zone2;
			if(sourceZoneIn == 3) peekedSourceZone = zone3;
			
			if(destZoneIn == 1) peekedDestinationZone = zone1;
			if(destZoneIn == 2) peekedDestinationZone = zone2;
			if(destZoneIn == 3) peekedDestinationZone = zone3;
			
			if(peekedSourceZone == NULL || peekedDestinationZone == NULL){
				printf("\n peekedSourceZone(%d) or peekedDestinationZone(%d) is NULL\n",sourceZoneIn, destZoneIn);
			}
			
			makeAMovement(peekedSourceZone, sourceCellIn-1, peekedDestinationZone, destCellIn-1);
			//printf("\n*** after movement ***\n");
			
			if(isWinner(zone1, zone2, zone3)){
				printf("\n\t***********************************\n");
				printf("\n\t|| Congratulations !! you won :) ||\n");
				printf("\n\t***********************************\n");
			}
		}
		
		
	}while(choice != 'Q' && choice != 'q');

	printf("\n\tBye Bye ;)l\n");
	return 0;
}


