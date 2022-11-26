class Solution
{
public:
	string addBinary(string a, string b)
	{
		string return_val;
		int return_val_index;
		int bit_index_a;
		int bit_index_b;

		// how about 2 bit indexes to keep track of where it should be
		// for each one that way I don't have to make both of the strings equal to
		// each other since inserting atht the beginning of a string is expensive;
		bit_index_a = a.size() - 1;
		bit_index_b = b.size() - 1;

		if (a.size() > b.size())
		{
			return_val.resize(a.size());
			return_val_index = a.size() - 1;
		}
		else
		{ // if it's equal or b is bigger just go w/ b size
			return_val.resize(b.size());
			return_val_index = b.size() - 1;
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
		int carry_over_curr = 0;

		// int bit_value = 0;
		// char bit_value_char = '0';
		char bit_value = '0';
		// int bit_a = 0;
		// int bit_b = 0;
		char bit_a = '0';
		char bit_b = '0';

		while (bit_index_a >= 0 and bit_index_b >= 0)
		{
			bit_value = 0;
			if (bit_index_a < 0)
			{ // if no longer inside range for a
				bit_a = 0;
			}
			else
			{
				bit_a = a[bit_index_a];
			}
			if (bit_index_b < 0)
			{ // if no longer inside range for a
				bit_b = 0;
			}
			else
			{
				bit_b = b[bit_index_b];
			}

			// need to take care of bitvalue
			if (bit_a == '1' && bit_b == '1')
			{
				// carry_over +=1;
				carry_over_curr += 1;
				bit_value = '0';
			}
			else if ((bit_a == '1' && bit_b == '0') || (bit_a == '0' && bit_b == '1'))
			{
				bit_value = '1';
			}
			else if (bit_a == '0' && bit_b == '0')
			{
				bit_value = '0';
			}

			if (carry_over > 0 && bit_value)
			{ // one or more
			}

			bit_index_a--;
			bit_index_b--;
		}
		// in below carry_over loop I'll have to insert at beginning of str
		//  s.insert(0,"1");
		// add while loop here for while carry_over >=1
		// keep adding 1 to front of bit_string
		return return_val;
	}
};