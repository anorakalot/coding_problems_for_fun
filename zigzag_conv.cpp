class Solution
{
public:
	string convert(string s, int numRows)
	{
		printf("original string\n");
		std::cout << s << std::endl;
		int s_size = s.size();
		printf("s_size == %i\n", s_size);
		printf("going to decrease s_size by 1 due to index error getting col error");
		s_size -= 1;
		printf("s_size == %i\n", s_size);
		printf("numRows == %i\n", numRows);

		// edge case of s_size only being 1
		if (s_size == 1)
		{
			return s;
		}
		// vector<vector<char>> zigzag_conv;

		// int num_in_between = numrows/2;
		// doesn't work for numrows 5 should be 3 but comes out to 2
		int numColumns = 1; // since first increment when going to 2//(also always at least length 1)
		int num_position = 0;
		int direction = 0;

		int s_index = 0;

		// all of this to find numColumns
		printf("starting_index = %c\n", s[s_index]);
		while (s_size > 0)
		{
			// meaning it goes down
			if (direction == 0) // is set up to start dir as 0
			{
				if (num_position < (numRows - 1))
				{
					num_position += 1; // move up y
					s_size -= 1;	   // used up a letter
					s_index += 1;
					printf("going down current index = %c\n", s[s_index]);
					printf("s_size = %i\n", s_size);
				}
				else
				{
					printf("changing direction to up\n");
					direction = 1;
				}
			}
			// going up zigzag means adding more columns
			if (direction == 1)
			{
				if (num_position > 0)
				{
					num_position -= 1;
					numColumns += 1;
					s_size -= 1;
					s_index += 1;
					printf("going up (meaning col +=1) current index = %c\n", s[s_index]);
					printf("s_size = %i\n", s_size);
				}
				else
				{
					printf("changing direction to down\n");
					direction = 0;
				}
			}

		} // end of while loop

		printf("numColumns == %i\n", numColumns);
		printf("\n\n");

		// should find mathematical way to get num of columns
		// y      x
		char zigzag_conv[numRows][numColumns];

		// put debug print loop here
		printf("LOOP that adds space values default to zigzag_conv\n");
		for (int y = 0; y <= numRows - 1; y++)
		{
			for (int x = 0; x <= numColumns - 1; x++)
			{
				printf("y == %i , x == %i\n", y, x);
				printf("testing\n");
				zigzag_conv[y][x] = '0';
				printf("%c \n", zigzag_conv[y][x]);
			}
			printf("\n");
		}

		string return_val;
		int y_val = 0;
		int x_val = 0;

		// could just do the same while loop as above but this time
		// make it so that it adds numbers

		// first reset s_size,direction,num_position,s_index var
		s_size = s.size() - 1;
		num_position = 0;
		direction = 0;
		s_index = 0;

		printf("FILLING starting_index = %c\n", s[s_index]);
		// add first letter to zigzag_conv
		zigzag_conv[y_val][x_val] = s[s_index];
		printf("added starting index to zigzag_conv at y_val = %i , x_val = %i\n", y_val, x_val);
		printf("zigzag_conv[y_val][x_val] = %c\n", zigzag_conv[y_val][x_val]);
		while (s_size > 0)
		{
			// meaning it goes down
			if (direction == 0) // is set up to start dir as 0
			{
				if (num_position < (numRows - 1))
				{
					num_position += 1; // move up y
					s_size -= 1;	   // used up a letter
					s_index += 1;
					// add 1 to y val
					y_val += 1;
					// keep x the same
					// add to zigzag_conv;
					zigzag_conv[y_val][x_val] = s[s_index];
					printf("going down current index = %c\n", s[s_index]);
					printf("added current index to zigzag_conv at y_val = %i , x_val = %i\n", y_val, x_val);
					printf("zigzag_conv[y_val][x_val] = %c\n", zigzag_conv[y_val][x_val]);
					printf("s_size = %i\n", s_size);
				}
				else
				{
					printf("changing direction to up\n");
					direction = 1;
				}
			}
			// going up zigzag means adding more columns
			if (direction == 1)
			{
				if (num_position > 0)
				{
					num_position -= 1;
					// numColumns +=1;//THIS WAS THE LINE CAUSDING THE ISSUE
					// SINCE THIS IS NOT THE FINDING COLUMNS LOOP THAT ALREADY HAPPENED IN THE PREV ONE
					s_size -= 1;
					s_index += 1;
					// y_val goes up (meaning decrease in 2d array)
					y_val -= 1;
					// increase x_val
					x_val += 1;
					zigzag_conv[y_val][x_val] = s[s_index];
					printf("going up (meaning col +=1) current index = %c\n", s[s_index]);
					printf("added current index to zigzag_conv at y_val = %i , x_val = %i\n", y_val, x_val);
					printf("zigzag_conv[y_val][x_val] = %c\n", zigzag_conv[y_val][x_val]);
					printf("s_size = %i\n", s_size);
				}
				else
				{
					printf("changing direction to down\n");
					direction = 0;
				}
			}

		} // end of FILLING zigzag_conv while loop

		// put debug print loop here
		printf("DEBUG LOOP\n");
		for (int y = 0; y <= numRows - 1; y++)
		{
			for (int x = 0; x <= numColumns - 1; x++)
			{
				printf("y == %i , x == %i\n", y, x);
				printf("testing\n");
				printf("%c \n", zigzag_conv[y][x]);
			}
			printf("\n");
		}
		printf("\n\n");
		printf("print out 2d array loop and add to return_val loop\n");
		for (int y = 0; y <= numRows - 1; y++)
		{
			for (int x = 0; x <= numColumns - 1; x++)
			{
				printf("%c ", zigzag_conv[y][x]);
				if (zigzag_conv[y][x] != '0')
				{
					return_val.push_back(zigzag_conv[y][x]);
				}
			}
			printf("\n");
		}

		std::cout << "return_val==" << return_val << std::endl;
		// actually ending might be a double for loop to go through and only add the values in a linear fashion after makign a zigzag pattern
		// return "0";//placeholder
		return return_val;

	} // end of convert class function
};
// //all of this to find numColumns
// while (s_size <= 0){
//     // if (direction == 0)
//     // {

//     //     if (num_position)
//     // }
//     if ((direction == 0) && (num_position<(numRows-1) )){
//         num_position += 1;//move up y
//         s_size -=1;//used up a letter
//     }
//     else{
//         direction = 1;
//         //after this else should go straight to next if statement
//         //continue;
//     }
//     if ((direction ==1) && (num_position >(0))){
//         num_position -=1;
//         numColumns +=1;
//         s_size -=1;
//     }
//     //I SEE THE PROBLEM if it goes here it never goes into the
//     //second if statement
//     else if {
//         direction = 0;
//     }

// }
