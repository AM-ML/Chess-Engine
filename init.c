#include <stdio.h>
#include "defs.h"

// init.c provides initial workspace setup like core functions.

int Sq120ToSq64[BRD_SQ_NUM]; // converts 120 SQR board to 64 SQR board
int Sq64ToSq120[64]; 		// converts 64 SQR board to 120 SQR board

void InitSq120ToSq64() // intitialized the 64-120 120-64 arrays / semi-funcs.
// 1- fill both 120-64, 64-120 arrays with impossible values for safety
// 2- loop through each square in the chess board (except off board square / NO_SQ)
// 3- store the 120 square and 64 square to 64-120 and 120-64 arrays respectively
// 3.5- using square 64 and 120 as index respectively.

{   // indexes
	int file = FILE_A; // file index
	int rank = RANK_1; // rank index
	int index = 0; // for loop index
	int sq64 = 0; // square 64 index
	int sq = A1; // square 120 index

	for(index = 0; index < BRD_SQ_NUM; index++)
	{
		Sq120ToSq64[index] = 65; // returning impossible value for safety, max = 63.
	}

	for(index = 0; index < 64; index++)
	{
		Sq64ToSq120[index] = 120; // returning impossible value for safety, max = 119.
	}

	for(rank = RANK_1; rank <= RANK_8; rank++) 
	{											   // loop to go through every sqr on board.
		for(file = FILE_A; file <= FILE_H; file++)
		{
			sq = FR2SQ(file,rank); // set sq equal to square 120 (A1, B1, C1, ...)

			// set square 64 array's corresponding index to value of square 120.
			Sq64ToSq120[sq64] = sq;
			
			// set square 120 array's corresponding index to value of square 64.
			Sq120ToSq64[sq] = sq64;

			sq64++; // incrementing sq64 for every square passed (until reaching 63)
		}
	}
}

void AllInit()
{
	InitSq120ToSq64();
}