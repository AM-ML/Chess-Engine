#ifndef DEFS_H
#define DEFS_H

#define MAXGAMEMOVES 2048 // Longest possible game.

typedef unsigned long long U64; // unsigned 64 bit integer type.

#define NAME "Vice 1.0"
#define BRD_SQ_NUM 120 // chess board array size / length.

// chess pieces
enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK };

// chess board files / columns. (FILE_NONE for board offset)
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };

// chess board ranks / rows. (RANK_NONE for board offset)
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };

// chess colors / sides / turn, white = 0, black = 1, both = 2.
enum { WHITE, BLACK, BOTH };

// chess squares value corresponding to chess board array index.
enum {
	A1 = 21, B1, C1, D1, E1, F1, G1, H1,
	A2 = 31, B2, C2, D2, E2, F2, G2, H2,
	A3 = 41, B3, C3, D3, E3, F3, G3, H3,
	A4 = 51, B4, C4, D4, E4, F4, G4, H4,
	A5 = 61, B5, C5, D5, E5, F5, G5, H5,
	A6 = 71, B6, C6, D6, E6, F6, G6, H6,
	A7 = 81, B7, C7, D7, E7, F7, G7, H7,
	A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

// basic bool initialization. F = 0, T = 1.
enum { FALSE, TRUE};

// KCA = king castling, QCA = queen castling, W,B = white, black
// 0000 | 1111, each bit is respective to wether certain castling possibility is available.
//      0 | 1     0 | 1     0 | 1     0 | 1
enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8 };

// move-undo, chess board move structure.

typedef struct 
{
	int move; // the move that will be played.

	int castlePerm; // castling permissions before move.

	int enPas; // en passant square possibility before move.

	int fiftyMove; // status of 50 move rule before move.

	U64 posKey; // position key before move.

} S_UNDO;

// chess board structure.
typedef struct 
{
	int pieces[BRD_SQ_NUM];

	// 3 bitboards, 		   A1 B1 C1 D1 E1 F1 G1 H1  
	//	 	b1 for white, e.g: 0  0  0  0  1  0  1  0  -> wP on E1, G1
	//						   A2 B2 ... -> wP on ...
	//		b2 for black, ... -> bP on ...
	// 		b3 for both, b1 | b2 (OR operator to join b1 & b2 bits)
	U64 pawns[3];

	// holds king location.
	int KingSq[2];

	// 4 bit int, 0000 | 1111 corresponding to line: 37,
	// 	 that states the castling possibilites
	int castlePerm;

	//========= RULES ==================================================================

	// turn (W or B).
	int side;

	// type: Square, if not active, enPas = NO_SQ.
	int enPas;

	// if active, draw game (50 moves = 100 ply).
	int fiftyMove;

	// half moves
	int ply;

	// determines 3-fold repetition, if active, draws the game.
	int hisPly;

	U64 posKey;

	// Pce[3] for whitePce, blackPce, bothPce.
	int pceNum[13]; // stores number of pieces on board.	   (P, N, B, R, Q, K)
	int bigPce[3];  // stores number of big pieces on board.   (N, B, R, Q)
	int majPce[3];  // stores number of major pieces on board. (R, Q)
	int minPce[3];  // stores number of minor pieces on board. (N, B)

	S_UNDO history[MAXGAMEMOVES];

} S_BOARD;

/* MACROS */

// performs mathematical operation to convert file, rank as input to square enum as output
// e.g: FILE_0, RANK_0 -> (0+21) + (0*10) = 21 = A1
#define FR2SQ(f, r) ( ( 21 + (f) ) + ( (r) * 10 ) )

/* GLOBALS */

extern int Sq120ToSq64[BRD_SQ_NUM]; // converts 120 SQR board to 64 SQR board
extern int Sq64ToSq120[64]; 		// converts 64 SQR board to 120 SQR board


/* FUNCTIONS */

extern void AllInit();

/* init.c */


#endif