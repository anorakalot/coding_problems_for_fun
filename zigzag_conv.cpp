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

		// should find mathematical way to get num of columns
		// y      x
		char zigzag_conv[numRows][numRows];

		// first convert to 2d array first not worrying about zigzag pattern
		for (int y = 0; y < numRows; y++)
		{
			for (int x = 0; x < numRows; x++)
			{
			}
		}

		return "0";

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
