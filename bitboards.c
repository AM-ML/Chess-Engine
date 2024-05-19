#include <stdio.h>
#include "defs.h"

void PrintBitBoard(U64 bb)
{
    U64 shiftMe = 1ULL;

    int rank = 0; // chess board rank index
    int file = 0; // chess board file index
    int sq64 = 0; // chess board64 square placeholder / index.
    int sq   = 0; // chess board120 square placeholder / index.

    printf("\n");

    for (rank = RANK_8; rank >= RANK_1; rank--)
    {                                      // looping through each chess board square.
        for (file = FILE_H; file >= FILE_A; file--)
        {
            sq = FR2SQ(file, rank); // retrieving the square from board120
            sq64 = SQ64(sq); // retrieving square64 from square120

            // checks if the bit on that square is = 1, then there is a piece there
            if ((shiftMe << sq64) & bb) 
                printf("x");
            else
                printf("-");
        }
        printf("\n"); // splitting each rank by a newline to make it look like a board
    }
    printf("\n");
    printf("\n");
}
