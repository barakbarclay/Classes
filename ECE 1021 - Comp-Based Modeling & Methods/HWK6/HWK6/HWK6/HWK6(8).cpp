#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
void master();
int suit();
int value();
void main(void)
{
	char a = 'y';
	while (a != 'n')
	{
		fflush(stdin);
		printf("Would you like a card, yes(y) or no(n)?:");
		scanf("%c", &a);
		if (a == 'n')
		{
			break;
		}
		master();
	}
}
void master()
{
	int suit1 = suit();
	switch (suit1)
	{
	case 1:
	{
			  printf("Value:%d\tSuit:Diamonds\n", value());
			  break;
	}	//end case
	case 2:
	{
			  printf("Value:%d\tSuit:Hearts\n", value());
			  break;
	}	//end case
	case 3:
	{
			  printf("Value:%d\tSuit:Clubs\n", value());
			  break;
	}	//end case
	case 4:
	{
			  printf("Value:%d\tSuit:Spades\n", value());
			  break;
	}	//end case
	default:
	{
			   printf("\n\n	ERROR  \n\n");
			   break;
	}	//end case

	}	//end switch

}
int suit()
{
	int suit = 0;
	suit = (rand() % 4) + 1;
	return suit;
}
int value()
{
	int value = 0;
	value = (rand() % 13) + 1;
	return value;
}