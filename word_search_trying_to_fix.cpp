class Solution
{
public:
	bool exist(vector<vector<char>> &board, string word)
	{
		// have it go through each possible neighbor to see if word can be done
		std::cout << word[0] << " " << std::endl;
		printf("print out board for debug\n");
		for (int y = 0; y < board.size(); y++)
		{
			for (int x = 0; x < board[y].size(); x++)
			{
				printf("%c ", board[y][x]);
			}
			printf("\n");
		}
		int x_save_space = 0;
		int y_save_space = 0;

		// debug testing map,pair
		map<pair<int, int>, int> prev_used;
		//         prev_used.insert({{2,9},1});
		//         printf("prev_used key of 2,9 = %i\n",prev_used[{2,9}]);
		//         prev_used.clear();
		//         printf("after clear\n");

		//         printf("prev_used key of 2,9 = %i\n",prev_used[{2,9}]);

		// prev_used.insert({{2,9},1});//need to test how to change value with this line if it works
		// insert doesn't work since it'll just return the previous value insteead of changing it
		// if key-value is already in the map
		// printf("prev_used key of 2,9 = %i\n",prev_used[{2,9}]);

		// what if made a key value already for each pair
		// so just need to access it each time instead of insert which doesn't work
		for (int y = 0; y < board.size(); y++)
		{
			for (int x = 0; x < board[y].size(); x++)
			{
				prev_used.insert({{y, x}, 0});
			}
		}
		// prev_used[{1,2}] = 1;

		printf("map key , value\n");
		for (int y = 0; y < board.size(); y++)
		{
			for (int x = 0; x < board[y].size(); x++)
			{
				printf(" (%i,%i),%i ", y, x, prev_used[{y, x}]);
			}
			printf("\n");
		}
		int save_mult_opts_y;
		int save_mult_opts_x;
		vector<pair<int, int>> mult_option_spaces; // keep track of {y,x} with mult_options
		vector<int> word_index_for_mult_option;	   // keeps track of word_index for mult_options vector
		int word_index = 0;
		int found_first_letter = 0;
		int valid_word = 0;
		printf("going through board to \n");
		for (int y = 0; y < board.size(); y++)
		{
			for (int x = 0; x < board[y].size(); x++)
			{
				if (board[y][x] == word[0])
				{ // if it finds the first letter in the word sequence
					mult_option_spaces.clear();
					mult_option_spaces.shrink_to_fit();
					word_index_for_mult_option.clear();
					word_index_for_mult_option.shrink_to_fit();

					printf("Found first letter\n");
					printf("loc = %i,%i\n", y, x);
					y_save_space = y;
					x_save_space = x;

					// set y x to prev_used
					prev_used[{y, x}] = 1;

					found_first_letter = 1;
					word_index = 1;
					valid_word = 1;
					if (word.size() == 1)
					{
						// which means there's only one letter
						return 1;
					}
					while (valid_word == 1)
					{ // meaning while ongoing word is valid keep going if not go back to
					  // x_save_space and y_save_space

						if (x + 1 < board[y].size()) // R
						{
							if (board[y][x + 1] == word[word_index] &&
								prev_used[{y, x + 1}] == 0)
							{

								if (word_index == word.size() - 1)
								{ // meaning at last part of the word
									return 1;
								}
								// for these if there is another option simply add this space to vector
								// mult_options
								// this is for the space before going to the neighbor in above if statemet
								// is the one added
								if (x - 1 >= 0)
								{
									if (board[y][x - 1] == word[word_index] &&
										prev_used[{y, x - 1}] == 0)
									{
										mult_option_spaces.push_back({y, x - 1});
										word_index_for_mult_option.push_back(word_index);
									}
								}

								if (y + 1 < board.size())
								{
									if (board[y + 1][x] == word[word_index] && prev_used[{y + 1, x}] == 0)
									{
										mult_option_spaces.push_back({y + 1, x});
										word_index_for_mult_option.push_back(word_index);
									}
								}
								if (y - 1 >= 0)
								{
									if (board[y - 1][x] == word[word_index] &&
										prev_used[{y - 1, x}] == 0)
									{
										mult_option_spaces.push_back({y - 1, x});
										word_index_for_mult_option.push_back(word_index);
									}
								}

								// y stays the same
								x += 1;

								// put into prev_used;
								prev_used[{y, x}] = 1;
								printf("went to neighbor = (%i,%i)\n", y, x);
								word_index += 1;
								continue; // to avoid going into the other if statements below
							}			  // end of y+1
						}
						if (x - 1 >= 0) // L
						{
							if (board[y][x - 1] == word[word_index] &&
								prev_used[{y, x - 1}] == 0)
							{
								if (word_index == word.size() - 1)
								{ // meaning at last part of the word
									return 1;
								}

								// for these if there is another option simply add this space to vector
								// mult_options
								// this is for the space before going to the neighbor in above if statemet
								// is the one added
								if (x + 1 < board[y].size())
								{
									if (board[y][x + 1] == word[word_index] &&
										prev_used[{y, x + 1}] == 0)
									{
										mult_option_spaces.push_back({y, x + 1});
										word_index_for_mult_option.push_back(word_index);
									}
								}
								if (y + 1 < board.size())
								{
									if (board[y + 1][x] == word[word_index] && prev_used[{y + 1, x}] == 0)
									{
										mult_option_spaces.push_back({y + 1, x});
										word_index_for_mult_option.push_back(word_index);
									}
								}
								if (y - 1 >= 0)
								{
									if (board[y - 1][x] == word[word_index] &&
										prev_used[{y - 1, x}] == 0)
									{
										mult_option_spaces.push_back({y - 1, x});
										word_index_for_mult_option.push_back(word_index);
									}
								}

								// y stays the same
								x -= 1;
								// put into prev_used;
								prev_used[{y, x}] = 1;
								printf("current_neighbor = (%i,%i)\n", y, x);
								word_index += 1;
								continue; // to avoid going into the other if statements below
							}
						}
						if (y + 1 < board.size()) // D
						{
							if (board[y + 1][x] == word[word_index] && prev_used[{y + 1, x}] == 0)
							{
								if (word_index == word.size() - 1)
								{ // meaning at last part of the word
									return 1;
								}
								// for these if there is another option simply add this space to vector
								// mult_options
								// this is for the space before going to the neighbor in above if statemet
								// is the one added
								if (x - 1 >= 0)
								{
									if (board[y][x - 1] == word[word_index] &&
										prev_used[{y, x - 1}] == 0)
									{
										mult_option_spaces.push_back({y, x - 1});
										word_index_for_mult_option.push_back(word_index);
									}
								}
								if (x + 1 < board[y].size())
								{
									if (board[y][x + 1] == word[word_index] &&
										prev_used[{y, x + 1}] == 0)
									{
										mult_option_spaces.push_back({y, x + 1});
										word_index_for_mult_option.push_back(word_index);
									}
								}
								if (y - 1 >= 0)
								{
									if (board[y - 1][x] == word[word_index] &&
										prev_used[{y - 1, x}] == 0)
									{
										mult_option_spaces.push_back({y - 1, x});
										word_index_for_mult_option.push_back(word_index);
									}
								}
								y += 1;
								// x stays the same
								// put into prev_used;
								prev_used[{y, x}] = 1;
								printf("current_neighbor = (%i,%i)\n", y, x);
								word_index += 1;
								continue; // to avoid going into the other if statements below
							}
						}

						if (y - 1 >= 0) // U
						{
							if (board[y - 1][x] == word[word_index] &&
								prev_used[{y - 1, x}] == 0)
							{
								if (word_index == word.size() - 1)
								{ // meaning at last part of the word
									return 1;
								}
								// for these if there is another option simply add this space to vector
								// mult_options
								// this is for the space before going to the neighbor in above if statemet
								// is the one added
								if (x - 1 >= 0)
								{
									if (board[y][x - 1] == word[word_index] &&
										prev_used[{y, x - 1}] == 0)
									{
										mult_option_spaces.push_back({y, x - 1});
										word_index_for_mult_option.push_back(word_index);
									}
								}
								if (x + 1 < board[y].size())
								{
									if (board[y][x + 1] == word[word_index] &&
										prev_used[{y, x + 1}] == 0)
									{
										mult_option_spaces.push_back({y, x + 1});
										word_index_for_mult_option.push_back(word_index);
									}
								}
								if (y + 1 < board.size())
								{
									if (board[y + 1][x] == word[word_index] && prev_used[{y + 1, x}] == 0)
									{
										mult_option_spaces.push_back({y + 1, x});
										word_index_for_mult_option.push_back(word_index);
									}
								}
								y -= 1;
								// x stays the same
								// put into prev_used;
								prev_used[{y, x}] = 1;
								printf("current_neighbor = (%i,%i)\n", y, x);
								word_index += 1;
								continue; // to avoid going into the other if statements below
							}
						}
						// have it go back to original starting point to go
						if (mult_option_spaces.size() > 0)
						{
							// printf("in do_multiple_times if\n");
							printf("in mult_options.size()>0\n");
							// set y and x to

							y = mult_option_spaces.back().first;
							x = mult_option_spaces.back().second;

							mult_option_spaces.pop_back();
							mult_option_spaces.shrink_to_fit();

							word_index = word_index_for_mult_option.back();
							word_index_for_mult_option.pop_back();

							// of abcd being true when it should be false by resetting to first neighbor

							// IMPORTANT NEED TO FIND A WAY TO change the prev_used map because
							// some of  the neighbors already went to are needed for the viable word search

							// map clear loop (set all values to 0)
							// this may or may not work
							// DELETE THIS LOOP IF IT DOESN"T WORK
							for (int y = 0; y < board.size(); y++)
							{
								for (int x = 0; x < board[y].size(); x++)
								{
									prev_used[{y, x}] = 0;
								}
							}
							continue;
							// this way should go back and do available neighbor not done yet
							// due to only doing each available neighbor once due to map
						}

						// //have it go back to original starting point to go
						// if (do_multiple_times > 0){
						//     printf("in do_multiple_times if\n");
						//     x = x_save_space;
						//     y = y_save_space;
						//     do_multiple_times -= 1;
						//     word_index = 1; //forgot to put this here which should fix bug
						//     //of abcd being true when it should be false by resetting to first neighbor
						//     continue;
						//     //this way should go back and do available neighbor not done yet
						//     //due to only doing each available neighbor once due to map
						// }
						// else{//probably is this else statement because it could be y-1 >=0 and still find no
						// other neighbors

						// now that I think about it it should just auto go here since every other if
						// there is a neighbor should be continued already

						// meaning none of the adjacent match to next letter in word
						// reset all variables and get out of while loop
						printf("did not find the word\n");
						word_index = 0;
						// backtrack to beginning x and y spot
						x = x_save_space;
						y = y_save_space;

						valid_word = 0;

						// map clear loop (set all values to 0)
						for (int y = 0; y < board.size(); y++)
						{
							for (int x = 0; x < board[y].size(); x++)
							{
								prev_used[{y, x}] = 0;
							}
						} // end of map clear loop

						//}
					} // end of while valid word loop
				}	  // end of if board[x][y] == word[0] matching letter to first letter in word

			} // end of for loop x part
			printf("\n");
		} // end of outer for loop y part

		return 0; // placeholder
				  // also this might be good because if doesn't return0
	}
};
// I THINK I FOUND A SOLN to prob where why not just go to
// other mult option instead of going back to y,x with multiple options just go to
// a different option
// need to retool prev_used to not have other mult_option on prev_used if multiple is on there
