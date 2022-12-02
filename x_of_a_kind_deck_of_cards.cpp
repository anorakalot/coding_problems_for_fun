class Solution
{
public:
	map<int, int> num_of_times_card;
	int partition_num = 0;
	int check_num_of_times_mod = 0;
	int check_partition_mod = 0;
	// bool two_rem_bool = 0;
	// bool three_rem_bool=0;
	int modulo_val;
	map<int, int>::iterator it;
	bool hasGroupsSizeX(vector<int> &deck)
	{
		if (deck.size() == 1)
		{
			return 0;
		}
		// setting up number of times each card num shows up
		for (int x = 0; x < deck.size(); x++)
		{
			num_of_times_card[deck[x]] += 1;
		}
		printf("number of times each card shows up\n");
		for (it = num_of_times_card.begin(); it != num_of_times_card.end(); it++)
		{
			printf("card_val = %i, num_of_times = %i\n", it->first, it->second);
		}
		printf("\n");
		partition_num = num_of_times_card[deck[0]];
		printf("partition_num == %i\n", partition_num);
		// if (partition_num %2==0){
		// }

		// for (int x = 0; x < deck.size(); x++){
		for (it = num_of_times_card.begin(); it != num_of_times_card.end(); it++)
		{
			printf("for deck[x] val of == %i num_of_times_card == %i\n", it->first, it->second);
			printf("reminder partition_val == %i\n", partition_num);
			modulo_val = it->second % partition_num;
			printf("modulo_val == %i\n", modulo_val);
			if (modulo_val != 0)
			{

				// printf("inside if statement of modulo_val != 0\n");
				// printf("num_of_times_card[deck[x]] %i modulo_div modulo_val %i == %i\n",it->second,modulo_val,it->second%modulo_val);
				// printf("partition_num %i modulo_div modulo_val %i == %i\n",partition_num,modulo_val,partition_num % modulo_val);
			}

			if (it->second != partition_num && modulo_val != 0)
			{
				check_num_of_times_mod = it->second % modulo_val;

				check_partition_mod = partition_num % modulo_val;
				printf("check_num_of_times_mod == %i, check_num_of_times_mod != 0 == %i\n", check_num_of_times_mod,
					   check_num_of_times_mod != 0);
				printf("check_partition_mod == %i, check_partition_mod != 0 == %i\n", check_partition_mod,
					   check_partition_mod != 0);
				if (check_num_of_times_mod != 0 || check_partition_mod != 0)
				{
					// printf("modulo _val %i\n",num_of_times_card[deck[x]] % partition_num);
					printf("FOUND MAP VAL NOT EQUAL TO REST OF PARTITION NUMBER\n");
					return 0;
				}
			}

			printf("\n\n");
		}
		return 1; // placeholder
	}
};
// I feel like I'm going about this problem in the wrong way.
// maybe try starting off w/ smallest map value and then see if rest of values can use smallest divisor of that.