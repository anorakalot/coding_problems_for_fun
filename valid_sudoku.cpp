class Solution
{
public:
	bool isValidSudoku(vector<vector<char>> &board)
	{
		// vector<char> row {'1','2'};

		// for(int i = 0; i < 9;i++ ){
		// printf("board[i][i]: %c\n" ,board[i][i]);
		// }
		map<char, int> row_check;
		map<char, int> col_check;

		map<char, int> top_left_box;
		map<char, int> top_mid_box;
		map<char, int> top_right_box;

		map<char, int> mid_left_box;
		map<char, int> mid_mid_box;
		map<char, int> mid_right_box;

		map<char, int> bott_left_box;
		map<char, int> bott_mid_box;
		map<char, int> bott_right_box;

		printf("debug loop\n");
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				printf("%c ", board[y][x]);
				// printf("");
			}
			printf("\n");
		}

		printf("loop that checks row\n");
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				printf("board[%i][%i] = %c\n", y, x, board[y][x]);
				if (board[y][x] != '.' && row_check[board[y][x]] == 0)
				{ // meaning it hasn't been seen before
					row_check[board[y][x]] = 1;
					// set unique val to 1;
				}
				else if (board[y][x] != '.' && row_check[board[y][x]] > 0)
				{ // meaning seen this char before on this row
					printf("(ROW_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)", y, x);
					return 0;
				}
			}				   // end of row loop
			row_check.clear(); // clear row_check after each row is done
		}

		printf("loop that checks col\n");
		for (int x = 0; x < 9; x++)
		{ // needs to go x (row pos) and go down the y col
			for (int y = 0; y < 9; y++)
			{
				printf("board[%i][%i] = %c\n", y, x, board[y][x]);
				if (board[y][x] != '.' && col_check[board[y][x]] == 0)
				{ // meaning it hasn't been seen before
					col_check[board[y][x]] = 1;
					// set unique val to 1;
				}
				else if (board[y][x] != '.' && col_check[board[y][x]] > 0)
				{ // meaning seen this char before on this row
					printf("(COL_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)", y, x);
					return 0;
				}
			}				   // end of row loop
			col_check.clear(); // clear row_check after each row is done
		}

		// placeholder for now until code is done
		return 1;
	}
};