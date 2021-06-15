#ifndef CARD_HEADER
#define CARD_HEADER

typedef struct card Card;
typedef enum NUM NUM;
typedef enum COLOR COLOR;
typedef enum TYPE TYPE;

enum NUM {  AS=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEENE, KING };
enum COLOR { BLACK=0, RED=25500 };
enum TYPE { DIAMOND=200, SPADE, HEART, CLUB };


struct card{
 int num; // {1=A} 2-10 and {J=11; Q=12; K=13}
 int color; //{Red=25500, Black=0}
 int type; //{Diamond = 200; spade= 201; heart = 202; club = 203}
};



Card * createCard(NUM n, TYPE t);
Card ** createCardsArray();
void displayCard(Card *card);
int areTheSameCard(Card *c1, Card *c2);
int isCardExistInArray(Card ** arr, int arraySize, Card *c);

#endif
