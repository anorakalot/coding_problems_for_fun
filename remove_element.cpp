class Solution
{
public:
	int removeElement(vector<int> &nums, int val)
	{
        if (nums.size() ==0){
            return 0;
        }
		int first_pointer = 0;
		int last_pointer = nums.size() - 1;
		int swap;
		int return_value = nums.size();
		// keep pointers of each
		printf("last_pointer = %i\n", last_pointer);
        printf("return_value = %i\n",return_value);
		// debug loop
        printf("printing given vector\n");
		for (int x = 0; x < nums.size(); x++)
		{
			printf("%i ",  nums[x]);
		}
        printf("\n");
        //move last_pointer down one incase val is there 
        printf("nums[last_pointer] == %i\n",nums[last_pointer]);
        while(nums[last_pointer]==val){
            //if (nums[last_pointer] == val){
            printf("inside while nums[last_pointer]==val\n");
            last_pointer -=1;
            return_value-=1;//still need to do this since still need to shorten if seeing a val
            printf("last_pointer now equals =%i \n",last_pointer);
            printf("return_value now equals =%i\n",return_value);
            //continue;
            //}
            if (last_pointer <0){
            return 0;
            }
        }

		// end of debug loop
		//for (int x = 0; x < nums.size(); x++)
		for(int x=0; x < return_value;x++)
        {
			if (nums[x] == val)
			{ // find val of
                
				printf("found val at %i switching now\n", x);
				// nums[x] = swap;
				swap = nums[x];
				nums[x] = nums[last_pointer];
				nums[last_pointer] = swap;
				// subtract return value by 1 since size is -=1 due to finding unwanted val
				return_value -= 1;
				// move last_pointer down by 1 so as to not switch the previous
				// bad value
				last_pointer -= 1;
                printf("last_pointer now equals =%i \n",last_pointer);
                printf("return_value now equals =%i\n",return_value);
				printf("debug of array after swap\n");
				for (int x = 0; x < nums.size(); x++)
				{
					printf("%i ", nums[x]);
				}
                printf("\n");
                while(nums[last_pointer]==val){
                    last_pointer -=1;
                    return_value -=1;
                }
			}
		}
        if (nums[last_pointer] == val){
            return_value-=1;
        }
        
		return return_value;
	}
};