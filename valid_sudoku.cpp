class Solution
{
public:
	bool isValidSudoku(vector<vector<char>> &board)
	{
		// vector<char> row {'1','2'};

		// for(int i = 0; i < 9;i++ ){
		// printf("board[i][i]: %c\n" ,board[i][i]);
		// }
		// map<char,int> row_check;
		// map<char,int> col_check;

		// map <char,int> top_left_box_check;
		// map <char,int> top_mid_box_check;
		// map <char,int> top_right_box_check;

		// map <char,int> mid_left_box_check;
		// map <char,int> mid_mid_box_check;
		// map <char,int> mid_right_box_check;

		// map <char,int> bott_left_box_check;
		// map <char,int> bott_mid_box_check;
		// map <char,int> bott_right_box_check;

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

		vector<map<int, int>> row_check(9);
		vector<map<int, int>> col_check(9);

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				if (board[y][x] == '.')
				{
					continue;
				}
				// doing row_check[x] makes it so it accesses
				// at row w/ the x value
				if (row_check[y][board[y][x]] == 0)
				{
					row_check[y][board[y][x]] = 1;
				}
				else if (row_check[y][board[y][x]] > 0)
				{
					// printf("x_val =%i\n",x);
					printf("FOUND ROW ERROR AT %i,%i\n", y, x);
					return 0;
				}
				// for this one it checks for the certain y value
				if (col_check[x][board[y][x]] == 0)
				{
					col_check[x][board[y][x]] = 1;
				}
				else if (col_check[x][board[y][x]])
				{
					// printf("y_val =%i\n",y);
					printf("FOUND COL ERROR AT %i,%i\n", y, x);
					return 0;
				}
			}
		}
		// printf("loop that checks row\n");
		// for (int y = 0; y < 9; y++){
		//     for (int x = 0; x < 9; x++){
		//         printf("%c ",board[y][x]);
		//         if (board[y][x] != '.' && row_check[board[y][x]] == 0){//meaning it hasn't been seen before
		//             row_check[board[y][x]] =1;
		//             //set unique val to 1;
		//         }
		//         else if (board[y][x] != '.' && row_check[board[y][x]]> 0){//meaning seen this char before on this row
		//             printf("(ROW_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)",y,x);
		//             return 0;
		//         }
		//     }//end of row loop
		//     printf("\n");
		//     row_check.clear();//clear row_check after each row is done
		// }

		// printf("loop that checks col\n");
		// for (int x = 0; x < 9; x++){//needs to go x (row pos) and go down the y col
		//     for (int y = 0; y < 9; y++){
		//         printf("%c ",board[y][x]);
		//         if (board[y][x] != '.' && col_check[board[y][x]] == 0){//meaning it hasn't been seen before
		//             col_check[board[y][x]] =1;
		//             //set unique val to 1;
		//         }
		//         else if (board[y][x] != '.' && col_check[board[y][x]]> 0){//meaning seen this char before on this row
		//             printf("(COL_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)",y,x);
		//             return 0;
		//         }
		//     }//end of row loop
		//     printf("\n");
		//     col_check.clear();//clear row_check after each row is done
		// }

		// printf("CHECKS SUB-Boxes\n");
		// for (int y = 0; y < 9; y++){
		//     for (int x = 0; x < 9; x++){

		//         printf("%c " ,board[y][x]);
		//         if (board[y][x] != '.'){
		//             if (x <= 2){
		//                 if (y <=2){
		//                     if (top_left_box_check[board[y][x]] ==0){
		//                         top_left_box_check[board[y][x]] = 1;
		//                     }
		//                     else if (top_left_box_check[board[y][x]] >0){
		//                         printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)",y,x);
		//                         return 0;
		//                     }

		//                 }
		//                 else if (y <=5){
		//                     if (mid_left_box_check[board[y][x]] ==0){
		//                         mid_left_box_check[board[y][x]] = 1;
		//                     }
		//                     else if (mid_left_box_check[board[y][x]] >0){
		//                         printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)",y,x);
		//                         return 0;
		//                     }

		//                 }
		//                 else if (y <= 8){
		//                     if (bott_left_box_check[board[y][x]] ==0){
		//                         bott_left_box_check[board[y][x]] = 1;
		//                     }
		//                     else if (bott_left_box_check[board[y][x]] >0){
		//                         printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)",y,x);
		//                         return 0;
		//                     }
		//                 }

		//             }
		//             else if (x <=5){
		//                 if (y <=2){
		//                     if (top_mid_box_check[board[y][x]] ==0){
		//                         top_mid_box_check[board[y][x]] = 1;
		//                     }
		//                     else if (top_mid_box_check[board[y][x]] >0){
		//                         printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)",y,x);
		//                         return 0;
		//                     }
		//                 }
		//                 else if (y <=5){
		//                     if (mid_mid_box_check[board[y][x]] ==0){
		//                         mid_mid_box_check[board[y][x]] = 1;
		//                     }
		//                     else if (mid_mid_box_check[board[y][x]] >0){
		//                         printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)",y,x);
		//                         return 0;
		//                     }
		//                 }
		//                 else if (y <= 8){
		//                     if (bott_mid_box_check[board[y][x]] ==0){
		//                         bott_mid_box_check[board[y][x]] = 1;
		//                     }
		//                     else if (bott_mid_box_check[board[y][x]] >0){
		//                         printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)",y,x);
		//                         return 0;
		//                     }
		//                 }

		//             }
		//             else if (x<=8){

		//                 if (y <=2){
		//                     if (top_right_box_check[board[y][x]] ==0){
		//                         top_right_box_check[board[y][x]] = 1;
		//                     }
		//                     else if (top_right_box_check[board[y][x]] >0){
		//                         printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)",y,x);
		//                         return 0;
		//                     }
		//                 }
		//                 else if (y <=5){
		//                     if (mid_right_box_check[board[y][x]] ==0){
		//                         mid_right_box_check[board[y][x]] = 1;
		//                     }
		//                     else if (mid_right_box_check[board[y][x]] >0){
		//                         printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)",y,x);
		//                         return 0;
		//                     }
		//                 }
		//                 else if (y <= 8){
		//                     if (bott_right_box_check[board[y][x]] ==0){
		//                         bott_right_box_check[board[y][x]] = 1;
		//                     }
		//                     else if (bott_right_box_check[board[y][x]] >0){
		//                         printf("(SUBBOX_CHECK) DUPLICATE FOUND IN COORD (Y,X) (%i,%i)",y,x);
		//                         return 0;
		//                     }
		//                 }

		//             }
		//         }
		//     }
		//     printf("\n");
		// }

		// if all code has run and no error is brought up this
		return 1;
	}
};