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

		map<char, int> top_left_box_check;
		map<char, int> top_mid_box_check;
		map<char, int> top_right_box_check;

		map<char, int> mid_left_box_check;
		map<char, int> mid_mid_box_check;
		map<char, int> mid_right_box_check;

		map<char, int> bott_left_box_check;
		map<char, int> bott_mid_box_check;
		map<char, int> bott_right_box_check;

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
				printf("%c ", board[y][x]);
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
			} // end of row loop
			printf("\n");
			row_check.clear(); // clear row_check after each row is done
		}

		printf("loop that checks col\n");
		for (int x = 0; x < 9; x++)
		{ // needs to go x (row pos) and go down the y col
			for (int y = 0; y < 9; y++)
			{
				printf("%c ", board[y][x]);
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
			} // end of row loop
			printf("\n");
			col_check.clear(); // clear row_check after each row is done
		}

		printf("CHECKS SUB-Boxes\n");
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{

				printf("%c ", board[y][x]);
				if (board[y][x] != '.')
				{
					if (x <= 2)
					{
						if (y <= 2)
						{
							if (top_left_box_check[board[y][x]] == 0)
							{
								top_left_box_check[board[y][x]] = 1;
							}
							else if (top_left_box_check[board[y][x]] > 0)
							{
								printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)", y, x);
								return 0;
							}
						}
						else if (y <= 5)
						{
							if (mid_left_box_check[board[y][x]] == 0)
							{
								mid_left_box_check[board[y][x]] = 1;
							}
							else if (mid_left_box_check[board[y][x]] > 0)
							{
								printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)", y, x);
								return 0;
							}
						}
						else if (y <= 8)
						{
							if (bott_left_box_check[board[y][x]] == 0)
							{
								bott_left_box_check[board[y][x]] = 1;
							}
							else if (bott_left_box_check[board[y][x]] > 0)
							{
								printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)", y, x);
								return 0;
							}
						}
					}
					else if (x <= 5)
					{
						if (y <= 2)
						{
							if (top_mid_box_check[board[y][x]] == 0)
							{
								top_mid_box_check[board[y][x]] = 1;
							}
							else if (top_mid_box_check[board[y][x]] > 0)
							{
								printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)", y, x);
								return 0;
							}
						}
						else if (y <= 5)
						{
							if (mid_mid_box_check[board[y][x]] == 0)
							{
								mid_mid_box_check[board[y][x]] = 1;
							}
							else if (mid_mid_box_check[board[y][x]] > 0)
							{
								printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)", y, x);
								return 0;
							}
						}
						else if (y <= 8)
						{
							if (bott_mid_box_check[board[y][x]] == 0)
							{
								bott_mid_box_check[board[y][x]] = 1;
							}
							else if (bott_mid_box_check[board[y][x]] > 0)
							{
								printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)", y, x);
								return 0;
							}
						}
					}
					else if (x <= 8)
					{

						if (y <= 2)
						{
							if (top_right_box_check[board[y][x]] == 0)
							{
								top_right_box_check[board[y][x]] = 1;
							}
							else if (top_right_box_check[board[y][x]] > 0)
							{
								printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)", y, x);
								return 0;
							}
						}
						else if (y <= 5)
						{
							if (mid_right_box_check[board[y][x]] == 0)
							{
								mid_right_box_check[board[y][x]] = 1;
							}
							else if (mid_right_box_check[board[y][x]] > 0)
							{
								printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)", y, x);
								return 0;
							}
						}
						else if (y <= 8)
						{
							if (bott_right_box_check[board[y][x]] == 0)
							{
								bott_right_box_check[board[y][x]] = 1;
							}
							else if (bott_right_box_check[board[y][x]] > 0)
							{
								printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)", y, x);
								return 0;
							}
						}
					}
				}
			}
			printf("\n");
		}
		// placeholder for now until code is done
		return 1;
	}
};