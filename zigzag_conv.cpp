class Solution
{
public:
	string convert(string s, int numRows)
	{
		printf("original string\n");
		std::cout << s << std::endl;
		int s_size = s.size();
		printf("s_size == %i", s_size);
		// vector<vector<char>> zigzag_conv;

		// int num_in_between = numrows/2;
		// doesn't work for numrows 5 should be 3 but comes out to 2
		int numColumns = 0;
		int num_position = 0;
		int direction = 0;

		while (s_size <= 0)
		{
			// if (direction == 0)
			// {

			//     if (num_position)
			// }
			if (direction == 0 && num_position < (numRows))
			{
				num_position += 1; // move up y
				s_size -= 1;	   // used up a letter
			}
			else
			{
			}
		}

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