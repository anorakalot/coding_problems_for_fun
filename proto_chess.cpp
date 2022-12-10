#include "stdio.h"
#include <cmath>
#include <vector>
using namespace std;

char inital_piece_setup[8] = {'r', 'k', 'b', 'Q', 'K', 'b', 'k', 'r'};

void print_board(char (&chess_board)[8][8]);
void setup_initial_board(char (&chess_board)[8][8]);
class piece
{
public:
	void move();
};

int main()
{
	printf("WELCOME TO CHESS\n");
	// vector<vector<char>> chess_board('-');
	char chess_board[8][8] = {'-'};
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			chess_board[y][x] = '-';
		}
	}
	// chess_board[1][5] = {'P'}; // error is here  so I think it's because I didn't set up size of vector
	printf("right before print_board func\n");
	print_board(chess_board);
	printf("after print_board func\n");

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