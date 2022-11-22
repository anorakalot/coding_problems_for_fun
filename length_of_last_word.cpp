class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		int last_word_length = 0;
		int found_last_word = 0;
		for (int x = s.size() - 1; x >= 0; x--)
		{
			if (found_last_word == 0 && s[x] != ' ')
			{
				found_last_word = 1;
				last_word_length += 1;
				continue;
			}
			if (found_last_word == 1)
			{
				if (s[x] != ' ')
				{
					last_word_length += 1;
				}
				else
				{
					break;
				}
			}
		}
		return last_word_length;
	}
};