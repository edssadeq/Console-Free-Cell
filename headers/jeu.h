#ifndef JEU_HEADER
#define JEU_HEADER

#include "./stack.h"
#include "./card.h"

typedef struct zone Zone;


typedef enum ZONE_COLS ZONE_COLS;

enum ZONE_COLS { ZONE1=8, ZONE23=4};


struct zone{
	int columns;
	Stack ** stacksArray; // array of pointers
};



Zone * createZone(ZONE_COLS columns, Stack ** stacksArray);
Zone * initializeZONE1();
Zone * initializeZONE2();
Zone * initializeZONE3();
void initializeZones(Zone **z1, Zone **z2, Zone **z3);
void randCardsToZone1(Zone *z1);
void displayZone(Zone *z, int zoneNumber);
int isInArray(int *arr, int size, int tocheck);
void initGAME(Zone **zone1, Zone **zone2, Zone **zone3);
void showStatus(Zone *zone1, Zone *zone2, Zone *zone3);
void makeAMovement(Zone* sourceZone, int sourceCellNum, Zone* destinationZone, int destinationCellNum );
int isZoneFull(Zone *z);
int isZoneEmpty(Zone *z);
int isMovementToZone3Possible(Zone *zone3, int cell, Card *cardToMove);
int isMovementToZone2Possible(Zone *zone2, int cell, Card *cardToMove);
int isMovementToZone1Possible(Zone *zone1, int cell, Card *cardToMove);
int whatZoneIsIt(Zone *z);
void resetGAME(Zone **zone1, Zone **zone2, Zone **zone3);
#endif
