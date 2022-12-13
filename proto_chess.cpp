#include "stdio.h"
#include <cmath>
#include <vector>
using namespace std;

// need to figure out how to set up class object pieces

char inital_piece_setup[8] = {'r', 'k', 'b', 'Q', 'K', 'b', 'k', 'r'};

void print_board(char (&chess_board)[8][8]);
void setup_initial_board(char (&chess_board)[8][8]);
char chess_board[8][8] = {'-'};

class piece
{
public:
	int y_coord;
	int x_coord;
	int y_input;
	int x_input;
	vector<pair<int, int>> possible_moves; // make a vector of possilbe moves each time a piece is selected

	virtual void move();
	virtual void find_curr_avail_moves();
};

class pawn : public piece
{
	void find_curr_avail_moves()
	{
		possible_moves.clear();
		possible_moves.shrink_to_fit();

		// should find a more algorithmic way to do this for future pieces like bishops , rooks , queens
		possible_moves.push_back(make_pair(y_coord - 1, x_coord - 1)); // this is y-1 because -1 goes up and -1 x goes to the left
		possible_moves.push_back(make_pair(y_coord - 1, x_coord + 1))  // again going up -1 for y and +1 for x goes to the right
	}
	void move()
	{
		// printf("possible moves are (%i,%i) and (%i,%i)", y_coor)
		// instead of printing out possible moves make it so ask for coord input
		scanf("y_input %i ", &y_input);
		scanf("x_input %i ", &x_input);

		// then check if input is in possilbe moves vector list
	}
};

int main()
{
	printf("WELCOME TO CHESS\n");
	// vector<vector<char>> chess_board('-');
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			chess_board[y][x] = '-';
		}
	}
	// chess_board[1][5] = {'P'}; // error is here  so I think it's because I didn't set up size of vector
	// printf("right before print_board func\n");
	// print_board(chess_board);
	// printf("after print_board func\n");

	setup_initial_board(chess_board);
	print_board(chess_board);

	return 0;
}

void print_board(char (&chess_board)[8][8])
{
	printf("Right before loop\n");
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			printf(" %c ", chess_board[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}
void setup_initial_board(char (&chess_board)[8][8])
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (y == 0 || y == 7)
			{
				chess_board[y][x] = inital_piece_setup[x];
			}
			else if (y == 1 || y == 6)
			{
				chess_board[y][x] = 'p';
			}
		}
	}
}

// ////proto switch case statmeents
// enum CHESS_STATES = {chess_init, chess_start, chess_move, chess_valid_y_n, chess_check} chess_state;

// switch (chess_state)//transitions
// {
// 	case chess_init;
// 	break;

// };

// switch(chess_state)//actions
// {
// 	case chess_init;
// 	break;

// }