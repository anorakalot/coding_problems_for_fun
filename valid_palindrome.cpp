class Solution
{
public:
	bool isPalindrome(string s)
	{
		int ascii;
		string clone;

		for (int x = 0; x < s.size(); x++)
		{
			ascii = s[x];
			if (ascii <= 90 && ascii >= 65)
			{ // if uppercase
				// convert to lowercase
				//  printf("s[x] == %c is uppercase\n",s[x]);
				//  printf("s[x] ascii value is ==  %i\n",ascii);
				ascii += 32;
				s[x] = s[x] + 32;
			}
			if (ascii >= 97 && ascii <= 122 || ascii >= 48 && ascii <= 57)
			{
				// if number or alphabet add to clone
				clone.push_back(s[x]);
			}
		}
		// //debug clone print loop
		// printf("debug clone print loop\n");
		// for (int x = 0; x < clone.size(); x ++){
		//     printf("%c",clone[x]);
		// }
		// printf("\n");
		int first_index = 0;
		int last_index = clone.size() - 1;
		int return_val = 1;
		while (first_index < last_index)
		{
			if (clone[first_index] != clone[last_index])
			{

				return_val = 0;
				break;
			}
			first_index += 1;
			last_index -= 1;
		}
		// //comparison 2 pointers
		// for (int x=0; x < s.size(); x++){
		//     //if ()
		// }

		return return_val;
		// return 0; //placeholder
	}
};
// for (int x=0; x < s.size();x++){
//              printf("%c",s[x]);
//          }
//          printf("\n");
