#include "stdio.h"
#include <cmath>
#include <vector>
using namespace std;

void print_board(char chess_board[8][8]);

class piece
{
public:
	void move();
};

int main()
{
	printf("WELCOME TO CHESS\n");
	printf("test_1\n");
	// vector<vector<char>> chess_board('-');
	char chess_board[8][8];
	printf("test_2\n");
	chess_board[1][5] = 'A'; // error is here  so I think it's because I didn't set up size of vector
	printf("test_3\n");
	printf("right before print_board func\n");
	print_board(chess_board);
	printf("after print_board func\n");

	return 0;
}

void print_board(char chess_board[8][8])
{
	printf("Right before loop");
	for (int y = 0; y < 0; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			printf("%c", chess_board[y][x]);
		}
	}
}