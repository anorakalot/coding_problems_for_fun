class Solution
{
public:
	void sortColors(vector<int> &nums)
	{
		// low == 0 and high == nums.size()-1
		// i think for starting value
		printf("nums.size()-1 == %i,nums[nums.size()-1] == %i\n", nums.size() - 1,
			   nums[nums.size() - 1]);

		quicksort(nums, 0, nums.size() - 1);
	}

	void quicksort(vector<int> &nums, int low, int high)
	{

		// might need to add explicit base case
		if (low < high)
		{
			int pivot = partition(nums, low, high);
			printf("returned_pivot_val == %i\n", pivot);
			// recursion calling
			quicksort(nums, low, (pivot - 1));
			// low to right before pivot
			quicksort(nums, (pivot + 1), high);
			// right after pivot to high
		}
		// else{//got rid of soo after recursion calls are done they just return
		// return; // made quicksort func void
		// actually don't need a return for a void function

		// return //low;// don't know if this is needed
		//}
	}
	int partition(vector<int> &nums, int low, int high)
	{
		printf("\n\n");
		printf("low = %i, high = %i\n", low, high);
		printf("nums before partition\n");
		// for (int x = 0; x <= high; x++)
		for (int x = low; x <= high; x++) // this way easier to see what is being done in
										  // particular partition
		{
			printf("%i ", nums[x]);
		}
		printf("\n");
		// int i = low - 1; // so -1 if low was 0
		//  which it should be for first partition
		int i = low;
		i = i - 1;
		// i -=1;
		// stops here w/ new runtime error if i= low-1 or i-=1 2 line approach

		// gonna try adding a int bool variable to keep i at low value once
		// and skip i+= 1 once
		// int low_once = 0;
		printf("i starting_val = %i\n", i); //,nums[i] = %i",i,nums[i]);
											// foudn the error it's due to nums[i] above and -1 not being a valid index
		//  int j;//don't need this if I have x for loop value
		int pivot = high; // just make it the right most index value
						  // for simplicity
		printf("pivot == %i\n", pivot);
		printf("pivot[nums] == %i\n", nums[pivot]);
		int swap = 0;
		for (int x = low; x <= high; x++)
		{
			printf("x == %i\n", x);
			printf("nums[x] == %i\n", nums[x]);
			// j=x;
			if (nums[x] <= nums[pivot])
			{
				printf("nums[x] <= nums[pivot]\n");
				// printf("swapping\n");
				// printf("nums[x] == %i\n", nums[x]);
				printf("x == %i, nums[x] == %i\n", x, nums[x]);
				printf("pivot = %i nums[pivot] == %i\n", pivot, nums[pivot]);
				// if (i != low){}
				//  if (low_once == 0){//first time i
				//  //does not need to get incrememnted if start at i = low
				//  low_once = 1;
				//  }
				//  else{
				//  i += 1; // increment i by 1
				//  }
				i += 1; // increment i by 1
				printf("i after increment == %i\n", i);
				if (i == x)
				{
					// continue;
					// if i is equal to x index
					// then don't do anything
				}
				else if (x > i)
				{
					// printf("nums[i] (after +=1) == %i\n", nums[i]);
					// printf("i == %i\n",i);
					printf("act. swapping\n");
					printf("i == %i, nums[i]== %i\n", i, nums[i]);
					printf("x == %i, nums[x] == %i\n", x, nums[x]);
					// printf("\n");
					//  now swap i and j
					swap = nums[x];
					nums[x] = nums[i];
					nums[i] = swap;
				}
			} // if (nums[x] <= pivot)
			else
			{
				// printf("not in nums[x] < nums[pivot]\n");
				printf("nums[x] > pivot\n");
			}
		}
		// once at the end swap i+1 and pivot index
		// then we return i+1 as where the pivot val is and this is where the recursion
		// quicksort will then call them pivot -1 for lower and pivot +1 for higher

		// printf("Swapping nums[pivot] and nums[i+1]\n");
		// printf("i+1 = %i && nums[i+1] == %i\n",i+1,nums[i+1]);
		// printf("pivot = %i && nums[pivot] == %i\n",pivot,nums[pivot]);
		// swap = nums[pivot];
		// nums[pivot] = nums[i + 1];
		// nums[i + 1] = swap;

		//(Comment)won't need above swap if x goes to high and does the last i+1 swap inside
		// the loop

		//(Ignore this I think)reason see change is due to this swap here with pivot and i+1

		printf("nums after partition\n");
		// for (int x = 0; x <= high; x++)
		for (int x = low; x <= high; x++) // this way easier to see what is being done in
										  //  this particular partition
		{
			printf("%i ", nums[x]);
		}
		printf("\n");

		// printf("return_val of i+1 = %i\n",i+1);
		// printf("nums[i+1] == %i\n",nums[i+1]);
		// return (i + 1);

		//(Comment)since last swap is already handled inside the loop
		// should just need to return i
		return i;
	}
};
// debugging help look at before and after partition loops
// too see where error starts before going into detail

// issue I see is that returned pivot val at the end is 9 when it shouldn't ever
// go past 5 which is the last index for the array size for the test array 202110

// I FIXED THE ERROR IT WAS JUST THE MAIN PARTITION LOOP
// WAS SET TO O TO HIGH AND NOT LOW TO HIGH