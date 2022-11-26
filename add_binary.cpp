class Solution
{
public:
	string addBinary(string a, string b)
	{
		// int addition_bool=1;
		// while (addition_bool ==1){
		// }
		// making one string the same size as the larger one is expensive
		string return_val;
		// int total_size;

		// int bit_index;
		int bit_index_a;
		int bit_index_b;

		// how about 2 bit indexes to keep track of where it should be
		// for each one that way I don't have to make both of the strings equal to
		// each other since inserting atht the beginning of a string is expensive;
		bit_index_a = a.size() - 1;
		bit_index_b = b.size() - 1;

		if (a.size() > b.size())
		{
			return_val.resize(a.size() + 1);
			// bit_index = a.size()-1;
			// total_size = a.size();
		}
		else
		{ // if it's equal or b is bigger just go w/ b size
			return_val.resize(b.size() + 1);
			// bit_index = b.size()-1;
		}

		printf("a_bit_string\n");
		for (int x = 0; x < a.size(); x++)
		{
			printf("%c", a[x]);
		}
		printf("\n");

		printf("b_bit_string\n");
		for (int x = 0; x < b.size(); x++)
		{
			printf("%c", b[x]);
		}
		printf("\n");

		int carry_over = 0;
		int bit_value = 0;
		while (bit_index > 0)
		{
			bit_value = 0;
			// actually below might not work since
			// for '11' and '1' you start w/ the right 1 being the same index as the last 1 in the left one
			//  if (a[bit_index] == ''){
			//      a_val = '0';
			//  }
			//  if (b[bit_index == ''){
			//      b_val = '0';
			//  }
			if (a[bit_index] == '1' && b[bit_index] == '1')
			{
				carry_over += 1;
				bit_value = 0;
			}

			bit_index--;
		}

		//

		return return_val;
	}
};