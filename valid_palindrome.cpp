class Solution
{
public:
	bool isPalindrome(string s)
	{
		int ascii;
		for (int x = 0; x < s.size(); x++)
		{
			ascii = s[x];
			if (ascii <= 90 && ascii >= 65)
			{ // if uppercase
				printf("s[x] == %c is uppercase\n", s[x]);
				printf("s[x] ascii value is ==  %i\n", ascii);
				s[x] = s[x] + 32;
			}
		}

		for (int x = 0; x < s.size(); x++)
		{
			printf("%c", s[x]);
		}
		printf("\n");
		return 0; // placeholder
	}
};