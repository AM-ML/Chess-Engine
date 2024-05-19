#include <stdio.h>
#include "defs.h"

void output_board_status()
{
	for(int i = 0; i < BRD_SQ_NUM; i++)
	{
		if (i % 10 == 0)
			printf("\n");
		printf("%5d", Sq120ToSq64[i]);
	}

	printf("\n");
	printf("\n");

	for (int i = 0; i < 64; i++)
	{
		if (i % 8 == 0)
			printf("\n");
		printf("%5d", Sq64ToSq120[i]);
	}

	printf("\n");
}

int main(void)
{
	AllInit();

	U64 bb = 0ULL;

	printf("start: \n");
	PrintBitBoard(bb);

	bb |= 1ULL << SQ64(E2);
	bb |= 1ULL << SQ64(H2);

	printf("ADDED pawn on E2, H2: \n");
	PrintBitBoard(bb);

	return 0;
}
