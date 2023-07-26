#ifndef _DECK_H_
#define _DECK_H_
#include <stdio.h>
#include <stdlib.h>

/**
 * enum kind_e - types of cards in the deck
 * @SPADE:  represented by 0
 * @HEART: represented by 1
 * @CLUB: represented by 2
 * @DIAMOND: represented by 3
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - the Playing card
 * @value: the actual Value of the card
 * @kind: type of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - the Deck of cards
 * @card: Points to the card node
 * @prev: Point to the previous list node
 * @next: Points to the next list node
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;
void sort_deck(deck_node_t **deck);

#endif
